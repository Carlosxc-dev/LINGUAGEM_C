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

noProcesso *ult=NULL;

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
void insereFila(float tamProcess, char nomeProcess, int prioriProcess)
{
    noProcesso *novo;
    int intervalo=0;

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

    // insercao na fila
    novo = (noProcesso *)malloc(sizeof(noProcesso));

    if (filaDeProcessos[intervalo] == NULL)
    {
        filaDeProcessos[intervalo] = novo;
    }

    novo->tamanho = tamProcess;
    //strcpy(novo->nome, nomeProcess);
    novo->prioridade = intervalo;

    if (ult != NULL)
    {
        ult->prox = novo;
    }
    ult = novo;
    novo->prox = NULL;
}
// imprime a fila
void imprime()
{
    float tamProcess = 0;
    noProcesso *atual;
    int i, aux = 1, quantProcess=0;

    for (i = 0; i < 3; i++)
    {
        atual = filaDeProcessos[i];
        printf("------fila [%d]-------\n", i);
        aux = 1;
        while (atual != NULL)
        {
            printf("numero[%d] nome= %s tamanho= %.2f prioridade=%d\n", aux, atual->nome, atual->tamanho, atual->prioridade);
            atual = atual->prox;
            aux++;
            tamProcess += atual->tamanho;
            quantProcess++;
        }
        printf("soma dos tamanhos = %.2f\n", tamProcess);
        printf("numero de processos da fila = %d\n", quantProcess);
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
    return 0;
} //fim main
