//Laborat�rio 7 - Jogo Domin�.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct no
{
    int face1;
    int face2;
    int auxtroca;
    struct no *prox; /*Lista Din�mica Simplesmente Encadeada, utilizando somente o ponteiro do pr�ximo.*/
} noPeca;

noPeca *priJog1 = NULL; /* Ponteiro para cada uma das listas de pe�as dos jogadores */
noPeca *priJog2 = NULL; /* Todos apontam para nulo inicialmente */
noPeca *priMesa = NULL;

int ContagemJog1 = 0, ContagemJog2 = 0, cont = 0;

int inicializa() //A fun��o inicializa gera pe�as aleat�rias realiza o sorteio, se esta vai para o jogador 1, para o 2 ou para a mesa.
{
    int i, j;
    int sor;

    srand(time(NULL));

    noPeca *aux;

    /*
        Pe�as Existentes no Domin�.
        [0:0]
        [1:0] [1:1]
        [2:0] [2:1] [2:2]
        [3:0] [3:1] [3:2] [3:3]
        [4:0] [4:1] [4:2] [4:3] [4:4]
        [5:0] [5:1] [5:2] [5:3] [5:4] [5:5]
        [6:0] [6:1] [6:2] [6:3] [6:4] [6:5] [6:6]

        O objetivo � ligar as faces iguais.

        Um jogador receber� 14 pe�as e o outro 13. O que receber 14 ser� o primeiro a jogar, para manter a igualdade.

        Vence o jogador que primeiro esvaziar sua m�o.

        No laborat�rio utilizamos apenas 2 jogadores, Com 7 pe�as para cada.

        Primeiro de tudo a pe�a [6:6] era posicionada na mesa.

        */

    for (i = 0; i < 7; i++) //Face 1 //00 01 02 03 04 05 06//11 12 13 14 15 16//22 23 24 25 26// 33 34 35 35 36// 44 45 46 // 55 56 // 66
    {
        for (j = i; j < 7; j++) //Face 2
        {
            aux = (noPeca *)malloc(sizeof(noPeca)); //Aloca��o da pe�a na mem�ria.

            aux->face1 = i;

            aux->face2 = j;

            aux->prox = NULL; /*Ainda n�o est� sendo atribuida a nenhum dos jogadores */

            if (ContagemJog1 == 14) /* Vari�vel contagem para ambos os jogadores, a fim de evitar que um tenha mais pe�as do que o outro.  */
            {
                sor = 1; /*Se o jogador 1 atingiu o m�ximo de pe�as, o jogador 2 receber� a pr�xima. */
            }
            else
            {
                if (ContagemJog2 == 14)
                {
                    sor = 0; /* Se o jogador 2 atingiu o m�ximo de pe�as, o jogador 1 receber� a pr�xima. */
                }
                else
                {
                    sor = rand() % 2; /* Sorteia entre os jogadores */
                }
            }
            if ((i == 6) && (j == 6))
            {
                priMesa = aux; /* Pe�a [6:6] � a �nica posicionada na mesa */
            }
            else
            {
                if (sor == 0)
                {
                    aux->prox = priJog1;
                    priJog1 = aux;
                    ContagemJog1++; /* Adiciona na pilha do jogador 1. */
                }
                else
                {
                    aux->prox = priJog2;
                    priJog2 = aux;
                    ContagemJog2++; /* Adiciona na pilha do jogador 2. */
                }
            }
        }
    }
    if (ContagemJog1 == 14) /*Jogador 1 tem todas as pe�as */
    {
        return 0; /* O ser� o primeiro a jogar.*/
    }
    else
    {
        return 1; /*Caso seja o jogador 2 que possui as 14 pe�as, ele quem ser� o primeiro a jogar*/
    }
} //endInicializa

void imprime(noPeca *atual) /* A fun��o imprime, imprime todas as pe�a da lista de que � passada o ponteiro.*/
{
    while (atual != NULL) /*Enquanto n�o chegou ao final da lista */
    {
        printf("[%d : %d]", atual->face1, atual->face2);
        atual = atual->prox;
    }
} //endImprime

noPeca *removeJogador1(int f) /*Fun��o remove jogador 1; */
{
    noPeca *ant = NULL;
    noPeca *atual = priJog1;

    while ((atual != NULL) && (atual->face1 != f) && (atual->face2 != f)) /*Enquanto n�o encontrar, nas m�os do jogador 1, nenhuma pe�a com face equivalente, continua a percorrer a lista */
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) /*Caso a lista esteja vazia.*/
    {
        cont++;
        return NULL;
    }
    else
    {
        if (ant == NULL)
        {
            priJog1 = atual->prox; /* Caso a primeira pe�a a ser colocada na mesa seja a primeira da lista. */
        }
        else
        {
            ant->prox = atual->prox; /*Caso a pe�a esteja em qualquer outro lugar */
        }
        if (atual != NULL)
        {
            ContagemJog1--;
            return atual; /*Retorna o que foi removido e posteriormente ser� enviado a mesa*/
        }
        else
        {
            cont++;
            return NULL;
        }
    }
}

