#include<stdio.h>
#include<math.h>
int main (int argc, char * argv[]){
    float raio, comp, pi, area, vol = 0;
    printf("digite o raio: ");
    scanf("%f", &raio);

    pi = 3,1416;
    comp = 2*pi*raio;
    area = pi*(pow(raio,2));
    vol = 4.0/3.0*pi*(pow(raio,3));

    printf("comprimento da esfera = %.2f\n", comp);
    printf("area da esfera = %.2f\n", area);
    printf("volume da esfera = %.2f\n", vol);

    return 0;
}
