#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM_NOME 20
#define TAM_TELEFONE 20

typedef struct NO
{
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    struct no *ant;
    struct no *prox;
} nocontato;

nocontato *prim = NULL;

int buscacontato(char tel[TAM_TELEFONE])
{
    int i = 0;
    nocontato *atual = prim;

    while ((atual != NULL) && (strcmp(atual->telefone, tel) != 0))
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

bool inserecontato(nocontato *novo)
{
    nocontato *aux = NULL;
    nocontato *atual = prim;
    int i;

    while ((atual != NULL) && (strcmp(atual->nome, novo->nome) < 0))
    {
        aux = atual;
        atual = atual->prox;
    }
    if (aux == NULL) // insere primeira posicao
    {
        prim = novo;
    }
    else
    {
        aux->prox = novo; //insere qualquer posicao
    }
    novo->ant = aux;
    novo->prox = atual;
    if (atual != NULL)
    {
        atual->ant = novo;
    }
    return true;
}

void imprimelista()
{
    nocontato *atual = prim;

    while (atual != NULL)
    {
        printf("\n");
        printf("nome = %s\n", atual->nome);
        printf("telefone  = %s\n", atual->telefone);
        atual = atual->prox;
    }
    printf("\n");
}

bool removecontato(char tel[TAM_TELEFONE])
{
    nocontato *aux = NULL;
    nocontato *atual = prim;

    while ((atual != NULL) && strcmp(atual->telefone,tel) != 0)
    {
        aux = atual;
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
            aux->prox = atual->prox;
        }
        free(atual);
        return true;
    }
}

void destroicontato()
{
    nocontato *atual = prim;
    nocontato *apaga;

    while (atual != NULL)
    {
        apaga = atual;
        atual = atual->prox;
        free(apaga);
    }
}

int main(int argc, char const *argv[])
{
    int op;
    char tel[TAM_TELEFONE];
    nocontato *aux;

    do
    {
        printf("\n");
        printf("1- inserir contato\n");
        printf("2- remover contato\n");
        printf("3- imprimir lista\n");
        printf("4- sair\n");
        printf("\n");
        printf("digite a opcao: ");
        scanf("%d", &op);
        getchar();
        printf("\n");

        switch (op)
        {
        case 1:
            aux = (nocontato *)malloc(sizeof(nocontato));
            printf("nome contato = ");
            gets(aux->nome);
            printf("telefone contato = ");
            gets(aux->telefone);
            if (buscacontato(aux->telefone) == -1)
            {
                inserecontato(aux);
                printf("contato inserido com sucesso\n");
            }
            else
            {
                free(aux);
                printf("contato ja existe\n");
            }
            break;
        case 2:
            printf("numero contato a ser removido = ");
            gets(tel);
            if (buscacontato(tel) != -1)
            {
                removecontato(tel);
                printf("contato removido com sucesso\n");
            }
            else
            {
                printf("contato nao encontrado = \n");
            }
            break;
        case 3:
            imprimelista();
            break;
        case 4:
            printf("digite 4 para sair\n");
            break;
        }
    } while (op != 4);
    
    destroicontato();

    return 0;
}
