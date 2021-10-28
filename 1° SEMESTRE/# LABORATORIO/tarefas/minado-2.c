#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char gabarito[10][10], visual[10][10];

void contaBomba(){
   int i, j, cont;
   for(i = 0; i < 10; i++){
      for(j = 0; j < 10; j++){
         if(gabarito[i][j] == ' '){
            cont = 0;
            if(((i > 0) && (j > 0)) && (gabarito[i-1][j-1] == '*')) cont++;
            if((j > 0) && (gabarito[i][j-1] == '*')) cont++;
            if(((i < 9) && (j > 0)) && (gabarito[i+1][j-1] == '*')) cont++;
            if((i > 0) && (gabarito[i-1][j] == '*')) cont++;
            if((i < 9) && (gabarito[i+1][j] == '*')) cont++;
            if(((i > 0) && (j < 9)) && (gabarito[i-1][j+1] == '*')) cont++;
            if((j < 9) && (gabarito[i][j+1] == '*')) cont++;
            if(((i < 9) && (j < 9)) && (gabarito[i+1][j+1] == '*')) cont++;
            if(cont > 0){
                gabarito[i][j] = '0'+cont;
            }
         }
      }
   }
}

void inicializa(){
    int lin, col, i, j;
    for(i = 0; i < 10; i++){
        for(j=0; j<10; j++){
            visual[i][j] = '?';
            gabarito[i][j] = ' ';
        }
    }
    for(i = 0; i < 10; i++){
        lin = rand() % 10;
        col = rand() % 10;
        if(gabarito[lin][col] == '*'){
            i--;
        }else{
            gabarito[lin][col] = '*';
        }
    }
}

void imprime(){
   int i, j;
   printf("   0  1  2  3  4  5  6  7  8  9\n");
   for(i = 0; i < 10; i++){
      printf("%3d",i);
      for(j = 0; j < 10; j++){
         printf("[%c]",visual[i][j]);
      }
      printf("\n");
   }
}

int main(int argc, char *argv[]){
    int lin, col, cont, jogadas=0;
    srand(time(NULL));
    inicializa();
    contaBomba();
    do {
       imprime();
       printf("Digite [linha coluna]: ");
       scanf("%d %d", &lin, &col);
       if(visual[lin][col]!='?'){
          jogadas++;
          visual[lin][col] = gabarito[lin][col];
          if(visual[lin][col] == '*'){
              break;
          }
       }
    } while(jogadas != 90);
    if(jogadas == 90){
        printf("Voce venceu! \n");
    }else{
        printf("Voce venceu! \n");
    }
    return 0;
}

