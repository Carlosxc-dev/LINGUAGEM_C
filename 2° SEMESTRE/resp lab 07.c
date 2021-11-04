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
    nopeca *aux; // ponteiro auxiliar
    srand(time(NULL));
    for (int i = 0; i < 7; i++) //face1 varia 0 a 6
    {
        for (j = i; j < 7; j++) // face2 p/ nao repetir faces
        {
            aux = (nopeca *)malloc(sizeof(nopeca)); // alocar espaco de memoria
            aux->face1 = i;
            aux->face2 = j;
            aux->prox = NULL; // nao ta tribuindo para os jogadores , so criando
            if (c1 == 14)     //jog1
            {
                sort = 1;
            }
            else
            {
                if (c2 == 14) //jog 2
                {
                    sort = 0;
                }
                else
                {
                    sort = rand() % 2; //sorteia qual jogador recebe a peca
                }
            }
            if ((i == 6) && (j == 6))
            {
                primesa = aux; // peca 6:6 vai pra mesa
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
nopeca *removejogador2(int f)
{
    nopeca *ant = NULL, *atual = prijog2;
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
            prijog2 = atual->prox; // tirando a primeira peca
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
void inserefimmesa(nopeca *novo)
{
    //insere no final da lista da mesa
    nopeca *ant = NULL;
    nopeca *atual = primesa;


    while (atual != NULL)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (ant != NULL)
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

int main(int argc, char const *argv[])
{
    int ini = 6, fim = 6, cont=0;
    int jogador = inicializa();
    nopeca *aux;

    while ((prijog1 != NULL) && (prijog2 != NULL))
    {
        printf("\nmesa= ");
        imprime(primesa);
        printf("\n-----------------------------------------------------------------------------\n");
        cont++;
        printf("\nvez do jogador [%d]\t\tpartida = [%d]\n", jogador, cont);
        getchar(); // pegar enter

        if (jogador == 0)
        {
            aux = removejogador1(ini);//a2
            if (aux != NULL)
            {
                if (aux->face1 == ini)
                {
                    ini = aux->face2;
                }
                else
                {
                    ini = aux->face1;
                }
                insereiniciomesa(aux);
            }
            else
            {
                aux = removejogador1(fim);
                if (aux != NULL)
                {
                    if (aux->face1 == fim)
                    {
                        fim = aux->face2;
                    }
                    else
                    {
                        fim = aux->face1;
                    }
                    inserefimmesa(aux);
                }
            }
            jogador = 1;
        }
        else// jogador 2
        {
            aux = removejogador2(ini);
            if (aux != NULL)
            {
                if (aux->face1 == ini)
                {
                    ini = aux->face2;
                }
                else
                {
                    ini = aux->face1;
                }
                insereiniciomesa(aux);
            }
            else
            {
                aux = removejogador2(fim);
                if (aux != NULL)
                {
                    if (aux->face1 == fim)
                    {
                        fim = aux->face2;
                    }
                    else
                    {
                        fim = aux->face1;
                    }
                    inserefimmesa(aux);
                }
            }
            jogador = 0;
        }
        printf("\njogador 0 = ");
        imprime(prijog1);
        printf("\njogador 1 = ");
        imprime(prijog2);

        if (aux == NULL)
        {
            break;
        }
    }
    // mostra o vencedor
    printf("\n\n");
    if (aux == NULL)
    {
        printf("\t\t*****  VENCEU JOGADOR %d  *****\n", jogador);
    }
    else if (prijog1 == NULL)
    {
        printf("\t\t*****  VENCEU JOGADOR 1  *****\n");
    }
    else if (prijog2 == NULL)
    {
        printf("\t\t*****  VENCEU JOGADOR 2  *****\n");
    }
    return 0;
}
