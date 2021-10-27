#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct no
{
    short int numero;
    char naipe;
    struct no *prox;
} tCarta;

tCarta *priMesa[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
tCarta *priNaipe[4] = {NULL, NULL, NULL, NULL};
tCarta *priTemp[4] = {NULL, NULL, NULL, NULL};
tCarta *priMonte = NULL;    //inicio da lista de cartas a ser gerada

// gera as 52 cartas com 4 naipes diferentes
void gerarBaralho()
{
    int i, j;
    tCarta *aux;
    //cria os naipes copa, ouro, paus, espada
    for (i = 3; i < 7; i++) // cria os naipes
    {
        for (j = 0; j < 13; j++) // cria os numeros das cartas
        {
            aux = (tCarta *)malloc(sizeof(tCarta));
            aux->numero = j + 1;
            aux->naipe = i;
            aux->prox = priMonte;
            priMonte = aux; // ponteiro que garda a primeira posicao referencia
        }
    }
}
//embaralha as 52 cartas do primonte
void embaralhaBaralho()
{
    int i, j, k, sorteio1, sorteio2;
    tCarta *ptr1, *ptr2, *aux;
    srand(time(NULL));

    for (i = 0; i < 70; i++)
    {
        // inicializacao para nao peder ponteiro inicial
        ptr1 = priMonte;
        ptr2 = priMonte;
        aux = priMonte;
        //sorteios dos numeros para percorrer montes
        sorteio1 = rand() % 52;
        sorteio2 = rand() % 52;
        // busca os sorteios nos montes
        if (sorteio1 != sorteio2)
        {
            for (j = 0; j < sorteio1; j++)
            {
                ptr1 = ptr1->prox; // pega o endereco pra troca
            }
            for (k = 0; k < sorteio2; k++)
            {
                ptr2 = ptr2->prox; // pega o endereco pra troca
            }
            //faz as trocas
            aux->naipe = ptr1->naipe;
            ptr1->naipe = ptr2->naipe;
            ptr2->naipe = aux->naipe;

            aux->numero = ptr1->numero;
            ptr1->numero = ptr2->numero;
            ptr2->numero = aux->numero;
        }
        else
        {
            i--;
        }
    }
}
// distribuir as cartas na mesa sendo 4 primeiras pilhas sao com 7 cartas
void distribuirMesa()
{
    int i, j;
    tCarta *atual = NULL;
    tCarta *aux = priMonte;
    priMesa[0] = priMonte;
    for (i = 0; i < 8; i++)
    {
        priMesa[i] = aux;
        atual = aux;

        if (i <= 3) //percorre ate 4 mesa
        {
            for (j = 0; j < 6; j++)
            { // percorre as sete cartas do baralho
                //printf("[%d/%c]  ", atual->numero, atual->naipe);
                atual = atual->prox;
            }
            aux = atual->prox;  // setimo valor da mesa 0
            atual->prox = NULL; // fim da mesa
            //printf("\n");
        }
        else //percorre ate 8 mesa
        {
            for (j = 0; j < 5; j++)
            { // percorre as sete cartas do baralho
                //printf("[%d/%c]  ", atual->numero, atual->naipe);
                atual = atual->prox;
            }
            aux = atual->prox;  // setimo valor da mesa 0
            atual->prox = NULL; // fim da mesa
                                // printf("\n");
        }
    }
}
// imprime jogo
void imprime()
{
    int i, j;
    tCarta *aux;

    //imprime os mesas
    for (i = 0; i < 8; i++) //mesa
    {

        printf("[mesa %d]= ", i);
        aux = priMesa[i];
        while (aux != NULL)
        {
            printf("[%2d/%c] ", aux->numero, aux->naipe);
            aux = aux->prox;
        }
        printf("\n");
    }
}
// Mesa para Temporario
void moveMesaTemp()
{
    int posCarta = -1;
    int posTemp = -1;

    printf("Digite posicao para mover pro temp [0-7] = ");
    scanf("%d", &posCarta);
    getchar();

    if ((posCarta >= 0) && (posCarta <= 7) && (priMesa[posCarta] != NULL))
    {
        while ((posTemp < 0) || (posTemp > 3))
        {
            printf("Digite a posicao temp = ");
            scanf("%d", &posTemp);
            getchar();

            if ((posTemp >= 0) && (posTemp <= 3))
            {
                if (priTemp[posTemp] == NULL)
                {
                    tCarta *ant = NULL;
                    tCarta *atual = priMesa[posCarta];

                    while (atual->prox != NULL)
                    {
                        ant = atual;
                        atual = atual->prox;
                    }
                    ant->prox = NULL;
                    priTemp[posTemp] = atual;
                    printf("\ntemp %d = [%d/%c]\n", posTemp, priTemp[posTemp]->numero, priTemp[posTemp]->naipe);
                }
                else
                {
                    printf("\nPosicao ocupada\n");
                }
            }
            else
            {
                printf("\nposicao  nao disponivel\n");
            }
        }
    }
    else
    {
        printf("\nPosicao  indisponivel na Mesa\n");
    }
}
// Temporario para Mesa
void moveTempMesa()
{
    tCarta *aux;

    int posTemp = -1;
    int posMesa = -1;

    printf("Digite a posicao para mover para mesa = ");
    scanf("%d", &posTemp);
    getchar();

    if ((posTemp >= 0) && (posTemp <= 3))
    {
        if (priTemp[posTemp] != NULL)
        {
            printf("Digite a posicao da pilha na 'Mesa': ");
            scanf("%d", &posMesa);
            getchar();

            if (priMesa[posMesa] != NULL)
            {
                if ((posMesa >= 0) && (posMesa <= 7))
                {
                    tCarta *ant = NULL;
                    tCarta *atual = priMesa[posMesa];

                    while (atual->prox != NULL)
                    {
                        ant = atual;
                        atual = atual->prox;
                    }
                    if (cartaMaior(priTemp[posTemp]->numero, atual->numero) == -1)
                    {
                        atual->prox = priTemp[posTemp];
                        priTemp[posTemp] = NULL;
                        atual->prox->prox = NULL;
                    }
                    else
                    {
                        printf("Naipe do temp e maior que da mesa \n");
                    }
                }
                else
                {
                    printf("Posicao indisponivel\n");
                }
            }
            else
            {
                printf("Inserindo na posicao %d vazia\n");
                priMesa[posMesa] = priTemp[posTemp];
                priTemp[posTemp] = NULL;
                priMesa[posMesa]->prox = NULL;
                posMesa = -1;
            }
        }
        else
        {
            printf("Posica vazia\n");
            posTemp = -1;
        }
    }
    else
    {
        printf("carta no temp esta vazio\n");
        posTemp = -1;
    }
}
// naipe das mesas
int cartaMaior(int c1, int c2)
{
    if(c1 > c2)
    {
        return 1;
    } 
    else
    {
        if(c1 == c2)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
}
// Mesa para Naipes
void moveMesaNaipe()
{
    int posCarta = -1;
    int posNaipe = -1;
    
    printf("Digite posicao mover p/ naipes = ");
    scanf("%d", &posCarta);
    getchar();

    if((posCarta >= 0) && (posCarta <= 7))
    {
        if(priMesa[posCarta] != NULL)
        {
            tCarta *ant = NULL;
            tCarta *atual = priMesa[posCarta];
            while(atual->prox != NULL)
            {
                ant = atual;
                atual = atual->prox;
            }
            printf("Digite posicao naipe = ");
            scanf("%d", &posNaipe);
            getchar();

            if((posNaipe >= 0) && (posNaipe <= 3))
            {   
                if(priNaipe[posNaipe] == NULL)
                {
                    if(atual->numero == 1)
                    {
                        priNaipe[posNaipe] = atual;
                        ant->prox = NULL;
                        priNaipe[posNaipe]->prox = NULL;
                    }
                    else
                    {
                        printf("primeira carta na pilha de Naipes tem ser 1\n");
                    }
                    
                }
                else
                {   
                    tCarta *aux;
                    aux = priNaipe[posNaipe];
                    while(aux->prox != NULL)
                    {
                        aux = aux->prox;
                    }
                    if(aux->naipe == atual->naipe)
                    {
                        if(aux->numero == atual->numero - 1)
                        {
                            aux->prox = atual;
                            atual->prox = NULL;

                            if(ant != NULL)
                            {
                                ant->prox = NULL;
                            }
                            else
                            {
                                priMesa[posCarta] = NULL;
                            }
                        }
                        else
                        {
                            printf("pilha de naipes fora de sequencia\n");
                        }   
                    }
                    else
                    {
                        printf("Naipes diferentes\n");
                    }   
                } 
            }
            else
            {
                printf("Carta na posicao disponivel.\n");
            }
        }
        else
        {
            printf("Posicao null\n");
        } 
    }
    else
    {
        printf("Posicao indisponivel\n");
    }
}
// Destruir pilhas
void destruirPilhas()
{
    tCarta *atual = NULL;
    tCarta *apaga = NULL;

    for(int i = 0; i < 4; i++)
    {
        atual = priTemp[i];

        if(atual != NULL)
        {
            free(atual);
        }
    }

    atual = NULL;
    apaga = NULL;
    for(int i = 0; i < 4; i++)
    {
        atual = priNaipe[i];
        
        while(atual != NULL){
            apaga = atual;
            atual = atual->prox;
            free(apaga);
        }
    }
    
    atual = NULL;
    apaga = NULL;
    for(int i = 0; i < 8; i++)
    {
        atual = priMesa[i];

        while(atual != NULL){
            apaga = atual;
            atual = atual->prox;
            free(apaga);
        }
    }
}
int main(int argc, char **argv)
{
    int op = 0;
    srand(time(NULL));
    gerarBaralho();
    embaralhaBaralho();
    distribuirMesa();
    while (op != 4)
    {
        printf("\n");
        imprime();
        printf("\n");
        printf("(1)Move Mesa-Temp\n");
        printf("(2)Move Mesa-Nape\n");
        printf("(3)Move Temp-Mesa\n");
        printf("(4)Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1:
            moveMesaTemp();
            break;
        case 2:
            moveMesaNaipe();
            break;
        case 3:
            moveTempMesa();
            break;
        case 4:
            op = 4;
        default:
            printf("Opcao Invalida.\n");
            break;
        }
    }
    destruirPilhas();
    return 0;
}
