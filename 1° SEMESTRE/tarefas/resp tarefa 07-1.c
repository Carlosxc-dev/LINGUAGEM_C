#include <stdio.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
    int i, j, x;
    int vet1[5] = {1, 2, 3, 4, 5};
    int vet2[5] = {4, 5, 6, 7, 8};
    int vet3[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool chave = true;

    //impresao dos vetore 1 e 2
    printf("vet1\t= ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vet1[i]);
    }
    printf("\n\n");
    printf("vet2\t= ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vet2[i]);
    }
    printf("\n\n");

    // uniao
    printf("uniao\t= ");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (vet1[i] == vet2[j]) // verifica se vet1 == vet2
            {
                break;
            }
        }
        vet3[i] = vet1[i];      // guarda vet1 no vet3              {1, 2, 3, 4, 5};
        printf("%d ", vet3[i]); // imprime vet3 ( vet1 )            {4, 5, 6, 7, 8};
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (vet2[i] == vet3[j]) // verifica vet2 == vet3
            {
                break;
            }
        }
        if (j == 5)
        {
            printf("%d ", vet2[i]); // imprime vet2 se != vet3
        }
    }
    printf("\n\n");

    // soma
    printf("soma\t= ");
    for (i = 0; i < 5; i++)
    {
        x = vet1[i] + vet2[i];//soma 1 com 2 
        printf("%d ", x);
    }
    printf("\n\n");

    // produto
    printf("produto\t= ");
    for (i = 0; i < 5; i++)
    {
        x = vet1[i] * vet2[i];// multeplicacao de 1 com 2 
        printf("%d ", x);
    }
    printf("\n\n");


    return 0;
}
