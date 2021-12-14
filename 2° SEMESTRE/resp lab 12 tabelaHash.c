#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 68

typedef struct no
{
    char nome[70];
    int matricula;
} noHash;

noHash tabHashAlunos[MAX];

// inicializa Tabela Hash com valores invalidos
void inicializa()
{
    int i;
    for (i = 0; i < MAX; i++)
        tabHashAlunos[i].matricula = -1;
    return;
} // end inicializa()

void imprimeNoAluno(noHash atual, int posCerta, int comp)
{
    int pos;
    pos = atual.matricula % MAX;

    printf("matricula = %d\n", atual.matricula);
    printf("nome = %s\n", atual.nome);
    printf("posicao = %d\n", pos);
    printf("posicao inserida = %d\n", posCerta);
    printf("numero comparacoes = %d\n", comp);
}

void inserirElementoTabHash(noHash atual)
{
    // pos e a posicao que deve ser inserido no vetor
    int pos, numComp = 1;

    // calcule funcao de hashing
    pos = atual.matricula % MAX;

    // se posicao estiver vazia, insere
    if (tabHashAlunos[pos].matricula == -1)
    {
        // copia informacoes
        tabHashAlunos[pos].matricula = atual.matricula;
        strcpy(tabHashAlunos[pos].nome, atual.nome);

        // imprime informacoes
        imprimeNoAluno(atual, pos, numComp);
        return;
    } // end if
    else
    {
        // enquanto nao encontrar posicao vazia, prossiga procurando
        while (numComp < MAX)
        {
            // 1) pos recebe a proxima posicao
            // 2) incrementa numero de comparacoes
            pos = (pos + 1) % MAX;
            numComp++;
            if (tabHashAlunos[pos].matricula == -1)
            {
                tabHashAlunos[pos].matricula = atual.matricula;
                strcpy(tabHashAlunos[pos].nome, atual.nome);
            }

            // imprime informacoes
            imprimeNoAluno(atual, pos, numComp);
            return;
            // end if
        } // end while
    }     // end else
} // end inserirElementoTabHash

bool buscaAluno(int matricula)
{
    int pos, numComp = 1;

    pos = matricula % MAX;
    if (tabHashAlunos[pos].matricula == matricula)
    {
        imprimeNoAluno(tabHashAlunos[pos], pos, numComp);
        return true;
    }
    else
    {
        while (numComp < MAX)
        {
            pos = (pos + 1) % MAX;
            numComp++;
            if (tabHashAlunos[pos].matricula == matricula)
            {
                imprimeNoAluno(tabHashAlunos[pos], pos, numComp);
                return true;
            }
        }
    }
    printf("matricula encontrada \n");
}

void imprimeVetor()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("v[%d] = %d  %s\n", i, tabHashAlunos[i].matricula, tabHashAlunos[i].nome);
    } // end for
} // end imprimeVetor()

