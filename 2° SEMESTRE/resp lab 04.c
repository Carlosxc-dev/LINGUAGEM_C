#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> //ou typedef


typedef struct no
{
    int matricula;
    char nome[20], diciplina[20];
    float coef;
    struct no *prox;
} noaluno;

noaluno *prim = NULL;

int buscaaluno(int mat)
{
    int i = 0;
    noaluno *atual = prim;
    while ((atual != NULL) && (atual->matricula != mat))
    {
        atual = atual->prox;
        i++;
    }
    if (atual == NULL)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

bool inserealuno(noaluno info)
{
    noaluno *ant = NULL;
    noaluno *atual = prim;

    noaluno *novo = (noaluno *)malloc(sizeof(noaluno));

    while ((atual != NULL) && (atual->matricula < info.matricula))
    {
        ant = atual;
        atual = atual->prox;
    }
    // insere primeira posicao
    if (ant == NULL)
    {
        prim = novo;
    }
    else // insere qualquer posicao
    {
        ant->prox = novo;
    }
    novo->matricula = info.matricula;
    strcpy(novo->nome, info.nome);
    strcpy(novo->diciplina, info.diciplina);
    novo->coef = info.coef;
    novo->prox = atual;
    return true;
}

bool removeAluno(int mat)
{
    noaluno *ant = NULL;
    noaluno *atual = prim;

    while ((atual != NULL) && (atual->matricula != mat))
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL)
    {
        return false;
    }
    else
    {
        if (atual == prim)
        {
            prim = atual->prox;
        }
        else
        {
            ant->prox = atual->prox;
        }
        free(atual);
        return true;
    }
}

void imprimelista()
{
    noaluno *atual = prim;

    while (atual != NULL)
    {
        printf("\n");
        printf("matricula = %d\n", atual->matricula);
        printf("nome aluno  = %s\n", atual->nome);
        printf("diciplina = %s\n", atual->diciplina);
        printf("coeficiente = %f\n", atual->coef);
        atual = atual->prox;
    }
    printf("\n");
}

void distroilista()
{
    noaluno *atual = prim;
    noaluno *apaga;

    while (atual != NULL)
    {
        apaga = atual;
        atual = atual->prox;
        free(apaga);
    }
}

int main(int argc, char const *argv[])
{
    int opcao, mat;
    noaluno info;

    do
    {
        printf("01 - inseri aluno\n");
        printf("02 - remove aluno\n");
        printf("03 - imprimir lista\n");
        printf("0 - sair \n");
        printf("qual opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("matricula: ");
            scanf("%d", &info.matricula);
            getchar();
            if (buscaaluno(info.matricula) == -1)
            {
                printf("nome aluno = ");
                gets(info.nome);
                printf("diciplina: ");
                gets(info.diciplina);
                printf("coeficiente: ");
                scanf("%f", &info.coef);
                getchar();
                if (inserealuno(info) == true)
                {
                    printf("aluno inserido na lista com sucesso\n");
                }
                else
                {
                    printf("problemas com insercao\n");
                }
            }
            else
            {
                printf("matricula nao cadastrada\n");
            }
            break;
        case 2:
            printf("matricula a ser removida : ");
            scanf("%d", &mat);
            if (buscaaluno(mat) != -1)
            {
                removeAluno(mat);
                printf("matricula removida com sucesso\n");
            }
            else
            {
                printf("matricula nao encontrada\n");
            }
            break;
        case 3:
            imprimelista();
            break;
        }
    } while (opcao != 0);
    distroilista();
    return 0;
}
