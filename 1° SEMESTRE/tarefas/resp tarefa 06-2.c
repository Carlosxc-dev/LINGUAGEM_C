#include<stdio.h>   
#include<math.h>

int main(int argc, char const *argv[])
{
    float conta,x, y; 
    int num;

    printf("escreva num x: ");
    scanf("%f", &x);
    printf("escreva num y: ");
    scanf("%f", &y);
    printf("\ndigite 1 para elevar x a y\n");
    printf("digite 2 para raiz quadrada de x e y\n");
    printf("digite 3 para raiz cubica de x e y\n");
    printf("resposta:  ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        conta = pow(x,y);
        printf("%.2f elevado a %.2f = %.2f", x, y, conta);
        break;
    
    case 2:
        printf("raiz quadrada de %.2f = %.2f\n", x, sqrt(x));
        printf("raiz quadrada de %.2f = %.2f\n", y, sqrt(y));
        break;
    
    case 3:
        printf("raiz cubica de %.2f = %.2f\n", x, cbrt(x));
        printf("raiz cubica de %.2f = %.2f\n", y, cbrt(y));
        break;
    
    default:
        printf("opcao invalida, digite um valor valido\n");
        break;
    }
    return 0;
}
