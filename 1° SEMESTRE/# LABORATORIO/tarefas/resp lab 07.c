#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int pergunta, parada = 1;
    char computador, usuario, sorteio, resposta;

    while (parada == 1)
    {
        printf("\n(r)ocha - (p)apel - (t)esoura - (l)argato - (s)pock\n");
        printf("digite a letra da opcao de usuario: ");
        srand(time(NULL));
        usuario = getchar();
        getchar();
        sorteio = rand() % 5;

        switch (sorteio)
        {
        case (0):
            computador = 'r';
            break;
        case (1):
            computador = 'p';
            break;
        case (2):
            computador = 't';
            break;
        case (3):
            computador = 'l';
            break;
        case (4):
            computador = 's';
            break;
        }

        printf("\n\tusuario = %c \n\tcomputador = %c \n", usuario, computador);

        if (computador == usuario) //empate
        {
            printf("\tempate\n");
        }
        else
        {
            if (((usuario == "t") && (computador == "p")) || ((usuario == "t") && (computador == "l")) ||
                ((usuario == "p") && (computador == "r")) || ((usuario == "p") && (computador == "s")) ||
                ((usuario == "r") && (computador == "t")) || ((usuario == "r") && (computador == "l")) ||
                ((usuario == "l") && (computador == "p")) || ((usuario == "l") && (computador == "s")) ||
                ((usuario == "s") && (computador == "t")) || ((usuario == "s") && (computador == "p")))
            {
                printf("\tusuario vence\n"); // usuario vence
            }
            else
            {
                printf("\tcomputador vence\n"); //computador vence
            }
        }
        printf("\ndeseja continuar (1=sim / 0=nao)?  ");
        scanf("%d", &pergunta);
        parada = pergunta;
        getchar();
    }
    return 0;
}
