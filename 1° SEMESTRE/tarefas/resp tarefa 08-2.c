#include <stdio.h>

float percentual(int valori, int valorf)
{
    return ((valorf * 100) / valori) - 100;
}

int main(int argc, char const *argv[])
{
    float antigo, atual, resp;
    printf("escreva valor antigo: ");
    scanf("%f", &antigo);
    printf("escreva valor atual: ");
    scanf("%f", &atual);
    resp = percentual(antigo, atual);
    if (atual < antigo)
    {
        resp = resp + 100;
        printf("decrecimo = %.2f %%", resp);
    }
    else
    {
        printf("acrecimo = %.2f %%", resp);
    }

    return 0;
}