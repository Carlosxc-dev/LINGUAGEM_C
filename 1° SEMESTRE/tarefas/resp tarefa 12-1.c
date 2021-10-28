#include <stdio.h>
#include <stdlib.h>
int multiplica(int n1, int n2, int aux)// aux == n1
{
    int resultado;
    if (n2==1)
    {
        resultado = n1;
    }
    else
    {
        resultado = multiplica(n1+aux, n2-1, aux);
    }
    return resultado;
}
int main(int argc, char const *argv[])
{
    int num1, num2, rsoma, aux;
    printf("digite o valores[n1 n2]: ");
    scanf("%d %d", &num1, &num2);
    aux = num1;
    printf("multeplicacao de %d por %d = %d\n\n", num1, num2, multiplica(num1, num2, aux));
    return 0;
}
