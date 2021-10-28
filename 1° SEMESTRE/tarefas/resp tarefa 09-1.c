#include <stdio.h>
#include <stdlib.h>

struct stDadosPessoa
{
    char nome[30], sexo[2];
    int cpf;
    float altura, peso;
};

int main(int argc, char const *argv[])
{
    int i, j, cpfdesejado, resp, x;
    float imc;
    struct stDadosPessoa vet[30];

    for (i = 0; i < 30; i++)
    {
        printf("digite seu nome: ");
        scanf("%s", &vet[i].nome);
        getchar();
        printf("digite seu sexo: ");
        scanf("%c", &vet[i].sexo);
        getchar();
        printf("digite seu cpf: ");
        scanf("%d", &vet[i].cpf);
        getchar();
        printf("digite sua [altura peso]: ");
        scanf("%f %f", &vet[i].altura, &vet[i].peso);
        getchar();
        printf("\n");
        printf("deseja continuar sim[0]/nao[1]: ");
        printf("\n");
        scanf("%d", &resp);
        if (resp == 1)
        {
            i = 30;
        }
    }
    system("cls");
    resp = 0;
    while (resp == 0)
    {
        printf("\ndigite cpf da pessoa desejada: ");
        scanf("%d", &cpfdesejado);
        for (j = 0; j < i; j++)
        {
            if (cpfdesejado == vet[j].cpf)
            {
                imc = vet[j].peso / (vet[j].altura * vet[j].altura);
                printf("nome = %s\n", vet[j].nome);
                printf("sexo = %s\n", vet[j].sexo);
                printf("cpf = %d\n", vet[j].cpf);
                printf("imc = %.2f\n", imc);
                x = 1;
            }
        }
        if (x == 0)
        {
            printf("cpf nao existe no banco de dados\n\n");
        }
        x = 0;
        printf("deseja continuar sim[0]/nao[1]: ");
        scanf("%d", &resp);
        if (resp == 1)
        {
            resp = 1;
        }
    }
    return 0;
}
