#include <stdio.h>

int multeplicar(int num)
{
    int i, j, soma, cont;
    for (i = 1; i <= num; i++)
    {
        cont = 0;
        printf("%2d ", i);//indice num
        for (j = 1; j<i; j++)
        {
            soma = cont + i + i;// soma 
            cont += i; // incremento soma
            printf("%3d ", soma); 
        }
        printf("\n");// pula a linha
        
    }
}

int main(int argc, char const *argv[])
{
    int valor;
    printf("escreva numero de 1 a 9: ");
    scanf("%d", &valor);
    multeplicar(valor);
    return 0;
}
