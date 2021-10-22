#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no
{
    char titulo[30];
    char autor[30];
    int ano;
    char editor[30];
    char classificacao[30];
} st_livros;

int main(int argc, char const *argv[])
{
    int i, j, quant = 0;
    st_livros **v;

    printf("quantidade de livros: ");
    scanf("%d", &quant);
    // alocando quant livros
    for (i = 0; i < quant; i++)
    {
        v[i] = (st_livros **)malloc(quant*sizeof(st_livros));
    }
    for (i = 0; i < quant; i++)
    {
        v[i] = (st_livros *)malloc(sizeof(st_livros));
    }
    // leitura dos dados dos livros
    for (i = 0; i < quant; i++)
    {
        printf("titulo = ");
        scanf("%s", v[i]->titulo);
        printf("auto = ");
        scanf("%s", v[i]->autor);
        printf("ano = ");
        scanf("%d", &v[i]->ano);
        printf("editora = ");
        scanf("%s", v[i]->editor);
        printf("classificacao = ");
        scanf("%s", v[i]->classificacao);
        printf("\n\n");
    }
    // impressao dos dados do livro
    for (i = 0; i < quant; i++)
    {
        printf("livro = %d\n\n", i);
        printf("titulo = %s\n", v[i]->titulo);
        printf("auto = %s\n", v[i]->autor);
        printf("editora = %s\n", v[i]->editor);
        printf("classificacao = %s\n", v[i]->classificacao);
        printf("ano = %d\n\n", v[i]->ano);
    }
    for (i = 0; i < quant; i++)
    {
        free(v[i]);
    }
    free(v);
    return 0;
}