noPeca *removeJogador2(int f) /*Fun��o remove jogador 1; */
{
    noPeca *ant = NULL;
    noPeca *atual = priJog2;

    while ((atual != NULL) && (atual->face1 != f) && (atual->face2 != f)) /*Enquanto n�o encontrar, nas m�os do jogador 1, nenhuma pe�a com face equivalente, continua a percorrer a lista */
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) /*Caso a lista esteja vazia.*/
    {
        cont++;
        return NULL;
    }
    else
    {
        if (ant == NULL)
        {
            priJog2 = atual->prox; /* Caso a primeira pe�a a ser colocada na mesa seja a primeira da lista. */
        }
        else
        {
            ant->prox = atual->prox; /*Caso a pe�a esteja em qualquer outro lugar */
        }
        if (atual != NULL)
        {
            ContagemJog2--;
            return atual; /*Retorna o que foi removido e posteriormente ser� enviado a mesa*/
        }
        else
        {
            cont++;
            return NULL;
        }
    }
}

void insereInicioMesa(noPeca *novo)
{
    novo->prox = priMesa;
    priMesa = novo;
}

void insereFimMesa(noPeca *novo)
{
    noPeca *atual = priMesa;
    noPeca *ant = NULL;

    while (atual != NULL)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (ant == NULL)
    {
        atual->prox = novo;
        novo->prox = ant;
    }
    else
    {
        ant->prox = novo;
        novo->prox = atual;
    }
}

int main(int argc, char **argv)
{
    int ini = 6, fim = 6; /*O ini � a FACE 1 e o fim, a FACE 2*/

    int jogador = inicializa(); //Recebe qual o primeiro jogador vai jogar.

    int x = 0;

    noPeca *aux;

    printf("\n");
    printf("  Jogador 1: ");
    imprime(priJog1);
    printf("\n");
    printf("  Jogador 2: ");
    imprime(priJog2);
    printf("\n");

    while ((priJog1 != NULL) && (priJog2 != NULL)) /*Enquanto nenhuma das listas est� vazia, continua o jogo. */
    {
        printf("\n Mesa: ");
        imprime(priMesa); //Imprime a Mesa.
        printf("\n Vez Jogador:  %d\n", jogador);
        printf("\n\tDIGITE ENTER PARA CONTINUAR...\n");
        getchar();

        if (jogador == 0) //Caso seja o jogador 1.
        {
            aux = removeJogador1(ini); /*Recebe o ponteiro da pe�a que tem a face inicial compat�vel.*/

            if (aux != NULL)
            {
                if (aux->face1 == ini)
                {
                    ini = aux->face2;
                    aux->auxtroca = aux->face1;
                    aux->face1 = aux->face2;
                    aux->face2 = aux->auxtroca;
                } //if(aux->face1 == ini)
                else
                {
                    ini = aux->face1; //Caso precise inverter a pe�a
                }
                insereInicioMesa(aux); /*Insere a pe�a no in�cio da mesa, ou seja, compat�vel com a face 1 da pe�a da mesa.*/
            }                          // if (aux != NULL)
            else
            {
                aux = removeJogador1(fim); /*Testa as segundas faces da lista do jogador 1,*/
                if (aux != NULL)
                {
                    if (aux->face1 == fim)
                    {
                        fim = aux->face2;
                    }
                    else
                    {
                        fim = aux->face1;
                        aux->auxtroca = aux->face1;
                        aux->face1 = aux->face2;
                        aux->face2 = aux->auxtroca;
                    }
                    insereFimMesa(aux);
                }
            }
            jogador = 1;
        } //endif jogador = 0;
        else
        {                              //Jogador 1
            aux = removeJogador2(ini); /*Teste das faces para o jogador 2.*/
            if (aux != NULL)
            {
                if (aux->face1 == ini)
                {
                    ini = aux->face2;
                    aux->auxtroca = aux->face1;
                    aux->face1 = aux->face2;
                    aux->face2 = aux->auxtroca;
                }
                else
                {
                    ini = aux->face1;
                }
                insereInicioMesa(aux);
            }
            else
            {
                aux = removeJogador2(fim);
                if (aux != NULL)
                {
                    if (aux->face1 == fim)
                    {
                        fim = aux->face2;
                    }
                    else
                    {
                        fim = aux->face1;
                        aux->auxtroca = aux->face1;
                        aux->face1 = aux->face2;
                        aux->face2 = aux->auxtroca;
                    }
                    insereFimMesa(aux);
                }
            }
            jogador = 0;
        }
        printf("\n Jogador  1 = ");
        imprime(priJog1);
        printf("\n Jogador   2 = ");
        imprime(priJog2);

        if ((aux == NULL) && ((ContagemJog1 == 0) || (ContagemJog2 == 0)))
        {
            break;
        }
        else if (cont >= 10)
        {
            x = 1;
            break;
        }
    }
    printf("\n33Mesa Final: ");
    imprime(priMesa);

    printf("\n\n\t");
    if (x == 1)
    {
        if (ContagemJog1 > ContagemJog2)
        {
            printf("O jogador 2 venceu.\n");
        }
        else
        {
            printf("O jogador 1 venceu.\n");
        }
    }
    else
    {
        if (aux == NULL)
        {
            printf("Venceu jogador:  %d\n", jogador + 1);
        }
        else if (priJog1 == NULL)
        {
            printf("Venceu Jogador 1\n");
        }
        else if (priJog2 == NULL)
        {
            printf("Venceu Jogador2\n");
        }
    }

    return 0;
}
