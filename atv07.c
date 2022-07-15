#include<stdio.h>

int main(int argc, char const *argv[])
{
    int matA[3][3];

    //matriz MxN
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matA[i][j] = 0;
            if(i = j){
                matA[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < 3; i++){ 
        for (int j = 0; j < 3; j++){
            if(matA[i][j] == matA[i+1][j]){
                printf("sim");
                return 0;
            }
        }
    }
    printf("nao");


    return 0;
}
