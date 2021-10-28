#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int larva = 0;
int alga = 1;
int sais = 1;
int jogadas = 1;
char tanque[25][50];

void imprime()
{
    int i, j;
    printf("            1111111111222222222233333333334444444444\n");
    printf("  01234567890123456789012345678901234567890123456789\n");
    for (i = 0; i < 25; i++)
    {
        printf("%2d", i);
        for (j = 0; j < 50; j++) // espaco
        {
            printf("%c", tanque[i][j]);
        }
        printf("\n");
    }
}

void inicializa()
{
    int i, j, lin, col;
    for (i = 0; i < 25; i++)
    {
        for (j = 0; j < 50; j++)
        {
            tanque[i][j] = ' ';
        }
    }
    // 3 triangulos 1-3
    for (i = 0; i < 2; i++)
    {
        lin = rand() % (25 - 1);
        col = rand() % (50 - 2);
        tanque[lin][col + 1] = ':';
        tanque[lin + 1][col] = ':';
        tanque[lin + 1][col + 1] = ':';
        tanque[lin + 1][col + 2] = ':';
    }
    // 2 triangulos 3-5
    for (i = 0; i < 2; i++)
    {
        lin = rand() % (25 - 2);
        col = rand() % (50 - 4);
        tanque[lin][col + 2] = ':';
        tanque[lin + 1][col + 1] = ':';
        tanque[lin + 1][col + 2] = ':';
        tanque[lin + 1][col + 3] = ':';
        tanque[lin + 2][col] = ':';
        tanque[lin + 2][col + 1] = ':';
        tanque[lin + 2][col + 2] = ':';
        tanque[lin + 2][col + 3] = ':';
        tanque[lin + 2][col + 4] = ':';
    }
    // 10 conchs
    for (i = 0; i < 10; i++)
    {
        lin = rand() % (25 - 2) + 1;
        col = rand() % (50 - 2) + 1;
        if (tanque[lin][col + 2] == ' ')
        {
            tanque[lin][col] = '@';
        }
        else
        {
            i++;
        }
    }
    // 5 brotos
    for (i = 0; i < 5; i++)
    {
        lin = rand() % (25);
        col = rand() % (50);
        if (tanque[lin][col + 2] == ' ')
        {
            tanque[lin][col] = 'y';
        }
        else
        {
            i++;
        }
    }
    // 3 peixes
    for (i = 0; i < 3; i++)
    {
        lin = rand() % (25);
        col = rand() % (50);
        if (tanque[lin][col + 2] == ' ')
        {
            tanque[lin][col] = 'x';
        }
        else
        {
            i++;
        }
    }
}

void cultivar()
{
    int lin, col;
    if (alga > 0)
    {
        printf("cultivar alga [lin, col]: ");
        scanf("%d %d", &lin, &col);
        getchar(); // captura enter
        if ((lin >= 0) && (lin <= 24) && (col >= 0) && (col <= 24))
        {
            if (tanque[lin][col] = ' ')
            {
                tanque[lin][col] = 'y';
                alga--;
                jogadas++;
            }
            else
            {
                printf("espaco ocupado");
            }
        }
        else
        {
            printf("coordenadas invalidas !!");
        }
    }
    else
    {
        printf("sem saldo de alga \n");
    }
}

void fertilizar()

{
    int lin, col;
    if (sais > 0)
    {
        printf("cultivar alga [lin, col]: ");
        scanf("%d %d", &lin, &col);
        getchar(); // captura enter
        if ((lin >= 0) && (lin <= 24) && (col >= 0) && (col <= 24))
        {
            if (tanque[lin][col] = 'y')
            {
                tanque[lin][col] = 'Y';
                sais--;
                jogadas++;
            }
            else
            {
                printf("coordenada sem broto");
            }
        }
        else
        {
            printf("coordenadas invalidas !!");
        }
    }
    else
    {
        printf("sem saldo de sais \n");
    }
}

