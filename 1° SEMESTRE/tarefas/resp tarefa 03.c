#include<stdio.h>
int main (int argc, char*argv[]){
    float vol, pi, alt, raio;

    printf("escreva a altura(metros): ");
    scanf("%f", &alt);
    printf("escreva o raio(metros): ");
    scanf("%f", &raio);
    printf("\n");

    pi = 3.1416;
    vol =  pi * raio * raio * alt;

    printf("volume do cilindro = %f metros", vol);

    return 0;
}
