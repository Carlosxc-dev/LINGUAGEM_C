#include<stdio.h>

int main(int argc, char const *argv[])
{
    float x, y, media, cont, mediaclass;
    int i, contapr=0, contrep=0, contexam=0;

    for(i=1;i<=6;i++)
    {
        // entrada de notas
        printf("aluno %d nota x = ", i);
        scanf("%f", &x);
        printf("aluno %d nota y = ", i);
        scanf("%f", &y);
        //calculo da media
        media = (x+y)/2;
        mediaclass += media;
        printf("media aluno %d = %.2f\n", i, media);
        //contagem 
        if(media<=3){
            contrep += 1;
            printf("\t---->aluno %d reprovado\n\n", i);
        }else{
            if((media>3)&&(media<=7)){
                contexam += 1;
                printf("\t---->aluno %d em exame\n\n", i);
            }else{
                contapr += 1;
                printf("\t---->aluno %d aprovado\n\n", i);
            }
        }
        
    } 
    //media da classe 
    mediaclass /= 6; 
    // impressao status dos alunos da classe 
    printf("media da classe = %.2f\n", mediaclass);
    printf("total de alunos reprovados = %d\n", contrep);
    printf("total de alunos em exame = %d\n", contexam);
    printf("total de alunos aprovados = %d\n\n", contapr);

    return 0;
}