void mover()
{
    int l1, c1, l2, c2;
    printf("coordenada de origem [ lin col]");
    scanf("%d %d", &l1, &c1);
    getchar(); // captura enter
    if ((l1 >= 0) && (l1 <= 24) && (c1 >= 0) && (c1 <= 49))
    {
        if ((tanque[l1][c1] == '-') || (tanque[l1][c1] == 'x') || (tanque[l1][c1] == 'X'))
        {
            printf("coordenada de destino [ lin col]");
            scanf("%d %d", &l2, &c2);
            getchar(); // captura enter
            if ((l2 >= 0) && (l2 <= 24) && (c2 >= 0) && (c2 <= 49))
            {
                if ((l2 - l1 >= -1) && (l2 - l1 <= 1) && (c2 - c1 >= -1) && (c2 - c1 <= 1)) // visinho
                {
                    if (tanque[l2][c2] == ' ') // move
                    {
                        tanque[l2][c2] = tanque[l1][c1];
                        tanque[l1][c1] = ' ';
                        jogadas++;
                    }
                    if ((tanque[l2][c2] == ':') || (tanque[l2][c2] == '@')) // morre
                    {
                        tanque[l1][c1] = ' ';
                        jogadas++;
                    }
                    if ((tanque[l1][c1] == 'X') && (tanque[l2][c2] == 'x')) // reproduz
                    {
                        if (larva > 0)
                        {
                            tanque[l1][c1] = '-';
                            larva--;
                            jogadas++;
                        }
                        else
                        {
                            printf("sem saldo de larvas\n");
                        }
                    }
                    if ((tanque[l2][c2] == 'y') || (tanque[l2][c2] == 'Y')) // evolui
                    {
                        if (tanque[l1][c1] == '-')
                        {
                            tanque[l2][c2] = 'x';
                            tanque[l1][c1] = ' ';
                            jogadas++;
                        }
                        if (tanque[l1][c1] == 'x')
                        {
                            tanque[l2][c2] = 'X';
                            tanque[l1][c1] = ' ';
                            jogadas++;
                        }
                        if (tanque[l1][c1] == 'X')
                        {
                            tanque[l2][c2] = 'x';
                            tanque[l1][c1] = ' ';
                            jogadas++;
                        }
                    }
                }
                else
                {
                    printf("destino nao e visinho\n");
                }
            }
            else
            {
                printf("coordenadas destno invalidas\n");
            }
        }
        else
        {
            printf("nao tem paixes\n");
        }
    }
    else
    {
        printf("coordenadas invalidas\n");
    }
}

void quebrar()
{
    int lin, col;

    printf("quebra concha [lin, col]: ");
    scanf("%d %d", &lin, &col);
    getchar(); // captura enter
    if ((lin >= 0) && (lin <= 24) && (col >= 0) && (col <= 24))
    {
        if (tanque[lin][col] = '@')
        {
            tanque[lin][col] = ' ';
            if (rand() % 100 < 25)
            {
                sais++;
            }
            if (rand() % 100 < 25)
            {
                larva++;
            }
            if (rand() % 100 < 25)
            {
                alga++;
            }
            if (rand() % 100 < 10)
            {
                sais += 2;
            }
            if (rand() % 100 < 10)
            {
                larva += 2;
            }
            if (rand() % 100 < 5)
            {
                alga += 2;
            }
        }
        else
        {
            printf("coordenada nao tem concha");
        }
    }
    else
    {
        printf("coordenadas invalidas !!");
    }
}

void pescar()
{
    int lin, col;

    printf("pescar peixe [lin, col]: ");
    scanf("%d %d", &lin, &col);
    getchar(); // captura enter
    if ((lin >= 0) && (lin <= 24) && (col >= 0) && (col <= 24))
    {
        if (tanque[lin][col] = 'x')
        {
            tanque[lin][col] = ' ';
            sais++;
            jogadas++;
        }
        if (tanque[lin][col] = 'X')
        {
            tanque[lin][col] = ' ';
            sais += 2;
            larva++;
            jogadas++;
        }
    }
    else
    {
        printf("coordenadas invalidas\n");
    }
}

void noite()
{
    int i, j;
    jogadas++;
    for (i = 0; i < 25; i++)
    {
        for (j = 0; j < 50; j++)
        {
            if ((tanque[i][j] == '-') && (rand() % 100 < 30))
            {
                tanque[i][j] = 'x';
            }
            if ((tanque[i][j] == 'y') && (rand() % 100 < 50))
            {
                tanque[i][j] = 'Y';
            }
            if ((i != 0) && (i != 24) && (j != 0) && (j != 49) && (tanque[i][j] == ' ') && (rand() % 1250 == 0))
            {
                tanque[i][j] = '@';
            }
            if (tanque[i][j] == '@')
            {
                tanque[i - 1][j - 1] = ' ';
                tanque[i - 1][j] = ' ';

                tanque[i][j - 1] = ' ';
                tanque[i][j + 1] = ' ';

                tanque[i + 1][j - 1] = ' ';
                tanque[i + 1][j] = ' ';
                tanque[i + 1][j + 1] = ' ';
            }
        }
    }
}

int main(int argc, char *arv[])
{
    srand(time(NULL));
    //b invoca  funccao
    inicializa();
    char op = ' ';
    while (op != 's')
    {
        printf("\n\n");
        //a) funcao imprime
        imprime();
        printf("larva=%d alga=%d sais=%d\n", larva, alga, sais);
        printf("(c)ultivar / (f)ertilizar / (m)over / (q)uebrar / (p)escar / (n)oite / (s)air");
        printf("[Jogada %d] opcao:", jogadas);
        op = getch();
        printf("%c\n", op);
        switch (op)
        {
        case 'c':
            //c cuitivar
            cultivar();
            break;
        case 'f':
            //d fertlizar
            fertilizar();
            break;
        case 'm':
            //e mover
            mover();
            break;
        case 'q':
            //f quebrar
            quebrar();
            break;
        case 'p':
            //g pescar
            pescar();
            break;
        case 'n':
            //h noite
            noite();
            break;
        case 's':
            break;
        default:
            printf("[opcao invalida]\n");
        }
        if (jogadas > 7)
        {
            imprime();
            noite();
        }
    }
    return 0;
}
