#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum
{
	NENHUM,
	EMPRESA,
	SORTEREVES,
	PRISAO,
	TERRENO
} enum_tipo;
typedef enum
{
	NINGUEM,
	JOGADOR1,
	JOGADOR2
} enum_dono;
typedef struct
{
	enum_tipo tipo;
	int preco;
	enum_dono dono;
} struct_casa;
struct_casa tab[30];
void inicializa()
{
	int i;
	for (i = 0; i < 30; i++)
	{
		tab[i].dono = NINGUEM;
		tab[i].preco = 0;
		tab[i].tipo = NENHUM;
	}

} //end inicializa
void geratabuleiro()
{
	int i, sort;
	for (i = 0; i < 10; i++) //10 prisoes
	{
		sort = rand() % 30;
		if (tab[sort].tipo == NENHUM)
		{
			tab[sort].tipo = EMPRESA;
			tab[sort].preco = rand() % 11 + 10;
		}
		else
		{
			i--;
		}
	}
	for (i = 0; i < 5; i++) // 5 sortereves
	{
		sort = rand() % 30;
		if (tab[sort].tipo == NENHUM)
		{
			tab[sort].tipo = SORTEREVES;
			tab[sort].preco = (rand() % 19) - 9;
		}
		else
		{
			i--;
		}
	}
	for (i = 0; i < 2; i++) //sorteia 2 prisoes
	{
		sort = rand() % 30;
		if (tab[sort].tipo == NENHUM)
		{
			tab[sort].tipo = PRISAO;
			tab[sort].preco = -9;
		}
		else
		{
			i--;
		}
	}
	for (i = 0; i < 30; i++)// terreno recebe se tiver nenhum
	{
		if (tab[i].tipo == NENHUM)
		{
			tab[i].tipo = TERRENO;
			tab[i].preco = rand() % 11;
		}
	}

} //end geratabuleiro
void mostra(int j1, int j2) //mostra
{
	int i;
	for ( i = 0; i < 30; i++)
	{
		switch (tab[i].tipo)
		{
		case EMPRESA:
			printf(" EM ");
			break;
		case SORTEREVES:
			printf(" ?? ");
			break;
		case TERRENO:
			printf(" TE ");
			break;
		case PRISAO:
			printf(" ## ");
			break;
		}
	}
	printf("\n");
	for ( i = 0; i < 30; i++)
	{
		printf(" %2d ", tab[i].preco);
	}
	printf("\n");
	for ( i = 0; i < 30; i++)
	{
		if ((i==j1)&&(i==j2))
		{
			printf("[l2]");
		}
		else
		{
			if (i==j1)
			{
				printf("[j1]");
			}
			else
			{
				if (i==j2)
				{
					printf("[j2]");
				}
				else
				{
					printf("[  ]");
				}	
			}	
		}		
	}
	printf("\n");
} 

int main(int argc, char *argv[])
{
	int i, dado, pos1 = 0, pos2 = 0, saldo1 = 100, saldo2 = 100;
	srand(time(NULL)); // numeros sorteados diferentes
	inicializa();
	geratabuleiro();
	while (saldo1 > 0 && saldo2 > 0)
	{
		dado = (rand() % 3) + 1;
		pos1 = (pos1 + dado) % 30;
		if (tab[pos1].tipo==TERRENO)
		{
			if (tab[pos1].dono==NINGUEM)
			{
				if (rand()%2==0)
				{
					saldo1-=tab[pos1].preco;
					tab[pos1].dono=JOGADOR1;
				}
			}
			if (tab[pos1].dono==JOGADOR2)
			{
				saldo1-=tab[pos1].preco;
				saldo2+=tab[pos1].preco;
				
			}
		}
		if (tab[pos1].tipo==EMPRESA)
		{
			if (tab[pos1].dono==NINGUEM)
			{
				if (rand()%2==0)
				{
					saldo1-=tab[pos1].preco;
					tab[pos1].dono=JOGADOR1;
				}
			}
			if (tab[pos1].dono==JOGADOR2)
			{
				saldo1-=tab[pos1].preco*dado;
				saldo2+=tab[pos1].preco*dado;
			}
		}
		if ((tab[pos1].tipo==PRISAO)||(tab[pos1].tipo==SORTEREVES))
		{
			saldo1+= tab[pos1].preco;
		}
		dado = (rand() % 3) + 1;
		pos2 = (pos2 + dado) % 30;
		if (tab[pos2].tipo==TERRENO)
		{
			if (tab[pos2].dono==NINGUEM)
			{
				if (rand()%2==0)
				{
					saldo2-=tab[pos2].preco;
					tab[pos2].dono=JOGADOR1;
				}
			}
			if (tab[pos2].dono==JOGADOR2)
			{
				saldo2-=tab[pos1].preco;
				saldo1+=tab[pos1].preco;
				
			}
		}
		if (tab[pos2].tipo==EMPRESA)
		{
			if (tab[pos2].dono==NINGUEM)
			{
				if (rand()%2==0)
				{
					saldo2-=tab[pos2].preco;
					tab[pos2].dono=JOGADOR1;
				}
			}
			if (tab[pos2].dono==JOGADOR2)
			{
				saldo2-=tab[pos2].preco*dado;
				saldo1+=tab[pos2].preco*dado;
			}
		}
		if ((tab[pos2].tipo==PRISAO)||(tab[pos2].tipo==SORTEREVES))
		{
			saldo2+= tab[pos2].preco;
		}
		mostra(pos1, pos2);
		printf("Jogador1=%d Jogador2=%d\n", saldo1, saldo2);
		getchar();
	}
	return 0;
}
