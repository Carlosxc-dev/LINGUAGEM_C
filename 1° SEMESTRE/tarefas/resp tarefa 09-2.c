#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
typedef struct
{
    char nome[30];
    int numConta;
    float saldo;
} stContaCliente;

int main(int argc, char const *argv[])
{
    int escolha, x = 0, y = 0, i, j, comp, chave = 1, aux1, pr, auxnum, k;
    float vetcomp[15], aux;
    char parada = 'n', ncli[30], aux2[10] = " ";
    stContaCliente operacao[30];

    while (parada == 'n')
    {
        printf("------banco da thaty------");
        printf("\n\t1-cadastrar\n\t2-visualizar\n\t3-excluir\n\tescolha: ");
        scanf("%d", &escolha);
        getchar();
        printf("--------------------------\n");
        switch (escolha)
        {
        case 1:          //cadstrar
            if (x <= 15) // cadastra 15 contas
            {
                printf("digite seu nome: ");
                gets(operacao[y].nome);
                pr = 1;
                while (pr == 1)
                {
                    pr = 2;
                    printf("digite Numconta: ");
                    scanf("%d", &operacao[y].numConta);
                    getchar();
                    for (k = 0; k < x; k++)
                    {
                        if (operacao[k].numConta == operacao[y].numConta)//compara num de contas iguais
                        {
                            printf("ERRO -> esse num de conta ja existe\n");
                            pr = 1;
                        }
                    }
                }
                printf("digite saldo: ");
                scanf("%f", &operacao[y].saldo);
                getchar();
                printf("cadastro feito com sucesso!\n");
                x++;
                y++;
            }
            else
            {
                printf("erro - maximo de contas 15\n");
            }
            printf("--------------------------\n");
            printf("\n");
            break;
        case 2: //visualizar
            printf("digite nome do cliente: ");
            scanf("%s", ncli);
            for (i = 0; i < x; i++)
            {
                if (strcmp(ncli, operacao[i].nome) == 0) //compara os nome contas
                {
                    printf("\nconta[%d]\n\tnum conta= %d\n\tsaldo= %.2f\n\n", i, operacao[i].numConta, operacao[i].saldo);
                }
            }
            break;
        case 3: //excluir
            printf("digite nome da conta a ser excluida: ");
            scanf("%s", ncli);
            aux = operacao[0].saldo;
            for (j = 0; j < i; j++)
            {
                if (strcmp(ncli, operacao[j].nome) == 0) //compara 2 str
                {
                    if (aux >= operacao[j].saldo) //compara
                    {
                        //aux = operacao[j].saldo;
                        //aux1 = operacao[j].numConta;
                        auxnum = j;
                    }
                }
            }
            strcpy(operacao[auxnum].nome, aux2);
            printf("excluindo...\n");
            Sleep(2000);
            printf("sua conta numero[%d]\n", operacao[auxnum].numConta);
            printf("com menor saldo de [%.2f]\nfoi excuida com sucesso!!\n", operacao[auxnum].saldo);
            break;
        default:
            printf("escolha invalida!!\n\n");
            break;
        }
        printf("deseja sair do programa ? [s/n]: ");
        scanf("%s", &parada);
        printf("\n");
        system("cls");
    }
    printf("\n\n\tvolte sempre a tathy agradece !!!\n\n");
    return 0;
}
