#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

typedef struct noCarta{
    short numero;
    char nape;
    struct noCarta *prox;
}tCarta;

tCarta *primMonte=NULL;
tCarta *primMesa[]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
tCarta *primNape[]={NULL,NULL,NULL,NULL};
tCarta *temp[]={NULL,NULL,NULL,NULL};

void gerarBaralho(){
    int i,j;
    tCarta *ult;

    //coracao=3, ouro=4, paus=5, espada=6
    for(i=0; i<4; i++){
        for(j=1; j<14; j++){
            if(primMonte==NULL){
                primMonte=(tCarta *)malloc(sizeof(tCarta));
                ult=primMonte;
            }//end if
            else{
                ult->prox=(tCarta *)malloc(sizeof(tCarta));
                ult = ult->prox;
            }//end else
            ult->nape=i+3;
            ult->numero=j;
            ult->prox=NULL;
        }//end for j
    }//end for i
}//end gerarBaralho

void embaralhaBaralho(){
    int i, j, sort;
    tCarta *atual, *ant;

    for(i=0; i<26; i++){//total mudanca no embaralhamento
        sort=rand()%52;
        ant = NULL;
        atual=primMonte;
        for(j=0; j<sort; j++){
            //localizar a carta
            ant=atual;
            atual=atual->prox;
        }//end for j
        if(sort>0){
            ant->prox=atual->prox;
            atual->prox=primMonte;
            primMonte=atual;
        }//end if
    }//end for i
}//end embaralhaBaralho

void distribuirMesa(){
    int i=0;
    tCarta *auxMonte, *auxMesa;
    while(primMonte!=NULL){
        auxMonte=primMonte;
        primMonte=primMonte->prox;
        if(primMesa[i]==NULL){
            primMesa[i]=auxMonte;
            primMesa[i]->prox=NULL;
        }//end if
        else{
            auxMesa=primMesa[i];
            primMesa[i]=auxMonte;
            primMesa[i]->prox=auxMesa;
        }//end else
        if(primMonte==NULL){
            break;
        }
        i=(i+1)%8;
    }//end while
}//end distribuirMesa

void imprime(){
    int i;
    tCarta *atual;

    printf("[TEMP]=");
    for(i=0; i<4; i++){
        if(temp[i]!=NULL){
            printf("%d-[%02d/%c] ", i, temp[i]->numero,temp[i]->nape);
        }//end if
        else{
            printf("%d-[    ] ",i);
        }//end else
    }//end for i
    printf("\n\n");
    for(i=0; i<4; i++){
        atual=primNape[i];
        printf("[NAPE %d]=", i);
        while(atual!=NULL){
            printf("[%02d/%c]",atual->numero,atual->nape);
            atual=atual->prox;
        }//end while
        printf("\n");
    }//end for i
    printf("\n");
    for(i=0; i<8; i++){
        atual=primMesa[i];
        printf("[MESA %d]=", i);
        while(atual!=NULL){
            printf("[%02d/%c]", atual->numero,atual->nape);
            atual=atual->prox;
        }//end while
        printf("\n");
    }//end for i
    printf("\n");
}//end imprime

int main(int argc, char **argv){
    srand(time(NULL));
    gerarBaralho();
    embaralhaBaralho();
    distribuirMesa();
    imprime();
    return 0;
}//end main
