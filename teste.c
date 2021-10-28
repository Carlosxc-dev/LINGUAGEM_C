#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> //ou typedef


typedef struct no{
    int num;
    struct no *prox;
} lista;

lista *prim = NULL;

// insere na lista 
void insere(int valor){
    lista *novo, *atual=prim;

    novo = (lista*)malloc(sizeof(lista));

    while (atual != NULL)
    {
        atual = atual->prox;
    }
    if (atual==NULL)
    {
        prim = novo;
    }else{
        atual = NULL;
    }
    novo->num = valor;
    novo->prox = atual;

}

int main(int argc, char const *argv[])
{
    int valor;


    printf("fala o valor: ");    
    scanf("%d", &valor);

    
    insere(valor);



    return 0;
}

