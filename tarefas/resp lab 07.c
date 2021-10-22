#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no
{
    int face1;
    int face2;
    struct no *prox;
} nopeca;

nopeca *prijog1 = NULL;
nopeca *prijog2 = NULL;
nopeca *primesa = NULL;

int inicializa()
{
    int i, j, c1 = 0, c2 = 0, sort;
    nopeca *aux;
    srand(time(NULL));
    for (int i = 0; i < 7; i++) //face2
    {
        for (j = i; j < 7; j++) // face2
        {
            aux = (nopeca *)malloc(sizeof(nopeca));
            aux->face1 = i;
            aux->face2 = j;
            aux->prox = NULL;
            if (c1 == 14)
            {
                sort = 1;
            }
            else
            {
                if (c2 == 14)
                {
                    sort = 0;
                }
                else
                {
                    sort = rand() % 2;
                }
            }
            if ((i == 6) && (j == 6))
            {
                primesa = aux;
            }
            else //pecas diferentes de 6:6
            {
                if (sort == 0)
                {
                    //insere pecas jgador 1
                    aux->prox = prijog1;
                    prijog1 = aux;
                    c1++;
                }
                else
                {
                    //insere pecas jogador 2
                    aux->prox = prijog2;
                    prijog2 = aux;
                    c2++;
                }
            }
        }
    }
    if (c1 == 14)
    {
        return 0;
    }
    else
    {
        return 1;
    }
} //end inicializa
void imprime(nopeca *atual)
{
    while (atual != NULL)
    {
        printf("[%d:%d]", atual->face1, atual->face2);
        atual = atual->prox;
    }
    printf("\n");
}
nopeca *removejogador1(int f)
{
    nopeca *ant = NULL, *atual = prijog1;
    while ((atual != NULL) && (atual->face1 != f) & (atual->face2 != f))
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL)
    {
        return NULL;
    }
    else
    {
        if (ant == NULL)
        {
            prijog1 = atual->prox;
        }
        else
        {
            ant->prox = atual->prox; // qualquer peca da lista
        }
    }
    if (atual != NULL)
    {
        return atual;
    }
    else
    {
        return NULL;
    }
}
void insereiniciomesa(nopeca *novo)
{
    novo->prox = primesa;
    primesa = novo;
}
void inserefimmesa(nopeca *novo){
    //terminar de fazer
}

int main(int argc, char const *argv[])
{
    int ini = 6, fim = 6;
    int jogador = inicializa();
    nopeca *aux;

    //so imprime as mesas
    /*printf("mesa = ");
    imprime(primesa);
    printf("jogador 1 = ");
    imprime(prijog1);
    printf("jogador 2 = ");
    imprime(prijog2);*/

    while ((prijog1 != NULL) && (prijog2 != NULL))
    {
        printf("mesa= ");
        imprime(primesa);
        printf("jogador %d\n", jogador);
        getchar();

        if (jogador == 0)
        {
            aux = removejogador(ini);
            if (aux != NULL)
            {
                insereiniciomesa(aux);
                if (aux->face1 == ini)
                {
                    ini = aux->face2;
                }
                else
                {
                    ini = aux->face1;
                }
            } // fim if aux == null
            else
            {
                aux = removejogador1(fim);
                if (aux != NULL)
                {
                    insereiniciomesa(aux);
                    if (aux->face1)
                    {
                        fim = aux->face2;
                    }
                    else
                    {
                        fim = aux->face1;
                    }
                }
            }
            jogador = 1;
        } // end if jogador 0
        else
        {
            //jogador2
            aux=removejogador2(ini);
            if (aux!=NULL)
            {
                insereiniciomesa(aux);
                if (aux->face1== ini)
                {
                    ini = aux->face2;
                }
                else
                {
                    ini = aux->face1;
                }
                
            }
            else
            {
                aux = removejogador2(fim);
                if (aux->face1 == fim)
                {
                    fim = aux->face2;
                }
                else
                {
                    fim = aux->face1;
                }
                jogador = 0;
            }
        }
        printf("jogador 1= ");
        imprime(prijog1);
        printf("jogador2= ");
        imprime(prijog2);
        if(aux == NULL)
        {
            break;
        }
    }
    if (aux = NULL)
    {
        printf("VENCEU JOGADOR %d\n", jogador);
    }
    else if (prijog1 == NULL)
    {
        printf("VENCEU JOGADOR 1\n");
    }
    else if (prijog2 == NULL)
    {
        printf("VENCEU JOGADOR 2\n");
    }
    return 0;
}
