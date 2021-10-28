#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char nome[20];
    int num;
    struct no *prox;
}t_aluno;


int main(int argc, char *argv[])
{
    t_aluno *cadastro; 
    t_aluno *aux;

    cadastro = (t_aluno*) malloc(sizeof(t_aluno));


    strcpy(cadastro->nome, "carlos");
    cadastro->num = 10;
    cadastro->prox = aux;
    aux = cadastro;

    printf("%d %s %d", cadastro->num, cadastro->nome, cadastro->prox);



} //end main
