#include<stdio.h>

int menorelem(int matriz[6][6])
{
    int i, j, menor;
    menor = matriz[0][5];
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            if(i + j == 5)
            {
                if(matriz[i][j] < menor)
                {
                    menor = matriz[i][j];
                }
            }
        }
    }
    return menor;
}

int main(int argc, char const *argv[])
{
    int i, j, sorteio, mat[6][6], resp;
    srand(time(NULL)); // sorteios diferentes
    
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            mat[i][j] = rand() % 10;
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    resp = menorelem(mat);
    printf("menor elemento = %d\n\n", resp);
    return 0;
}
