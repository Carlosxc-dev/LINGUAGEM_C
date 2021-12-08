#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>

#define NUM_ALUNOS 15
#define TAM_NOME 30

HANDLE hConsole;
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;

//estrutura noAluno
typedef struct no{
   char nome[30];
   int matricula;
   int fatBal;
   struct no *esq;
   struct no *dir;
} noAluno;

//------------------------------------------------------------------------------
void rotacionarParaDireita(noAluno **atual){
    noAluno *aux;

    aux = (*atual)->esq;
    (*atual)->esq = aux->dir;
    aux->dir = (*atual);

    (*atual)->fatBal = fatorBalanceamento(*atual);
    aux->fatBal = fatorBalanceamento(aux);
    *atual = aux;
}//end rotacionarParaDireita

void rotacionarParaEsquerda(noAluno **atual){
    noAluno *aux;

    aux = (*atual)->dir;
    (*atual)->dir = aux->esq;
    aux->esq = (*atual);

    (*atual)->fatBal = fatorBalanceamento(*atual);
    aux->fatBal = fatorBalanceamento(aux);
    *atual = aux;
}//end rotacionarParaEsquerda

int altura(noAluno *atual){
    int d=0,e=0;
    if(!atual)
        return 0;
    if(!atual->esq && !atual->dir)
        return 0;
    if(atual->esq)
        d = 1+altura(atual->esq);
    if(atual->dir)
        e = 1+altura(atual->dir);
    if(e>d)
        return e;
    else
        return d;
}//end altura

int fatorBalanceamento(noAluno *atual){
    int lh,rh;

    if(atual == NULL)
        return(0);

    if(atual->esq == NULL)
        lh = 0;
    else
        lh = 1 + altura(atual->esq);

    if(atual->dir == NULL)
        rh = 0;
    else
        rh = 1 + altura(atual->dir);

    return (rh - lh);
}//end fatorBalanceamento

// Insercao na �rvore AVL
void inserirNoArvoreAVL(noAluno **noAtual, noAluno *novoNoAluno){
    if(*noAtual == NULL){
        *noAtual = novoNoAluno;
    }//end if
    else{
        if(novoNoAluno->matricula < (*noAtual)->matricula){
            inserirNoArvoreAVL(&(*noAtual)->esq, novoNoAluno);
            if(fatorBalanceamento(*noAtual) == -2){
                if(novoNoAluno->matricula < (*noAtual)->esq->matricula)
                    rotacionarParaDireita(noAtual);
                else{
                    //rota��oDupla
                    rotacionarParaEsquerda(&(*noAtual)->esq);
                    rotacionarParaDireita(noAtual);
                }//end else
            }//end if fator balanceamento == -2
        }//end if
        else{
            inserirNoArvoreAVL(&(*noAtual)->dir, novoNoAluno);
            if(fatorBalanceamento(*noAtual) == 2){
                if(novoNoAluno->matricula > (*noAtual)->dir->matricula)
                    rotacionarParaEsquerda(noAtual);
                else{
                    //rota��oDupla
                    rotacionarParaDireita(&(*noAtual)->dir);
                    rotacionarParaEsquerda(noAtual);
                }//end else
            }//end if fator bal. == 2
        }//end else
    }//end else
    (*noAtual)->fatBal = fatorBalanceamento(*noAtual);
}//end inserirNoArvoreAVL

// Insercao na �rvore bin�ria simples, desbalanceada
void inserirNoArvoreBinaria(noAluno **noAtual, noAluno *novoNoAluno){
    if(*noAtual == NULL){
        *noAtual = novoNoAluno;
    }//end if
    else{
        // insere na sub�rvore da esquerda ou direita
        if(novoNoAluno->matricula < (*noAtual)->matricula)
            inserirNoArvoreBinaria(&(*noAtual)->esq, novoNoAluno);
        else
            inserirNoArvoreBinaria(&(*noAtual)->dir, novoNoAluno);
    }//end else
}//end inserirNoArvoreBinaria

