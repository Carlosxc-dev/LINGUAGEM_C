#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
    char nome[30], sexo[2]; // sexo ultimo /0
    int idade;
    float altura, peso;
} stPaciente;

int main(int argc, char const *argv[])
{
    int i, j, aux;
    char nome[30];
    float auxpeso, auxpeso1;
    stPaciente cliente[20];

    for (i = 0; i < 2; i++) // cadastro
    {
        printf("digite seu nome: ");
        gets(cliente[i].nome); // nomes com spaco usar gets
        printf("digite idade: ", cliente[i].nome);
        scanf("%d", &cliente[i].idade);
        getchar();
        printf("digite sexo: ");
        scanf("%s", &cliente[i].sexo);
        printf("digite altura: ");
        scanf("%f", &cliente[i].altura);
        getchar();
        printf("digite peso: ");
        scanf("%f", &cliente[i].peso);
        getchar();
        printf("\n");
    }
    auxpeso1 = cliente[0].peso; // inicializar comparacao
    for (j = 0; j < i; j++)
    {
        if (auxpeso1 <= cliente[j].peso) // verifica mais pesado
        {
            auxpeso1 = cliente[j].peso;
            aux = j;
        }
    }
    printf("%s e o mais pesado\n\n", cliente[aux].nome);
    for (j = 0; j < i; j++) // acima peso ideal
    {
        if (strcmp(cliente[j].sexo, "m") == 0) //sexo m
        {
            if (((72.7 * cliente[j].altura) - 58) < cliente[j].peso) // acima peso ideal m
            {
                printf("%s com  %d anos esta acima do peso\n\n", cliente[j].nome, cliente[j].idade);
            }
        }
        else if (strcmp(cliente[j].sexo, "f") == 0) //sexo f
        {
            if (((62.1 * cliente[j].altura) - 44.7) < cliente[j].peso) // acima peso ideal f
            {
                printf("%s com  %d anos esta acima do peso\n\n", cliente[j].nome, cliente[j].idade);
            }
        }
        else
        {
            printf("nao ha niguem acima do peso ideal\n\n");
        }
    }
    for (j = 0; j < i; j++) // abixo peso ideal
    {
        if (strcmp(cliente[j].sexo, "m") == 0) //sexo m
        {
            if (((72.7 * cliente[j].altura) - 58) > cliente[j].peso) // abaixo peso ideal m
            {
                auxpeso = (72.7 * cliente[j].altura) - 58;
                printf("%s voce deve ficar com %.2f kg para estar no peso ideal\n\n", cliente[j].nome, auxpeso);
            }
            else
            {
                printf("nao ha niguem abaixo do peso ideal\n\n");
            }
        }
        else if (strcmp(cliente[j].sexo, "f") == 0) //sexo f
        {
            if (((62.1 * cliente[j].altura) - 44.7) > cliente[j].peso) // abaixo peso ideal m
            {
                auxpeso = (62.1 * cliente[j].altura) - 44.7;
                printf("%s voce deve ficar com %.2f kg para estar no peso ideal\n\n", cliente[j].nome, auxpeso);
            }
            else
            {
                printf("nao ha niguem abaixo do peso ideal\n\n");
            }
        }
    }
    return 0;
}
