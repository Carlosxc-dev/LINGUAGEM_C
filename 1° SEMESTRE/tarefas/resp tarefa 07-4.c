#include <stdio.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
    int mat[10][10], troc[10][2], vet[10];
    int i, j, x = 10, a, b;
    bool chave = false;
    srand(time(NULL));

    // impresao matriz inicial
    printf("     matriz de referencia \n");
    printf("   0  1  2  3  4  5  6  7  8  9\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", i);
        for (j = 0; j < 10; j++)
        {
            mat[i][j] = rand() % 10; // sorteio matriz inicial
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // troca linha 2 pela 8
    printf("troca da linha 2 pela 8 \n");
    printf("   0  1  2  3  4  5  6  7  8  9\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", i);
        for (j = 0; j < 10; j++)
        {
            a = mat[2][j];
            b = mat[8][j];
            mat[2][j] = b;
            mat[8][j] = a;

            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // troca coluna 3 pela 9
    printf("troca da coluna 3 pela 9 \n");
    printf("   0  1  2  3  4  5  6  7  8  9\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", i);
        for (j = 0; j < 10; j++)
        {
            if (j == 3)
            {
                troc[i][j] = mat[i][3];
                mat[i][3] = mat[i][9];
                mat[i][9] = troc[i][j];
            }
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // troca diagonais
    printf("troca das diagonais \n");
    printf("   0  1  2  3  4  5  6  7  8  9\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", i);
        for (j = 0; j < 10; j++)
        {
            if (i == j)
            {
                x--;
                vet[j] = mat[i][j];
                mat[i][j] = mat[i][x];
                mat[i][x] = vet[j];
            }
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;
}