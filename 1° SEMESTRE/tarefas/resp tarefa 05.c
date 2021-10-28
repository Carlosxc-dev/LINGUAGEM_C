#include<stdio.h>
#include<math.h>
#define PI 3.1416

int main (int argc, char * argv[]){
    int num;
    float quad, cubo, raizcub, raizquad;

    printf("digite um numero: ");
    scanf("%d", &num);

    quad = num*num;
    raizquad = sqrt(num);
    cubo = pow(num,3);
    raizcub = cbrt(num);

    printf("quadrado =  %f\n", quad);
    printf("raiz quadrada = %f\n", raizquad);
    printf("cubo = %f\n", cubo);
    printf("raiz cubica = %f\n", raizcub);

    return 0;
}
