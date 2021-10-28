#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int *v = NULL;
    int  num, i;

    srand(time(NULL));
    printf("digite um numero inteiro: ");
    scanf("%d", &num);

    if (v == NULL)
    {
        v = (int * )malloc(num*sizeof(int));
    }
    else
    {
        printf("vetor ja alocado");
    }
    for ( i = 0; i < num; i++)
    {
        v[i] = rand()%100+1;
        printf(" %d ", v[i]);
    }
    printf("\n");
    if (v != NULL)
    {
        free(v);
        printf("liberando vetor!!");
    }
    else
    {
        printf("vetor nao existe!!!");
    }
    
    free(v);
    return 0;
}
