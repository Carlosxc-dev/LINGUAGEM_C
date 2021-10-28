#include <stdio.h>
float produto(float nA, int nB)
{
    float resultado;
    if (nB==1)
    {
        resultado = nA;
    }
    else
    {
        resultado = produto(nA*nB, 1);
    }
    return resultado;
}
int main(int argc, char const *argv[])
{
    int numB;
    float numA;
    printf("digite numA: ");
    scanf("%f", &numA);
    printf("digite numB: ");
    scanf("%d", &numB);
    printf("produto de %.2f x %d = %.2f\n\n", numA, numB, produto(numA, numB));
    return 0;
}