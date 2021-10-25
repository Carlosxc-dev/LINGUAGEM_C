#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    int valor;
    struct no *prox;
} nocedula;

nocedula *pilha[7]; // pilha com 2 valores

int valornota[7] = {1, 2, 5, 10, 20, 50, 100};

void inicializapilha()
{
    int i;
    for (i = 0; i < 7; i++)
    {
        pilha[i] = NULL;
    }
}
void abastecePilha(int v, int quant)
{
    int i;
    int pos; //posicao da pilha a ser inserido o valor
    nocedula *novo;
    switch (v)
    {
    case 1:
        pos = 0;
        break;
    case 2:
        pos = 1;
        break;
    case 5:
        pos = 2;
        break;
    case 10:
        pos = 3;
        break;
    case 20:
        pos = 4;
        break;
    case 50:
        pos = 5;
        break;
    case 100:
        pos = 6;
        break;
    default:
        printf("valor de cedula inválido\n");
    } //end switch
    for (i = 0; i < quant; i++)
    {
        //aloca a cedula na memória
        novo = (nocedula *)malloc(sizeof(nocedula));
        //mudar o valor da cedula para o valor recebido
        novo->valor = v;
        //adiciona como primeiro elemento da pilha[pos]
        novo->prox = pilha[pos];
        pilha[pos] = novo;
    } //end for
} //end abastecePilha
void imprimeSaldo()
{
    nocedula *atual;
    int i, soma = 0;
    //para cada pilha
    for (i = 0; i < 7; i++)
    {
        atual = pilha[i];
        //percorre cada pilha
        while (atual != NULL)
        {
            //acumulando a soma
            soma += atual->valor;
            //proximo elemento
            atual = atual->prox;
        } //end while
    }     //end for
    printf("\nsaldo = %d\n\n", soma);
} //end imprimeSaldo
void imprimeSomaCedulas()
{
    nocedula *atual;
    int i, soma = 0;
    //para cada pilha
    for (i = 0; i < 7; i++)
    {
        atual = pilha[i];
        soma = 0;
        //percorre cada pilha
        while (atual != NULL)
        {
            //acumulando a soma
            soma += atual->valor;
            //proximo elemento
            atual = atual->prox;
        } //end while
        printf("saldo em notas de %d = %d\n", valornota[i], soma);
    } //end for
    printf("\n");
} //end imprimeSomaCedulas
bool saquedisponivel(int valor)
{
    int i;
    nocedula *atual;
    for (i = 6; i >= 0; i--)
    {
        atual = pilha[i]; //inicio de pilha
        //enquanto tem elementos na pilha e
        //enquanto eh possivel dividir o valor pelo valor das cedulas
        while ((atual != NULL) && ((valor / valornota[i]) >= 1))
        {
            //decrementa o valor
            valor -= valornota[i];
            //proximo elemento da pilha
            atual = atual->prox;
        } //end while
    }     //end for
    if (valor == 0)
    {
        return true;
    }
    else
    {
        return false;
    } //end else
} //end saqueDisponivel
bool saque(int valor)
{
    int i;
    nocedula *atual;
    if (saquedisponivel(valor) == true)
    {
        for (i = 6; i >= 0; i--)
        {
            //enquanto tem elementos na pilha e
            //enquanto eh possível dividir o valor pelo valor das cedulas
            while ((pilha[i] != NULL) && ((valor / valornota[i]) >= 1))
            {
                //decrementa o valor
                valor -= valornota[i];
                //pegando o elemento a ser removido da pilha
                atual = pilha[i];
                //mundando o novo primeiro da pilha
                pilha[i] = pilha[i]->prox;
                //apagando atual
                free(atual);
            } //end while
        }     //end for
        return true;
    }
    else
    {
        return false;
    } //end else
} //end saque
void destroipilha()
{
    nocedula *atual;
    int i;
    while (atual != NULL)
    {
        atual = pilha[i];
        free(atual);
        pilha[i] = pilha[i]->prox;
    }
}

int main(int argc, char const *argv[])
{
    int valor, quant, opcao, aux = 0;

    inicializapilha();
    abastecePilha(100, 80);
    abastecePilha(50, 70);
    abastecePilha(20, 150);
    abastecePilha(10, 200);
    abastecePilha(5, 30);
    abastecePilha(2, 55);
    abastecePilha(1, 100);

    while (aux != 1)
    {

        printf("1- abastecer, 2- imprimir, 3- saque, 4- sair, opcao = ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("digite [valorNota quant] = ");
            scanf("%d %d", &valor, &quant);
            abastecePilha(valor, quant);
            imprimeSaldo();
            break;
        case 2:
            imprimeSaldo();
            printf("\n");
            break;
        case 3:
            printf("digite valor = ");
            scanf("%d", &valor);
            if (saquedisponivel(valor) == true)
            {
                saque(valor);
                printf("\nsaque disponivel!!\n");
                imprimeSaldo();
                printf("\n");
            }
            else
            {
                printf("ERRO - sem saldo !!\n");
            }
            break;
        case 4:
            //imprimeSomaCedulas();
            destroipilha();
            aux = 1;
            break;
        default:
            printf("ERRO - opcao invalida");
            break;
        }
        imprimeSomaCedulas();
    }

    return 0;
}
