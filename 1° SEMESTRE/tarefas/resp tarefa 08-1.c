#include<stdio.h>

int soma(int num1, int num2)
{
    int i, soma=0;
    for(i = num1+1; i < num2; i++) 
    {
        soma += i;
    }
    return soma;
}
int main(int argc, char const *argv[])
{
    int n1, n2, resp;
    printf("escreva 2 numeros: ");
    scanf("%d %d", &n1, &n2);
    resp = soma(n1, n2);
    printf("\nA soma dos n numeros = %d\n", resp);
    return 0;
}
