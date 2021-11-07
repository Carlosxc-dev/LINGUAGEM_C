#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> //ou typedef
#define linha 3
#define coluna 3

int jogador1 ;
int jogador2 ;

char **matriz = NULL;
// inicializa
void inicializa()
{
    int i, j;

    matriz = malloc(linha * sizeof(char));
    for (i = 0; i < linha; i++)
    {
        matriz[i] = (char *)malloc(coluna * sizeof(char));
    }

    // atribuicao dos valores
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            matriz[i][j] = ' ';
        }
    }
}
// imprime a matriz
void imprime()
{
    int i, j;

    printf("\t\t\t-----JOGO DA VELHA-----\n");
    printf("\t\t\t     0    1    2\n");
    for (i = 0; i < linha; i++)
    {
        printf("\t\t\t%d- ", i);
        for (j = 0; j < coluna; j++)
        {
            printf("[ %c ]", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\t\t\t-----------------------\n");
}
// atribui os valores na posicao da matriz
void atribui(int jogador, int lin, int col)
{
    if (jogador == 0)
    {
        matriz[lin][col] = 'x';
    }
    else
    {
        matriz[lin][col] = 'o';
    }
}

int main(int argc, char const *argv[])
{
    char op = 's';
    int lin, col;
    inicializa();
    imprime();
    int jogador= 1;

    do
    {
        //trocad de jogadores 
        printf("\t\t\t\njogador %d\n", jogador);
        if (jogador == 0)
        {
            jogador = 1;
        }
        else
        {
            jogador = 0;
        }
        
        // insercao de dados
        printf("\t\t\tdigite a linha = ");
        scanf("%d", &lin);
        printf("\t\t\tdigite a coluna = ");
        scanf("%d", &col);
        getchar();
        printf("\n\n");

        atribui(jogador, lin, col);

        imprime();

       
    } while (op != 'n');

    return 0;
}
