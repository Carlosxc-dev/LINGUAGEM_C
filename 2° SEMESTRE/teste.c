#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct no
{
    char nome[20];
    int cpf;
    struct no *prox;
    struct no *ant;
} cadastro;

*prim = NULL;
*ult = NULL;

bool insere(char nome[20], int cpf)
{
    cadastro *atual = prim;
    cadastro *aux = NULL;
    cadastro *novo = (cadastro *)malloc(sizeof(cadastro));

    while ((atual != NULL) && (strcmp(atual->nome, nome) != 0))
    {
        aux = atual;
        atual = atual->prox;
    }

    if (aux == NULL)
    {
        prim = novo;
    }
    else
    {
        aux->prox = novo;
    }

    if (atual != NULL)
    {
        atual->ant = novo;
    }

    //inserrir os elem
    strcpy(novo->nome, nome);
    novo->cpf = cpf;
    novo->prox = atual;
    novo->ant = aux;

    return true;
}

void imprime(){
    cadastro *atual = ult;

    while(atual != NULL){
        printf("nome = %s\ncpf = %d\n\n", atual->nome, atual->cpf);
        atual = atual->ant;
    }

}

int main(int argc, char *argv[])
{
    cadastro dados;
    int op;

    do
    {
        printf("1-inserir dados\n2-imprimir dados\n3-sair\nopcao= ");
        scanf("%d", &op);
        printf("\n");

        switch (op)
        {
        case 1:
            printf("nome = ");
            scanf("%s", dados.nome);

            printf("cpf = ");
            scanf("%d", &dados.cpf);

            if (insere(dados.nome, dados.cpf) == true)
            {
                printf("inserido com sucesso\n");
            }
            else
            {
                printf("nao inserido");
            }

            break;
        case 2:
            imprime();
            break;
        case 3:
            op = 0;
            break;

        default:
            printf("opcao invalida");
            break;
        }

    } while (op != 0);

} //end main
