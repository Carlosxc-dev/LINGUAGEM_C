#include<stdio.h>

int main(int argc, char const *argv[])
{
    int codcarga, codestado, pesocarga, preco;
    float imposto;
 
    printf("\nescreva codigo do estado(1 a 5): ");
    scanf("%d", &codestado);
    printf("escreva peso da carga(tonelada): ");
    scanf("%d", &pesocarga);
    printf("escreva codigo da carga(10 a 40): ");
    scanf("%d", &codcarga);

    // calculo peso da carga
    pesocarga = pesocarga * 1000;
    printf("\npeso em kg = %d\n\n", pesocarga);

    //calculo preço da carga e valor da carga
    if((codcarga>=10)&&(codcarga<=20))
    {
        printf("preco 100/kg\n");
        preco = pesocarga * 100;
        printf("valor da carga = %d\n\n", preco);
    }
    else
    {
        if((codcarga>=21)&&(codcarga<=30))
        {
            printf("preco 250/kg\n");
            preco = pesocarga * 250;
            printf("valor da carga = %d\n\n", preco);
        }
        else
        {
            if((codcarga>=31)&&(codcarga<=40))
            {
                printf("preco 340/kg\n");
                preco = pesocarga * 340;
                printf("valor da carga = %d\n\n", preco);
            }
            else
            {
                printf("opcao invalida !!!\n\n");
            }
        }
    }

    //imposto
    switch (codestado)
    {
    case 1:
        printf("imposto e 35%% da carga\n");
        imposto = preco * 0.35;
        printf("valor da imposto = %.2f\n\n", imposto);
        break;
    case 2:
        printf("imposto e 25%% da carga\n");
        imposto = preco * 0.25;
        printf("valor da imposto = %.2f\n\n", imposto);
        break;
    case 3:
        printf("imposto e 15%% da carga\n");
        imposto = preco * 0.15;
        printf("valor da imposto = %.2f\n\n", imposto);
        break;
    case 4:
        printf("imposto e 5%% da carga\n");
        imposto = preco * 0.05;
        printf("valor da imposto = %.2f\n\n", imposto);
        break;
    default:
        printf("insento de imposto\n\n");
        break;
    }

    //valor total
    printf("valor total tranportado = %.2f\n\n", (imposto+preco));

    return 0;
}




