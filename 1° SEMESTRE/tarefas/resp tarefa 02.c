#include<stdio.h>
int main(int argc, char * argv[]){
    int ant, x, suc;

    printf("escreva um numero: ");
    scanf("%d", &x);
    printf("\n");

    ant = x-1;
    suc = x+1;

    printf("seu sucessor e %d\n", suc);
    printf("seu antecessor e %d\n", ant);

    return 0;

}
