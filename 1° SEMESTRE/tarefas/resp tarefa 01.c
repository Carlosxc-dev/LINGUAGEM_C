#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[]){
    int x, y, z;
    float medg, meda, medh, medp;

    printf("digite num x: ");
    scanf("%d", &x);
    printf("digite num y: ");
    scanf("%d", &y);
    printf("digite num z: ");
    scanf("%d", &z);
    printf("\n");

    meda = (x+y+z)/3.0;
    medg = cbrt(x*y*z);
    medh = 1.0/((1.0/x)+(1.0/y)+(1.0/z));
    medp = ((x)+(y*2)+(z*3)) / 6.0;

    printf("media aritmetica = %.2f\n", meda);
    printf("media geometrica = %.2f\n", medg);
    printf("media harmonica = %.2f\n", medh);
    printf("media ponderada = %.2f\n", medp);
    printf("\n");

    return 0;
}

