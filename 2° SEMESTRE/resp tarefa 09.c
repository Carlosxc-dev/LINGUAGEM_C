#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char cep[9];
    char uf[3];
    char cidade[31];
    char logradouro[61];
    struct no *esq;
    struct no *dir;
} noCEP;

noCEP *raiz = NULL;
int quant; // conta ate x elem

// insere elem na arvore
void insereNo(FILE *arq)
{
    noCEP *atual = raiz;
    noCEP *ant = NULL;
    noCEP *novo = (noCEP *)malloc(sizeof(noCEP));
    char linha[200];
    char *substring;

    fgets(linha, 200, arq);
    substring = strtok(linha, "\t"); // quebra linha no arquivo
    // pega info cep
    if (substring != NULL)
    {
        strcpy(novo->cep, substring);
    }
    // pega informacao da uf
    substring = strtok(NULL, "\t");
    if (substring != NULL)
    {
        strcpy(novo->uf, substring);
    }
    // pega informacao da cidade
    substring = strtok(NULL, "\t");
    if (substring != NULL)
    {
        strcpy(novo->cidade, substring);
    }
    // pega informacao da endereco
    substring = strtok(NULL, "\t");
    if (substring != NULL)
    {
        strcpy(novo->logradouro, substring);
    }
    // sem filhos = null
    novo->esq = NULL;
    novo->dir = NULL;

    // percorre a arvore para achar a posicao para inserir o novo
    while ((atual != NULL) && (strcmp(novo->cep, atual->cep) < 0))
    {
        ant = atual;
        if (strcmp(novo->cep, atual->cep) < 0)
        {
            atual = atual->esq;
        }
        else
        {
            atual = atual->dir;
        }
    }
    if (ant == NULL)//define raiz da arvore 
    {
        raiz = novo;
    }
    else
    {
        if (atual == NULL)//procura filho para inserir 
        {
            if (strcmp(novo->cep, ant->cep) < 0)
            {
                ant->esq = novo;
            }
            else
            {
                ant->dir = novo;
            }
        }
    }
}
// imprime os elementos
void imprimeNoCEP(noCEP *n)
{
    printf("CEP = %s\n", n->cep);
    printf("UF = %s\n", n->uf);
    printf("cidade = %s\n", n->cidade);
    printf("endereco = %s\n", n->logradouro);
}
// imprime em pre-ordem
void imprimePreOrdem(noCEP *n, int opQuant)
{
    if ((n != NULL) && (quant < opQuant))
    {
        imprimeNoCEP(n);
        quant++;
        imprimePreOrdem(n->esq, opQuant);
        imprimePreOrdem(n->dir, opQuant);
    }
}
// imprime em ordem
void imprimeOrdem(noCEP *n, int opQuant)
{
    if ((n != NULL) && (quant < opQuant))
    {
        imprimeOrdem(n->esq, opQuant);
        imprimeNoCEP(n);
        quant++;
        imprimeOrdem(n->dir, opQuant);
    }
}
// imprime em pos ordem
void imprimePosOrdem(noCEP *n, int opQuant)
{
    if ((n != NULL) && (quant < opQuant))
    {
        imprimePosOrdem(n->esq, opQuant);
        imprimePosOrdem(n->dir, opQuant);
        imprimeNoCEP(n);
        quant++;
    }
}
// imprime a busca
void buscaCEPArvore(noCEP *atual, char cepProcurado[9])
{
    // busca o cep na arvore
    while ((atual != NULL) && (strcmp(cepProcurado, atual->cep) != 0))
    {
        if (strcmp(cepProcurado, atual->cep) < 0)
        {
            atual = atual->esq;
        }
        else
        {
            atual = atual->dir;
        }
    }
    // quando encontrar o cep
    if (strcmp(cepProcurado, atual->cep) == 0)
    {
        printf("CEP ENCONTRADO: \n\n");
        imprimeNoCEP(atual);
    }
    else
    {
        printf("cep nao encontrado\n");
    }
}
// destroi a arvore
void destroiArvore(noCEP *atual)
{
    if (atual != NULL)
    {
        destroiArvore(atual->esq);
        destroiArvore(atual->dir);
        free(atual);
    }
}
// escolha quantidade de enderecos para imprimir
int escolhaQuant(){
    int opQuant = 0;

    printf("Qual a quantidade de cep sera imprimido: ");
    scanf("%d", &opQuant);
    printf("\n\n");
    return opQuant;
}

// main
int main(int argc, char **argv)
{
    FILE *arq;
    int opMenu, opImpressao, opQuant;
    char procuraCep[9];

    arq = fopen("tarefa lab 09 baseCep.txt", "r");

    if (!arq)
    {
        printf("Arquivo nao pode ser aberto \n");
        exit(1);
    }
    // inserindo os dados na arvore
    while (!feof(arq))
    {
        insereNo(arq);
    }
    fclose(arq);

    // menu de escolha do percursso usar
    while (opMenu != 3)
    {
        quant = 0; // reinicializa a opQuant pritf dos elem

        // menu
        printf("-------BANCO DE DADOS--------\n\n\t[1]-imprimir\n\t[2]-buscarCEp\n\t[3]-sair\n\n");
        printf("digite uma opcao: ");
        scanf("%d", &opMenu);
        printf("-----------------------------\n\n");

        // opcao menu
        switch (opMenu)
        {
        case 1:
            // opcao impressao
            printf("IMPRIMIR EM:\n\t[1]-preOrdem\n\t[2]-Ordem\n\t[3]-posOrdem\n\n");

            printf("escolha uma opcao: ");
            scanf("%d", &opImpressao);
            printf("-----------------------------\n\n");

            // menu de impressao
            switch (opImpressao)
            {
            case 1:
                opQuant = escolhaQuant();
                printf("imprimindo em PreOrdem....\n");
                imprimePreOrdem(raiz, opQuant);
                printf("\n");
                break;
            case 2:
                opQuant = escolhaQuant();
                printf("imprimindo em ordem....\n");
                imprimeOrdem(raiz, opQuant);
                printf("\n");
                break;
            case 3:
                opQuant = escolhaQuant();
                printf("imprimindo em posOrdem....\n");
                imprimePosOrdem(raiz, opQuant);
                printf("\n");
                break;

            default:
                printf("Opcao invalida\n");
                break;
            }
            printf("\n");
            break;
        case 2:
            printf("BUSCAR UM CEP:\nescreva o cep procurado: ");
            scanf("%s", procuraCep);
            printf("\n\n");
            buscaCEPArvore(raiz, procuraCep);
            break;
        case 3:
            printf("saindo do menu\n");
            break;
        default:
            printf("encerrando programa\n\n");
            break;
        }
    }

    destroiArvore(raiz);

    return 0;
}