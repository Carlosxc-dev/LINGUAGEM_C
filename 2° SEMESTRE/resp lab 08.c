#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define NUM_FILAS 3
#define TAM_NOME 50

//estrutura de um processo
typedef struct no
{
    float tamanho;
    char nome[TAM_NOME];
    int prioridade;
    struct no *prox;
} noProcesso;

//fila de processos a serem executados na CPU
noProcesso *filaDeProcessos[NUM_FILAS];
//vetor que indica a existencia de pelo menos um processo dessa prioridade
bool prioridadesProcessos[10];

// inicializa fila de processos
void inicializa()
{
    for (int i = 0; i < 3; i++)
    {
        filaDeProcessos[i] = NULL;
    }
}
// inicializa todas as posicoes do vetor como falso
void inicializaVetorPrioridades()
{
    for (int i = 0; i < 10; i++)
    {
        prioridadesProcessos[i] = false;
    }
}
// indica a prioridade do processo para inserer na fila certa
void insereFila(float tamProcess, char nomeProcess[TAM_NOME], int prioriProcess)
{
    int intervalo=10;
    noProcesso *atual, *ant=NULL;
    noProcesso *novo = (noProcesso*)malloc(sizeof(noProcesso));

    //intervalos considerados para cada fila de processos
    if ((prioriProcess >= 0) && (prioriProcess <= 3))
    {
        intervalo = 0;
    }
    else if ((prioriProcess >= 4) && (prioriProcess <= 6))
    {
        intervalo = 1;
    }
    else if ((prioriProcess >= 7) && (prioriProcess <= 9))
    {
        intervalo = 2;
    }
    else
    {
        printf("--> intervalo invalido\n");
    }

    // achar ultimo e o penultimo
    atual = filaDeProcessos[intervalo];
    while (atual != NULL)
    {
        ant = atual;
        atual = atual->prox;
    }
    // verifica se e o primeiro da fila 
    if(ant == NULL){
        filaDeProcessos[intervalo] = novo;
    }
    else{
        ant->prox = novo;
    }

    // inserre os dados
    novo->tamanho = tamProcess;
    strcpy(novo->nome, nomeProcess);
    novo->prioridade = prioriProcess;
    novo->prox = NULL;
}
// imprime a fila
void imprime()
{
    float somatam;
    noProcesso *atual;
    int i, aux = 1, quantProcess;

    for (i = 0; i < 3; i++)
    {
        atual = filaDeProcessos[i];
        printf("------fila [%d]-------\n", i);
        aux = 1;
        somatam = 0;
        quantProcess = 0;
        while (atual != NULL)
        {
            printf("numero[%d]  prioridade=%d  ", aux, atual->prioridade);
            printf("tamanho=%.2f  nome=%s\n", atual->tamanho, atual->nome);
            aux++;
            somatam += atual->tamanho;
            quantProcess++;
            atual = atual->prox;
        }
        printf("soma dos tamanhos = %.2f\n", somatam);
        printf("numero de processos da fila = %d\n", quantProcess);
        printf("\n\n");
    }
}
// remove o primeiro da fila
bool removePrimeiroFila(){
    int op, rt=0;
    noProcesso *aux;


    printf("digite a fila da remocao= ");
    scanf("%d", &op);

    aux = filaDeProcessos[op];

    filaDeProcessos[op] = aux->prox;

    free(aux);

    rt = 1;

    if (rt == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
//destrio toda memoria alocada pela insercao
void destroiFila(){
    int i;
    noProcesso *aux, *atual;

    for ( i = 0; i < 3; i++)
    {
        atual = filaDeProcessos[i];
        while (atual != NULL)
        {
            aux = atual;
            atual = atual->prox;
            free(aux);
        }
    }
    
    
}


int main(int argc, char **argv)
{
    inicializa();
    inicializaVetorPrioridades();

    insereFila(1, "BrOfficeCalc", 3);
    insereFila(2.3, "CodeBlocks", 9);
    insereFila(0.5, "Calculadora", 1);
    insereFila(6.4, "Firefox", 7);
    insereFila(3.1, "PhpMyAdmin", 2);
    insereFila(2.9, "Kile", 4);
    insereFila(4.5, "Gimp", 9);
    insereFila(5.5, "BrOfficeWriter", 6);
    insereFila(5.8, "GCC", 2);

    imprime();
    printf("--------------\n\n");

    if(removePrimeiroFila()==true){
        imprime();
        printf("\nprimeiro removido com sucesso\n");
    }

    destroiFila();

    return 0;
} //fim main
