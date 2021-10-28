#include<stdio.h>
int main(int argc, char * argv[]){
    char email[50];
    int dia, mes, ano;
    float altura, peso, imc;

    printf("digite o email: ");
    scanf("%s", email);
    printf("data de nascimento(dd/mm/aa): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    printf("digite sua altura(metros): ");
    scanf("%f", &altura);
    printf("fale seu peso(kg): ");
    scanf("%f", &peso);

    imc = peso / (altura*altura);

    printf("email: %s\n", email);
    printf("nascimento: %d/%d/%d\n", dia, mes, ano);
    printf("IMC: %f\n", imc);

    return 0;
}
