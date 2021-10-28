#include <stdio.h>
#include <stdbool.h> // ou enum
#include <string.h>
#define MAX 2

typedef struct no
{
    char nome[20];
    int matricula;
    float coeficiente;
    int prox;
} noaluno;

int prim = -1;
int dispo = 0;
noaluno listaAlunos[MAX];

void inicializaLista()
{
    int i;
    for (i = 0; i < MAX - 1; i++)
    {
        listaAlunos[i].prox = i + 1;
    }
    listaAlunos[i].prox = -1;
}
int buscaluno(int mat)
{
    int pos = prim;
    while ((pos != -1) && (listaAlunos[pos].matricula != mat))
    {
        pos = listaAlunos[pos].prox;
    }
    return pos;
}
bool inserealuno(noaluno aluno)
{
    int ant, atual, novo;
    if (dispo == -1)
    {
        return false;
    }
    else
    {
        ant = -1;
        atual = prim;
        novo = dispo;
        while ((atual!=-1)&&(listaAlunos[atual].matricula)<aluno.matricula)
        {
            ant = atual;
            atual = listaAlunos[atual].prox;
        }
        dispo = listaAlunos[dispo].prox;
        if (ant==-1)
        {
            prim = novo;
        }
        else
        {
            listaAlunos[ant].prox = novo;
        }
        strcpy(listaAlunos[novo].nome, aluno.nome);
        listaAlunos[novo].matricula = aluno.matricula;
        listaAlunos[novo].coeficiente = aluno.coeficiente;
        listaAlunos[novo].prox = atual;
        return true;
    }
}
void imprimeLista()
{
    int pos = prim;
    printf("\n\n");
    while (pos != -1)
    {
        printf("nome = %s\n", listaAlunos[pos].nome);
        printf("matricula = %d\n", listaAlunos[pos].matricula);
        printf("coeficiente = %f\n", listaAlunos[pos].coeficiente);
        printf("proximo = %d\n", listaAlunos[pos].prox);
        pos = listaAlunos[pos].prox;
    }
    printf("\n\n");
}
bool removealuno(int mat)
{
    int ant, atual;
    ant = -1;
    atual = prim;

    while ((atual != -1)&&(listaAlunos[atual].matricula != mat))
    {
        ant = atual;
        atual = listaAlunos[atual].prox;
    }
    if (atual == -1)
    {
        return false;
    }
    else
    {
        if (ant == -1)
        {
            prim = listaAlunos[atual].prox;
        }
        else
        {
            listaAlunos[ant].prox = listaAlunos[atual].prox;
        }
        listaAlunos[atual].prox = dispo;
        dispo = atual;
        return true;
    }
}

int main(int argc, char *argv[])
{
    int i, mat;
    noaluno aux;

    inicializaLista();
    for (i = 0; i < MAX; i++)
    {
        printf("digite nome: ");
        scanf("%s", aux.nome);
        printf("digite a mtricula: ");
        scanf("%d", &aux.matricula);
        printf("digite coeficiente: ");
        scanf("%f", &aux.coeficiente);

        if (buscaluno(aux.matricula) == -1)
        {
            inserealuno(aux);
        }
        else
        {
            i--;
        }
    }
    imprimeLista();

    printf("matricula a ser removida: ");
    scanf("%d", &mat);
    if (buscaluno(mat)!=-1)
    {
        removealuno(mat);
    }
    else
    {
        printf("matricula nao encontrada \n");
    }
    imprimeLista();
    return 0;
}
