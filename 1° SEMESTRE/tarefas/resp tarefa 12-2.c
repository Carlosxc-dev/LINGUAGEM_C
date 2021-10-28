#include <stdio.h>
#include <stdlib.h>
int soma(int n1, int aux, int x)
{
    int resultado;
    if (x==n1+1)// n1+1 fazer soma ultimo numero
    {
        resultado = aux;// resultado retorno
    }
    else
    {
        resultado = soma(n1, aux+x, x+1);
    }
    return resultado;
}
int main(int argc, char const *argv[])
{
    int num1, rsoma, aux=0, x=0;
    printf("digite um numero: ");
    scanf("%d", &num1);
    printf("soma de 0 ate %d = %d\n\n", num1, soma(num1, aux, x));
    return 0;
}