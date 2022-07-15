#include<stdio.h>

int main(int argc, char const *argv[])
{
    int matA[3][3]={{2,3,2},{1,2,5},{3,4,9}};
    int matB[3][2]={{2,0},{4,4},{1,3}};
    int matC[3][3]={{0,0,0},{0,0,0},{0,0,0}};

    for (int i = 0; i < 3; i++){ 
        for (int j = 0; j < 3; j++){
            matC[i][j] = matA[i][j]*matB[i][j];
            printf("%d ", matC[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++){ 
        for (int j = 0; j < 3; j++){
            matC[i][j] = matA[i][j]*matB[i][j];
            printf("%d ", matC[i][j]);
        }
        

    return 0;
}
