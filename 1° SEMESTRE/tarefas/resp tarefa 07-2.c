#include <stdio.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
    int vet1[10];
    int i;
    bool chave = false;

    // atribuicao de valor ao vetor
    for (i = 0; i < 10; i++)
    {
        printf("valor do vetor na posicao [%d] = ", i);
        scanf("%d", &vet1[i]);
    }
    printf("\n");

    //verifica se maior que 50
    for (i = 0; i < 10; i++)
    {
        if (vet1[i] > 50)
        {
            printf("valor %d na posicao [%d]\n", vet1[i], i);
            chave = true;
        }
    }
    // verifica se todos sao menores que 50
    if (chave == false)
    {
        printf(" --> todos os valores sao menores que 50\n");
    }
    return 0;
}