// Busca iterativa na �rvore bin�ria (AVL ou n�o)
noAluno *buscarMatricula(noAluno *raiz, int mat_chave){
    noAluno *atual = raiz;
    int contador = 0;

    while((atual != NULL) && (atual->matricula != mat_chave)){
        contador++;
        if(atual->matricula > mat_chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }//end while

    // Imprime o n�mero de itera��es necess�rias
    printf("\n*** Foram percorridos %d no(s).\n\n", contador);

    // Ir� retornar NULL cso n�o encontre
    return atual;
}//end buscarMatricula


// Impress�o de dados
void imprimeNoAluno(noAluno* no){
    printf("> Nome: %s\n", no->nome);
    printf("> Matricula: %d\n\n", no->matricula);
}//end imprimeNoAluno

//Libera��o de recursos
void libera_arvore(noAluno* atual){
    if(atual != NULL){
        libera_arvore(atual->esq);
        libera_arvore(atual->dir);
        free(atual);
    }//end if
}//end libera_arvore

void em_ordem(noAluno *raiz){
    if(raiz!=NULL){
        em_ordem(raiz->esq);
        imprimeNoAluno(raiz);
        printf("\n");
        em_ordem(raiz->dir);
    }//end if
}//end em_ordem

//fun��o que imprime no formato de �rvore deitada
void mostra(noAluno *atual, int n){
    if(atual!=NULL){
        int i;
        mostra(atual->dir, n+1);
        for(i=0; i<n; i++)
            printf("    ");
        printf("%d\n", atual->matricula);
        mostra(atual->esq, n+1);
    }//end if
}//end mostra

//fun��o que imprime no formato de �rvore deitada mostrando o fator de balanceamento
void mostraFatBal(noAluno *atual, int n){
    if(atual!=NULL){
        int i;
        mostraFatBal(atual->dir, n+1);
        for(i = 0; i < n; i++)
            printf("    ");
        printf("%d", atual->matricula);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf(" %d\n", atual->fatBal);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        mostraFatBal(atual->esq, n+1);
    }//end if
}//end mostraFatBal

void imprimeArvores(noAluno *arvAVL, noAluno *arvBinaria){
    printf("\n\nAVL  (deitada):");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("(VERDE EH O FATOR DE BALANCEAMENTO)\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("------------------------------------------\n");
    mostraFatBal(arvAVL, 0);

    printf("\n\nBINARIA  (deitada):\n");
    printf("------------------------------------------\n");
    mostra(arvBinaria, 0);
}//end imprimeArvores


//funcao para inicializar cores
//imprime o fator de balanceamento colorido
void inicializaCores(){
    //funcao para mudar as cores do terminal
    //dever se usado o #include<windows.h>
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //salva o estado atual do terminal
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
}//end inicializaCores

int main(int argc, char **argv){
    inicializaCores();

    int opcao=0;
    int i, mat;
    noAluno *arvBinaria = NULL;
    noAluno *arvAVL = NULL;
    noAluno *novo, *novoAvl;

    char listaNomes[NUM_ALUNOS][TAM_NOME]={
        "Anna Luisa", "Arthur", "Bruno", "Beatriz", "Carla",
        "Eduardo", "Felipe", "Joao", "Leonardo", "Lucas",
        "Mateus", "Paulo", "Rafael", "Tiago", "Viviane"};

    int listaMatriculas[NUM_ALUNOS]={2021050, 2021001, 2021030, 2021010, 2021020, 2021120, 2021060, 2021070, 2021040, 2021090, 2021080, 2021110, 2021130, 2021100, 2021140};

    // para cada elemento do vetor listaNomes
    for(i=0; i<NUM_ALUNOS; i++){
        printf("\n\n\nTECLE ENTER PARA INSERIR O PROXIMO ELEMENTO...");
        getchar();

        //� alocado um ponteiro para cada noAluno
        novo = (noAluno*) malloc(sizeof(noAluno));
        novoAvl = (noAluno*) malloc(sizeof(noAluno));

        //s�o preenchidos o nome e a matr�cula
        strcpy(novo->nome, listaNomes[i]);
        novo->matricula = listaMatriculas[i];
        novo->dir = NULL;
        novo->esq = NULL;

        //s�o preenchidos o nome e a matr�cula do no da AVL
        strcpy(novoAvl->nome, listaNomes[i]);
        novoAvl->matricula = listaMatriculas[i];
        novoAvl->dir = NULL;
        novoAvl->esq = NULL;

        //� chamado o m�todo de inser��o na �rvore bin�ria e arvore AVL
        inserirNoArvoreBinaria(&arvBinaria, novo);
        inserirNoArvoreAVL(&arvAVL, novoAvl);

        system("cls");
        imprimeArvores(arvAVL, arvBinaria);
    }//end for i
    do{
        system("pause");
        system("cls");
        printf("\nMenu:");
        printf("\n(1) - Buscar um Aluno na ARVORE BINARIA SIMPLES");
        printf("\n(2) - Buscar um Aluno na  ARVORE AVL");
        printf("\n(3) - Mostrar Fator de Balancemento dos nos da Arvore AVL");
        printf("\n(0) - Sair\n");
        printf("Opcao = ");
        scanf("%d", &opcao);
        //opcao = getchar();
        system("cls");
        switch(opcao){
            case 1:
                imprimeArvores(arvAVL, arvBinaria);
                printf("\n------------------------------------------\n");
                printf("BUSCA ARVORE SIMPLES: Informe um Numero de matricula: ");
                scanf("%d", &mat);

                printf("\nUtilizando a arvore binaria simples:\n");
                printf("------------------------------------------\n");
                noAluno* resp = buscarMatricula(arvBinaria, mat);

                if(resp == NULL)
                    printf("Aluno nao encontrado\n\n");
                else{
                    printf("Aluno Encontrado:\n\n");
                    imprimeNoAluno(resp);
                }//end else
                break;
            case 2:
                imprimeArvores(arvAVL, arvBinaria);
                printf("\n------------------------------------------\n");
                printf("BUSCA ARVORE AVL: Informe um Numero de matricula: ");
                scanf("%d", &mat);

                printf("\nUtilizando a arvore AVL:\n");
                printf("------------------------------------------\n");
                resp = buscarMatricula(arvAVL, mat);

                if(resp == NULL)
                    printf("Aluno nao encontrado\n\n");
                else{
                    printf("Aluno Encontrado:\n\n");
                    imprimeNoAluno(resp);
                }//end else
                break;
            case 3:
                printf("\n\nFator de balanceamento dos nos da arvore AVL:\n");
                printf("------------------------------------------\n");
                mostraFatBal(arvAVL, 0);
                break;
            default:
                if(opcao != 0)
                    printf("\nOpcao Invalida!!!\n");
                break;
        }//end switch
    }while(opcao != 0);

    // Liberando Mem�ria
    printf("Encerrando o programa...\n");
    libera_arvore(arvBinaria);
    libera_arvore(arvAVL);
    return 0;
}//end main
