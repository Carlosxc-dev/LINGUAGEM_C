#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct noCarta
{
    short numero;
    char nape;
    struct noCarta *prox;
} tCarta;

tCarta *primMonte = NULL;
tCarta *primMesa[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
tCarta *primNape[] = {NULL, NULL, NULL, NULL};
tCarta *temp[] = {NULL, NULL, NULL, NULL};

bool ehVermelho(tCarta *carta)
{
    return ((carta->nape >= 3) && (carta->nape <= 4));
} // end ehVermelho

bool ehPreto(tCarta *carta)
{
    return ((carta->nape >= 5) && (carta->nape <= 6));
} // end ehPreto

bool saoCoresDiferentes(tCarta *carta1, tCarta *carta2)
{
    return ((ehVermelho(carta1) && ehPreto(carta2)) ||
            (ehPreto(carta1) && ehVermelho(carta2)));
} // end saoCoresDiferentes

void mudaUmaCarta(origem, destino)
{
    tCarta *atualDestino, *antDestino, *atualOrigem, *antOrigem;

    // percorrer mesa da origem
    atualOrigem = primMesa[origem];
    antOrigem = NULL;
    while (atualOrigem->prox != NULL)
    {
        antOrigem = atualOrigem;
        atualOrigem = atualOrigem->prox; // ultimo
    }

    // percorrer mesa do destino
    atualDestino = primMesa[destino];
    antDestino = NULL;
    while (atualDestino->prox != NULL)
    {
        antDestino = atualDestino;
        atualDestino = atualDestino->prox; // ultimo
    }
    // condicoes para mover
    if ((atualOrigem->numero < atualDestino->numero) &&
        (saoCoresDiferentes(atualOrigem, atualDestino) == true))
    {
        atualDestino->prox = atualOrigem;
        if (antOrigem == NULL) // 1 carta mesa
        {
            primMesa[origem] = NULL;
        }
        else // +1 carta mesa
        {
            antOrigem->prox = NULL;
        }
    }
    else
    {
        printf("\t\t\tERRO => Nao e possivel mover1\n");
    }
}

bool condicaoMudarBlocoCartas(origem, destino, qntEscolha)
{
    int i, j, x, qntCartaMesa = 0;
    tCarta *ant, *atual, *aux;

    atual = primMesa[origem];
    ant = NULL;
    while (atual->prox != NULL)
    {
        ant = atual;
        atual = atual->prox;
        qntCartaMesa++;
    }

    

    return true;
}

void mudaUmBlocoCartas(origem, destino)
{
    tCarta *atualOrigem, *atualDestino, *antOrigem, *antDestino, *aux;
    tCarta *lista[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    int qntCartasEscolha = 0, i, x = 1;

    printf("escolha quantidade de cartas: ");
    scanf("%d", &qntCartasEscolha);

    if (condicaoMudarBlocoCartas(origem, destino, qntCartasEscolha) == true)
    {
        for (i = 0; i < qntCartasEscolha; i++) // faz numero de remocao do final pro inicio
        {
            // percorrer mesa da origem
            atualOrigem = primMesa[origem];
            antOrigem = NULL;
            while (atualOrigem->prox != NULL)
            {
                antOrigem = atualOrigem;
                atualOrigem = atualOrigem->prox; // ultimo
            }
            antOrigem->prox = NULL; // apago mesa origem

            lista[x] = atualOrigem; // adiciona em um vetor de ponteiros
            x++;
        }
        // percorrer mesa do destino para saber o ultimo
        atualDestino = primMesa[destino];
        antDestino = NULL;
        while (atualDestino->prox != NULL)
        {
            antDestino = atualDestino;
            atualDestino = atualDestino->prox; // ultimo
        }
        // faz insercao no destino
        for (x; x != 0; x--)
        {
            atualDestino = primMesa[destino];
            antDestino = NULL;
            while (atualDestino->prox != NULL)
            {
                antDestino = atualDestino;
                atualDestino = atualDestino->prox; // ultimo
            }
            atualDestino->prox = lista[x]; // adiciona cartas no destino
        }
    }
    else
    {
        printf("\t\t\tERRO => Nao e possivel mover! aaa\n");
    }
}

void gerarBaralho()
{
    int i, j;
    tCarta *ult;

    // coracao=3, ouro=4, paus=5, espada=6
    for (i = 0; i < 4; i++)
    {
        for (j = 1; j < 14; j++)
        {
            if (primMonte == NULL)
            {
                primMonte = (tCarta *)malloc(sizeof(tCarta));
                ult = primMonte;
            } // end if
            else
            {
                ult->prox = (tCarta *)malloc(sizeof(tCarta));
                ult = ult->prox;
            } // end else
            ult->nape = i + 3;
            ult->numero = j;
            ult->prox = NULL;
        } // end for j
    }     // end for i
} // end gerarBaralho

void embaralhaBaralho()
{
    int i, j, sort;
    tCarta *atual, *ant;

    for (i = 0; i < 26; i++)
    { // total mudanca no embaralhamento
        sort = rand() % 52;
        ant = NULL;
        atual = primMonte;
        for (j = 0; j < sort; j++)
        {
            // localizar a carta
            ant = atual;
            atual = atual->prox;
        } // end for j
        if (sort > 0)
        {
            ant->prox = atual->prox;
            atual->prox = primMonte;
            primMonte = atual;
        } // end if
    }     // end for i
} // end embaralhaBaralho

void distribuirMesa()
{
    int i = 0;
    tCarta *auxMonte, *auxMesa;
    while (primMonte != NULL)
    {
        auxMonte = primMonte;
        primMonte = primMonte->prox;
        if (primMesa[i] == NULL)
        {
            primMesa[i] = auxMonte;
            primMesa[i]->prox = NULL;
        } // end if
        else
        {
            auxMesa = primMesa[i];
            primMesa[i] = auxMonte;
            primMesa[i]->prox = auxMesa;
        } // end else
        if (primMonte == NULL)
        {
            break;
        }
        i = (i + 1) % 8;
    } // end while
} // end distribuirMesa

void imprime()
{
    int i;
    tCarta *atual;

    printf("[TEMP]=");
    for (i = 0; i < 4; i++)
    {
        if (temp[i] != NULL)
        {
            printf("%d-[%02d/%c] ", i, temp[i]->numero, temp[i]->nape);
        } // end if
        else
        {
            printf("%d-[    ] ", i);
        } // end else
    }     // end for i
    printf("\n\n");
    for (i = 0; i < 4; i++)
    {
        atual = primNape[i];
        printf("[NAPE %d]=", i);
        while (atual != NULL)
        {
            printf("[%02d/%c]", atual->numero, atual->nape);
            atual = atual->prox;
        } // end while
        printf("\n");
    } // end for i
    printf("\n");
    for (i = 0; i < 8; i++)
    {
        atual = primMesa[i];
        printf("[MESA %d]=", i);
        while (atual != NULL)
        {
            printf("[%02d/%c]", atual->numero, atual->nape);
            atual = atual->prox;
        } // end while
        printf("\n");
    } // end for i
    printf("\n");
} // end imprime

void moveMesaNape()
{
    int posMesa, posNape;
    tCarta *ant, *atual, *aux;

    printf("Posicao Pilha Mesa (0-7): ");
    scanf("%d", &posMesa);
    getchar();
    if ((posMesa >= 0) && (posMesa <= 7) && (primMesa[posMesa] != NULL))
    {
        printf("Posicao Nape (0-3): ");
        scanf("%d", &posNape);
        getchar();
        ant = NULL;
        atual = primMesa[posMesa];
        while (atual->prox != NULL)
        {
            ant = atual;
            atual = atual->prox;
        } // end while
        if ((posNape >= 0) && (posNape <= 3) &&
            (((atual->numero == 1) && (primNape[posNape] == NULL)) ||
             ((primNape[posNape] != NULL) &&
              (atual->nape == primNape[posNape]->nape) &&
              (atual->numero - 1 == primNape[posNape]->numero))))
        {
            if (ant == NULL)
            {
                primMesa[posMesa] = NULL;
            } // end if
            ant->prox = NULL;
            if (primNape[posNape] == NULL)
            {
                primNape[posNape] = atual;
            } // end if
            else
            {
                aux = primNape[posNape];
                primNape[posNape] = atual;
                primNape[posNape]->prox = aux;
            } // end else
        }     // end if
        else
        {
            printf("\t\t\tERRO => Nao pode mover carta para nape\n");
        }
    } // end if
    else
    {
        printf("\t\t\tERRO => Pilha invalida ou vazia\n");
    } // end else
} // end moveMesaNape

void moveMesaTemp()
{
    int posMesa, posTemp;
    tCarta *ant, *atual, *aux;
    printf("Posicao Pilha Mesa (0-7): ");
    scanf("%d", &posMesa);
    getchar();
    if ((posMesa >= 0) && (posMesa <= 7) && (primMesa[posMesa] != NULL))
    {
        printf("Posicao Temp (0-3): ");
        scanf("%d", &posTemp);
        getchar();
        ant = NULL;
        atual = primMesa[posMesa];
        while (atual->prox != NULL)
        {
            ant = atual;
            atual = atual->prox;
        } // end while
        if ((posTemp >= 0) && (posTemp <= 3) && (temp[posTemp] == NULL))
        {
            if (ant == NULL)
            {
                primMesa[posMesa] = NULL;
            } // end if
            ant->prox = NULL;
            temp[posTemp] = atual;
        } // end if
        else
        {
            printf("\t\t\tERRO => Nao pode mover a carta para o temp\n");
        } // end else
    }     // end if
    else
    {
        printf("\t\t\tERRO => Pilha invalida ou vazia\n");
    } // end else
} // end moveMesaTemp

void moveTempMesa()
{
    int posTemp, posMesa;
    tCarta *atual;
    printf("Posicao Temp (0-3): ");
    scanf("%d", &posTemp);
    getchar();
    if ((posTemp >= 0) && (posTemp <= 3) && (temp[posTemp] != NULL))
    {
        printf("Posicao Pilha Mesa (0-7): ");
        scanf("%d", &posMesa);
        getchar();
        if ((posMesa >= 0) && (posMesa <= 7))
        {
            if (primMesa[posMesa] == NULL)
            {
                primMesa[posMesa] = temp[posTemp];
                temp[posTemp] = NULL;
            } // end if
            else
            {
                atual = primMesa[posMesa];
                while (atual->prox != NULL)
                {
                    atual = atual->prox;
                } // end while
                if ((saoCoresDiferentes(temp[posTemp], atual)) &&
                    (atual->numero - 1 == temp[posTemp]->numero))
                {
                    atual->prox = temp[posTemp];
                    temp[posTemp] = NULL;
                } // end if
                else
                {
                    printf("\t\t\tERRO => Nao pode mover temp para mesa\n");
                }
            }
        }
        else
        {
            printf("\t\t\tERRO => Nao pode mover temp para mesa\n");
        } // end else
    }     // end if
    else
    {
        printf("\t\t\tERRO => Temp vazio\n");
    } // end else
} // end moveTempMesa

void moveNapeTemp()
{
    tCarta *ant, *aux, *atual;
    int posNaipe, posTemp;

    printf("digite a posicao pilha nape (0-3): ");
    scanf("%d", &posNaipe);
    getchar();
    if ((posNaipe >= 0) && (posNaipe <= 3) && (primNape[posNaipe] != NULL))
    {
        printf("digite a posicao temp(0-3): ");
        scanf("%d", &posTemp);
        getchar();
        if ((posTemp >= 0) && (posTemp <= 3) && (temp[posTemp] == NULL))
        {
            atual = primNape[posNaipe];
            ant = NULL;
            while (atual->prox != NULL)
            {
                ant = atual;
                atual = atual->prox;
            }

            if (ant == NULL) // caso so tenha um elemento no nape
            {
                temp[posTemp] = primNape[posNaipe];
                primNape[posNaipe] = NULL;
            }
            else // caso mais um elem no naipe
            {
                temp[posTemp] = atual;
                ant->prox = NULL;
            }
        }
        else
        {
            printf("\t\t\tERRO => posicao invalida\n");
        }
    }
    else
    {
        printf("\t\t\tERRO => posicao invalida\n");
    }
}

void moveTempNape()
{
    tCarta *aux, *atual, *ant;
    int posNape, posTemp;

    printf("digite a posicao do temp(0-3): ");
    scanf("%d", &posTemp);
    getchar();
    if ((posTemp >= 0) && (posTemp <= 3) && (temp[posTemp] != NULL))
    {
        printf("digite a posicao naipe(0-3): ");
        scanf("%d", &posNape);
        getchar();
        if ((posNape >= 0) && (posNape <= 3))
        {
            atual = primNape[posNape];
            ant = NULL;
            while ((atual != NULL) && (atual->prox != NULL))
            {
                ant = atual;
                atual = atual->prox; // ultimo
            }

            if ((((temp[posTemp]->numero == 1) && (primNape[posNape] == NULL)) ||
                 ((primNape[posNape] != NULL) &&
                  (temp[posTemp]->nape == primNape[posNape]->nape) &&
                  (temp[posTemp]->numero - 1 == primNape[posNape]->numero))))
            {
                if (atual == NULL) // vazio
                {
                    primNape[posNape] = temp[posTemp];
                }
                else // 1 ou + elem
                {
                    atual->prox = temp[posTemp];
                }
                temp[posTemp] = NULL;
            }
            else
            {
                printf("\t\t\tERRO => nao pode mover\n");
            }
        }
        else
        {
            printf("\t\t\tERRO => nao pode mover\n");
        }
    }
    else
    {
        printf("\t\t\tERRO => nao pode mover\n");
    }
}

void moveNaipeMesa()
{
    tCarta *antMesa, *atualMesa, *antNape, *atualNape, *aux;
    int posNape, posMesa;

    printf("digite a posicao do nape(0-3): ");
    scanf("%d", &posNape);
    getchar();
    if ((posNape >= 0) && (posNape <= 3) && (primNape[posNape] != NULL))
    {
        printf("digite a posicao mesa(0-7): ");
        scanf("%d", &posMesa);
        getchar();

        if ((posMesa >= 0) && (posMesa <= 7))
        {
            // pilha de napes
            atualNape = primNape[posNape];
            antNape = NULL; // tem 1 elem
            while (atualNape->prox != NULL)
            {
                antNape = atualNape;
                atualNape = atualNape->prox; // ultimo
            }

            // pilha da mesa
            atualMesa = primMesa[posMesa];
            antMesa = NULL; // 1 elem na mesa
            while ((primMesa[posMesa] != NULL) && (atualMesa->prox != NULL))
            {
                antMesa = atualMesa;
                atualMesa = atualMesa->prox;
            }
            if ((saoCoresDiferentes(atualMesa, atualNape) == true) &&
                (atualNape->numero < atualMesa->numero))
            {

                // condicoes para a pilhas da mesas
                if (antMesa == NULL) // mesa tem 1 elem
                {
                    atualMesa->prox = atualNape;
                }
                else if (primMesa[posMesa] == NULL) // mesa vazia
                {
                    primMesa[posMesa] == atualNape;
                }
                else // mesa mais 1 elem
                {
                    atualMesa->prox = atualNape;
                }

                // condicoes para as pilhas de naipes
                if (antNape == NULL) // pilha naipe tem 1 elem
                {
                    primNape[posNape] = NULL;
                }
                else // pilha de naipes tem mais de um elem
                {
                    antNape->prox = NULL;
                }
            }
            else
            {
                printf("\t\t\tERRO => nao pode mover1\n");
            }
        }
        else
        {
            printf("\t\t\tERRO => nao pode mover2\n");
        }
    }
    else
    {
        printf("\t\t\tERRO => nao pode mover3\n");
    }
}

void moveMesaMesa()
{
    int posMesaOrigem, posMesaDestino, op;

    printf("mover [1]-carta ou [2]-bloco: ");
    scanf("%d", &op);
    printf("origem - escolha mesa(0-7): ");
    scanf("%d", &posMesaOrigem);
    getchar();
    printf("destino - escolha mesa(0-7): ");
    scanf("%d", &posMesaDestino);
    getchar();

    if ((posMesaOrigem >= 0) && (posMesaOrigem <= 7) && (posMesaDestino >= 0) &&
        (posMesaDestino <= 7) && (primMesa[posMesaOrigem] != NULL))
    {
        // mover uma carta
        switch (op)
        {
        case 1:
            mudaUmaCarta(posMesaOrigem, posMesaDestino);
            break;
        case 2:
            mudaUmBlocoCartas(posMesaOrigem, posMesaDestino);
            break;
        default:
            printf("opcao invalida!!\n");
            break;
        }
    }
    else
    {
        printf("\t\t\tERRO => Nao e possivel mover!\n");
    }
}

int main(int argc, char **argv)
{
    int op = 0;
    srand(time(NULL));
    gerarBaralho();
    embaralhaBaralho();
    distribuirMesa();
    while (op != 8)
    {
        printf("\n-----------------------------------------------------\n");
        imprime();
        printf("(1)Move Mesa-Nape\n");
        printf("(2)Move Mesa-Temp\n");
        printf("(3)Move Temp-Mesa\n");
        printf("(4)Move Nape-Temp\n");
        printf("(5)Move Temp-Naipe\n");
        printf("(6)Move Nape-Mesa\n");
        printf("(7)Move Mesa-Mesa\n");
        printf("(8)Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1:
            moveMesaNape();
            break;
        case 2:
            moveMesaTemp();
            break;
        case 3:
            moveTempMesa();
            break;
        case 4:
            moveNapeTemp();
            break;
        case 5:
            moveTempNape();
            break;
        case 6:
            moveNaipeMesa();
            break;
        case 7:
            moveMesaMesa();
            break;
        default:
            printf("\t\t\tERRO => Opcao invalida\n");
            break;
        }
    }
    return 0;
}