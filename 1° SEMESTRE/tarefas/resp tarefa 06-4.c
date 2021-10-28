#include<stdio.h>
#include<math.h>>

int main(int argc, char const *argv[])
{
    float sjoao, sjose;
    int cont=0;

    // leitura sjoao
    printf("\nescreva salario do joao: ");
    scanf("%f", &sjoao);

    // calculo salario jose 
    sjose = sjoao/3;
    printf("\nsalario jose = %.2f\n\n", sjose);

    // dias para jose chegar ao valor de joao
    while(sjose<sjoao)
    {   
        sjose = sjose + (sjose*0.05);
        sjoao = sjoao + (sjoao*0.02);
        cont += 1;//meses
    }
    printf("Em %d meses salario do joao = jose !\n\n", cont);
    return 0;
}
