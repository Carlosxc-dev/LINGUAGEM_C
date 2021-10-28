#include <stdio.h>
#include <string.h>
#include <stdbool.h> // ou usar o enum
#define MAX 2
char listaseq[MAX][20];
int dispo = 0;

bool buscanome(char nome[20])
{
    int i = 0;
    while ((i < dispo) && (strcmp(listaseq[i], nome) < 0))
    {
        i++;
    }
    if ((i < dispo) && (strcmp(listaseq[i], nome) == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool inserenome(char nome[20])
{
    int i = dispo;
    if (dispo > MAX)
    {
        return false;
    }
    else
    {
        while ((i > 0) && (strcmp(listaseq[i - 1], nome) > 0))
        {
            strcpy(listaseq[i], listaseq[i-1]);
            i--;
        }
        strcpy(listaseq[i], nome);
        dispo++;
        return true;
    }
}
void imprimelista()
{
    int i ;
    for ( i = 0; i < dispo; i++)
    {
        printf("%s  ", listaseq[i]);
    }
    printf("\n");
}
bool removenome(char nome[20])
{
    int i=0;
    while ((i<dispo)&&(strcmp(listaseq[i], nome)<0))
    {
        i++;
    }
    if ((i < dispo)&&(strcmp(listaseq[i], nome)==0))
    {
        while (i<dispo-1)
        {
            strcpy(listaseq[i], listaseq[i+1]);
            i++;
        }
        dispo--;
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int i;
    char nome[20];
    for ( i = 0; i < MAX; i++)
    {
        printf("digite um nome = ");
        gets(nome);
        if (buscanome(nome) == true)
        {
            printf("nome ja encontrado\n");
            i--;
        }
        else
        {
            inserenome(nome);
        }
    }
    imprimelista();
    printf("digite um nome pra remover: ");
    gets(nome);
    if(buscanome(nome)==true)
    {
        removenome(nome);
        printf("nome removido\n");
    }
    else
    {
        printf("nome nao removido");
    }
    imprimelista();
    return 0;
}