int main(int argc, char *argv[])
{
    int i, opcaoMenu, matricula;
    noHash novo;

    // inicializa tabela hash
    inicializa();

    // lista de nomes
    char listaNomes[MAX][70] = {
        "AMANDA SACCHI",
        "ANA FL�VIA SOARES REIS",
        "ANDR� LUIZ MELO DOS SANTOS FRANCO",
        "ANDR� MARCOS LEIFELD RAICOSKI",
        "ANNA BEATRYZ COSTA",
        "ANNA LUIZA DIAS",
        "ARTHUR RAMOS FERRONI",
        "BRENNO DE OLIVEIRA DA ROSA",
        "BRENO DA SILVA CUST�DIO",
        "BRUNA CUST�DIO ALVES",
        "BRUNO ELIAS MARTINS PEREIRA",
        "BRUNO SAID ALVES DE SOUZA",
        "CARLOS HENRIQUE CRUZ XAVIER",
        "C�SAR FELIPE SANTOS DE GODOY",
        "DANIEL FERREIRA LARA",
        "DANIEL FL�VIO BRITO COELHO",
        "DANIEL JOS� MACHADO",
        "DANILO CANUTO PEREIRA",
        "DAVI JOS� MOREIRA CUNHA",
        "DAVI LUCAS SANTOS PEREIRA",
        "DIEGO RODRIGO GOMES",
        "DIELSON SOARES DE OLIVEIRA JUNIOR",
        "EDUARDO ALVES CARVALHO",
        "EDUARDO SILES MARTINS",
        "ENZO YUKIO CHINEN",
        "FELIPE FAUSTINO BRITO",
        "FELIPE QUEIROZ FLORES QUINTAO BACHETTI",
        "FELIPE SANTANA MEDEIROS",
        "FERNANDO COSTA LASMAR",
        "GABRIEL OLIVEIRA GALINDO",
        "GUILHERME SILVA TEIXEIRA",
        "GUILHERME VASCONCELOS HORITA",
        "HENRIQUE BERALDO VILELA MARQUES",
        "HUGO DAMASIO CEZARIO DE SOUZA",
        "IGOR RAFAEL MARCELO MORAIS",
        "ITALO SOUZA SILVA",
        "JENNIFER YURIE HATA",
        "JO�O LUCAS BERLINCK CAMPOS",
        "JO�O LUCAS SOARES SIKANSI",
        "JO�O RAFAEL RODRIGUES VILAS",
        "JORGE CHRISTINO DOS SANTOS FERREIRA",
        "JOS� EDUARDO IZIDORO JUNIOR",
        "KAIO PASQUAL NUNES LAMANNA",
        "KAMAL FELIX RAMADAN",
        "LEONARDO FACURI FERRETTI",
        "LEONARDO MONTEIRO LABEGALINI",
        "LEONARDO SOUSA FERREIRA FADUL",
        "LUCAS LUAN BELARMINO BARBOSA",
        "LUIS FELIPE FERIAN",
        "LUIZ GUILHERME FARIA FERREIRA",
        "LUIZ HENRIQUE ALVES DO NASCIMENTO",
        "MARCOS PAULO VIEIRA SOARES",
        "MATEUS ALEXANDRE MARTINS DE SOUZA",
        "MATEUS DE BRAGAN�A KALLAS",
        "MATHEUS SISTON GALDINO",
        "MATIAS DA SILVA CAMPOS",
        "PATRICIA BRENNY RIBEIRO",
        "RAFAEL CHAVES PEREIRA DOS SANTOS",
        "RENATO MARQUEZCUNHA",
        "RICARDO FELIPE PEREIRA SILVA",
        "RONYS WELLINGTON RODRIGUES DE SANTANA",
        "RYAN FELIPE FERREIRA RIBEIRO",
        "SAMUEL JACKSON CARVALHO LEONEL",
        "TAYNARA MARCONDES PEREIRA SILVA",
        "THIAGO BATISTA ARAUJO",
        "VINICIUS HENRIQUE SILVA",
        "VIVIAN LEITE FRAGOSOS",
        "YANN MATIAS DUTRA"};

    // Lista de Numeros de Matricula
    int listaMatriculas[MAX] = {2021006707, 2021000140, 2021012740, 21007221, 2021020279, 2020024934, 2020017733, 2021029935, 2021018190, 2021032144, 2021018379, 2021002510, 2021015751, 2020003611, 2021003661, 2020017475, 2021025990, 2020005358, 2021016131, 2021019053, 2021020457, 2021004346, 2021017550, 2021026290, 2021005307, 2021007366, 2021005147, 2021020930, 2021024278, 2020013430, 2021033061, 2021011860, 2021011627, 2021025097, 2021030829, 2021006485, 2021001907, 2016017450, 2021003160, 2019015629, 2021014825, 2021024170, 2018013924, 2021032485, 2020001930, 2021012769, 2021001101, 2021017872, 2021025391, 2018010360, 2021005586, 2019005810, 2021004023, 2018000579, 2021006340, 2021025776, 2021018870, 2017011371, 2021020733, 2021019590, 2021020170, 2021020958, 2019005220, 2021000543, 2021032968, 2021024115, 2021032743, 2021014988};

    // insere todos os alunos na tabela hash
    for (i = 0; i < MAX; i++)
    {
        novo.matricula = listaMatriculas[i];
        strcpy(novo.nome, listaNomes[i]);
        inserirElementoTabHash(novo);

        imprimeVetor();
        printf("\n-------------");
        printf("\nTecle ENTER para inserir o proximo...");
        getch();
        system("cls");
    } // end for

    // realizando buscas
    printf("Buscando Aluno ...\n\n");

    imprimeVetor();
    while (1)
    {
        printf("\n-------------");
        printf("\nInforme uma matricula para busca: ");
        scanf("%d", &matricula);
        system("cls");

        if (buscaAluno(matricula) != true)
        {
            break;
        }
        imprimeVetor();
    } // end while
    return 0;
} // end main()
