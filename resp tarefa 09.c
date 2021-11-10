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
int quant; // conta ate 10 elem

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
    if (ant == NULL)
    {
        raiz = novo;
    }
    else
    {
        if (atual == NULL)
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
void imprimePreOrdem(noCEP *n)
{
    if ((n != NULL) && (quant < 10))
    {
        imprimeNoCEP(n);
        quant++;
        imprimePreOrdem(n->esq);
        imprimePreOrdem(n->dir);
    }
}
// imprime em ordem
void imprimeOrdem(noCEP *n)
{
    if ((n != NULL) && (quant < 10))
    {
        imprimeOrdem(n->esq);
        imprimeNoCEP(n);
        quant++;
        imprimeOrdem(n->dir);
    }
}
// imprime em pos ordem
void imprimePosOrdem(noCEP *n)
{
    if ((n != NULL) && (quant < 10))
    {
        imprimePosOrdem(n->esq);
        imprimePosOrdem(n->dir);
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
        printf("cep encontrado\n");
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

// main
int main(int argc, char **argv)
{
    FILE *arq;
    int op;
    char procuraCep[9];

    arq = fopen("baseCep.txt", "r");

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
    op = 1;
    while (op != 4)
    {
        quant = 0; // imprime so 10 elem
        // escolha
        printf("digite uma opcao de percurso = ");
        printf("1 - pre-ordem\n");
        printf("2 - ordem\n");
        printf("3 - pos-ordem\n");
        printf("4 -  sair\n");
        scanf("%d", &op);
        // menu
        switch (op)
        {
        case 1:
            printf("imprimindo em pre-ordem\n");
            imprimePreOrdem(raiz);
            printf("\n");
            break;
        case 2:
            printf("imprimindo em ordem\n");
            imprimeOrdem(raiz);
            printf("\n");
            break;
        case 3:
            printf("imprimindo em pos-ordem\n");
            imprimePosOrdem(raiz);
            printf("\n");
            break;
        case 4:
            printf("saindo do menu\n");
            break;
        }
    }

    printf("busca por um cep = ");
    scanf("%s", procuraCep);

    buscaCEPArvore(raiz, procuraCep);

    printf("encerrando programa\n");
    destroiArvore(raiz);

    return 0;
}