#include <stdio.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
    int i, j, k, l, x = 10, a, b, psela;
    bool chave = false;
    int verif[5][7];
    int mat[5][7] = {{8, 7, 9, 5, 6, 6, 7},
                     {1, 2, 3, 4, 5, 2, 7},
                     {3, 2, 3, 4, 5, 2, 7},
                     {2, 3, 9, 4, 6, 2, 7},
                     {5, 4, 6, 3, 8, 9, 7}};
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 7; j++)
        {
            verif[i][j] = mat[i][j];
            printf("%d ", verif[i][j]);
        }
        printf("\n");
    }
    // verifica menor elem da linha
    for (i = 0; i < 5; i++) //linha mat
    {
        for (j = 0; j < 7; j++) //coluna mat
        {
            for (k = 0; k < 7; k++) // col verif
            {
                if ((mat[i][j] < verif[i][k]) && (mat[i][j] < x)) // mat < x
                {
                    x = verif[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        for (l = 0; l < 5; l++)// verifica maior elem coluna 
        {
            if( x > mat[l][b])
            {
                psela = x;
                chave = true;
            }
        }
        if(chave == true)
        {
            printf("\nponto de sela = %d ", psela);
            printf("\n\ncoordenada = [%d][%d]\n", a, b);
            chave = false;
        }
    }

    return 0;
}