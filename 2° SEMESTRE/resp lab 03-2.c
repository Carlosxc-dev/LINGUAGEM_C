#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    int i,j, linha, coluna;
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;
    srand(time(NULL));

    printf("digite a quantidade de linhas:");
    scanf("%d", &linha);
    printf("digite a quantidade de coluna:");
    scanf("%d", &coluna);

    // alocacao matriz a
    if (a == NULL)
    {
        a = malloc(linha*sizeof(int));
        for ( i = 0; i < linha; i++)
        {
            a[i] = (int*)malloc(coluna*sizeof(int));
        }
    }
    else
    {
        printf("matriz ja alocada!!\n");
    }
    // alocacao matriz b
     if(b == NULL)
    {
        b = malloc(linha*sizeof(int));
        for ( i = 0; i < linha; i++)
        {
            b[i] = (int*)malloc(coluna*sizeof(int));
        }
    }
    else
    {
        printf("matriz ja alocada!!\n");
    }
    // alocacao matriz c
     if (c == NULL)
    {
        c = malloc(linha*sizeof(int));
        for ( i = 0; i < linha; i++)
        {
            c[i] = (int*)malloc(coluna*sizeof(int));
        }
    }
    else
    {
        printf("matriz ja alocada!!\n");
    }

    for ( i = 0; i < linha; i++)
    {
        for ( j = 0; j < coluna; j++)
        {
            a[i][j] = rand()%10+1;
            b[i][j] = rand()%10+1;
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    //impressao matriz A
    printf("matriz A \n");
    for ( i = 0; i < linha; i++)
    {
        for ( j = 0; j < coluna; j++)
        {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
    //impressao matriz b
    printf("matriz B \n");
    for ( i = 0; i < linha; i++)
    {
        for ( j = 0; j < coluna; j++)
        {
            printf(" %d ", b[i][j]);
        }
        printf("\n");
    }
    //impressao matriz c
    printf("matriz C \n");
    for ( i = 0; i < linha; i++)
    {
        for ( j = 0; j < coluna; j++)
        {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
    //desalocando matriz A
    if (a != NULL)
    {
        printf("liberando matriz A\n");
        for ( i = 0; i < linha; i++)
        {
            free(a[i]);
        }
        free(a[j]);
    }
    else
    {
        printf("matriz nao alocada\n");
    }
    //desalocando matriz B
    if (b != NULL)
    {
        printf("liberando matriz B\n");
        for ( i = 0; i < linha; i++)
        {
            free(b[i]);
        }
        free(b[j]);
    }
    else
    {
        printf("matriz nao alocada\n");
    }
    //desalocando matriz c
    if (c != NULL)
    {
        printf("liberando matriz C\n");
        for ( i = 0; i < linha; i++)
        {
            free(c[i]);
        }
        free(c[j]);
    }
    else
    {
        printf("matriz nao alocada\n");
    }
    



    return 0;
}
