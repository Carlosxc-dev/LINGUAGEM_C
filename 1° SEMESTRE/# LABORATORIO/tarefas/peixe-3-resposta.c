#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int larva=0;
int alga=0;
int sais=1;
int jogadas=0;
char tanque[25][50];
void inicializa(){
    int i, j, l, c;
    for(i=0;i<25;i++){
        for(j=0;j<50;j++){
            tanque[i][j]=' ';
        }
    }
    for(i=0;i<3;i++){// losangulo
        l=rand()%25;
        c=rand()%50;
        if(l+1<25 && c+2<50 ){
            tanque[l][c+1]=':';
            tanque[l+1][c]=':';
            tanque[l+1][c+1]=':';
            tanque[l+1][c+2]=':';
        }else{
            i--;
        }
    }
    for(i=0;i<2;i++){// triangulo
        l=rand()%25;
        c=rand()%50;
        if(l+2<25 && c+5<50 ){
            tanque[l][c+3]=':';
            tanque[l+1][c+2]=':';
            tanque[l+1][c+3]=':';
            tanque[l+1][c+4]=':';
            tanque[l+2][c+1]=':';
            tanque[l+2][c+2]=':';
            tanque[l+2][c+3]=':';
            tanque[l+2][c+4]=':';
            tanque[l+2][c+5]=':';
        }else{
            i--;
        }
    }
    for(i=0;i<10;i++){//conchas
        l=rand()%25;
        c=rand()%50;
        if(tanque[l][c]==' '){
            tanque[l][c]='@';
        }else{
            i--;
        }
    }
    for(i=0;i<5;i++){//algas
        l=rand()%25;
        c=rand()%50;
        if(tanque[l][c]==' '){
            tanque[l][c]='y';
        }else{
            i--;
        }
    }
    for(i=0;i<3;i++){//peixes
        l=rand()%25;
        c=rand()%50;
        if(tanque[l][c]==' '){
            tanque[l][c]='x';
        }else{
            i--;
        }
    }
}
void imprime(){
    int i, j;
    printf("    ");
    for(j=0;j<50;j++){
        if(j/10>=1){
            printf("%d", j/10);
        }else{
            printf(" ");
        }
    }
    printf("\n");
    printf("    ");
    for(j=0;j<50;j++){
        printf("%d", j%10);
    }
    printf("\n");
    for(i=0;i<25;i++){
        printf("[%2d]", i);
        for(j=0;j<50;j++){
            printf("%c", tanque[i][j]);
        }
        printf("\n");
    }
    printf("larva=%d alga=%d sais=%d\n", larva, alga, sais);
}
void cultivar(){
    int l, c;
    if(alga > 0){
        printf("CULTIVAR[linha coluna]: ");
        scanf("%d %d", &l, &c);
        getchar();
        if(l>=0 && l<25 && c>=0 && c<50){
            if(tanque[l][c]==' '){
                tanque[l][c]='y';
                alga--;
                jogadas++;
            }else{
                printf("Celula nao esta vazia.\n");
            }
        }else{
            printf("Linha < 25 e Coluna < 50.\n");
        }
    }else{
        printf("Zerado saldo de alga.\n");
    }
}
void fertilizar(){
    int l, c;
    printf("FERTILIZAR[linha coluna]: ");
    scanf("%d %d", &l, &c);
    getchar();
    if(l>=0 && l<25 && c>=0 && c<50){
        if(tanque[l][c]=='y'){
            if(sais > 0){
                tanque[l][c]='Y';
                sais--;
                jogadas++;
            }else{
                printf("zerado saldo de sais.\n");
            }
        }else{
            printf("Celula nao tem broto de alga.\n");
        }
    }else{
        printf("Linha < 25 e Coluna < 50.\n");
    }
}
void mover(){
    int l, c, x, y;
    printf("MOVER ORIGEM [linha coluna]: ");
    scanf("%d %d", &l, &c);
    getchar();
    if(l>=0 && l<25 && c>=0 && c<50){
        if(tanque[l][c]=='-' || tanque[l][c]=='x' || tanque[l][c]=='X'){
            printf("MOVER DESTINO [linha coluna]: ");
            scanf("%d %d", &x, &y);
            getchar();
            if(abs(x-l) <= 1 && abs(c-y) <= 1 && x>=0 && x<25 && y>=0 && y<50){
                if( tanque[l][c]=='X' &&
                    tanque[x][y]==' ' &&
                   ((y>0 && tanque[x][y-1]=='x') ||
                   ((y<49 && tanque[x][y+1]=='x')))){
                        tanque[x][y]='-';
                        tanque[l][c]=' ';
                        sais+=2;
                        larva++;
                        jogadas++;
                }else if(tanque[x][y]==' '){
                    tanque[x][y] = tanque[l][c];
                    tanque[l][c] = ' ';
                    jogadas++;
                }else if(tanque[x][y]==':' || tanque[x][y]=='@'){
                    tanque[l][c] = ' ';
                    jogadas++;
                }else if(tanque[x][y]=='y'){
                    if(tanque[l][c]=='-'){
                        tanque[x][y] = 'x';
                        tanque[l][c] = ' ';
                        jogadas++;
                    }else if(tanque[l][c]=='x'){
                        tanque[x][y] = 'X';
                        tanque[l][c] = ' ';
                        jogadas++;
                    }else{
                        tanque[x][y] = 'X';
                        tanque[l][c] = ' ';
                        jogadas++;
                    }
                }else if(tanque[x][y]=='Y'){
                    if(tanque[l][c]=='-'){
                        tanque[x][y] = 'x';
                        tanque[l][c] = ' ';
                        alga++;
                        jogadas++;
                    }else if(tanque[l][c]=='x'){
                        tanque[x][y] = 'X';
                        tanque[l][c] = ' ';
                        alga++;
                        jogadas++;
                    }else{
                        tanque[x][y] = 'X';
                        tanque[l][c] = ' ';
                        alga++;
                        jogadas++;
                    }
                }
            }else{
                printf("Celula destino nao eh vizinha da celula de origem.\n");
            }
        }else{
            printf("Celula origem nao tem larva ou peixe jovem ou adulto.\n");
        }
    }else{
        printf("Linha < 25 e Coluna < 50.\n");
    }
}
void quebrar(){
    int l, c, s;
    printf("QUEBRAR[linha coluna]: ");
    scanf("%d %d", &l, &c);
    getchar();
    if(l>=0 && l<25 && c>=0 && c<50){
        if(tanque[l][c]=='@'){
            tanque[l][c]=' ';
            jogadas++;
            s = rand() % 100;
            if(s < 25){
                sais++;
            }else if(s >= 25 && s < 50){
                larva++;
            }else if(s >= 50 && s < 75){
                alga++;
            }else if(s >= 75 && s < 85){
                sais+=2;
            }else if(s >= 85 && s < 95){
                larva+=2;
            }else if(s >= 96 && s < 100){
                alga+=2;
            }
        }else{
            printf("Celula nao tem concha.\n");
        }
    }else{
        printf("Linha < 25 e Coluna < 50.\n");
    }
}
void pescar(){
    int l, c;
    printf("PESCAR[linha coluna]: ");
    scanf("%d %d", &l, &c);
    getchar();
    if(l>=0 && l<25 && c>=0 && c<50){
        if(tanque[l][c]=='x'){
            tanque[l][c]=' ';
            sais++;
            jogadas++;
        }else if(tanque[l][c]=='X'){
            tanque[l][c]=' ';
				sais+=2;
				larva++;
            jogadas++;
        }else{
            printf("Celula nao tem peixe jovem ou adulto.\n");
        }
    }else{
        printf("Linha < 25 e Coluna < 50.\n");
    }
}
void noite(){
    int i, j, l, c, s, n;
    jogadas=0;//zerar
    for(i=0;i<25;i++){
        for(j=0;j<50;j++){
            //evolucao de larva para peixe jovem
            if(tanque[i][j]=='-' && rand() % 100 < 30){
                tanque[i][j]='x';
            }
            if(tanque[i][j]=='y' && rand() % 100 < 50){
                tanque[i][j]='Y';
            }
            //morre larva, peixe jovem, peixe adulto, broto alga, alga adulta
            if(tanque[i][j]=='@'){
                for(l=-1;l<2;l++){
                    for(c=-1;c<2;c++){
                        if(i+l>=0 && i+l <50 && j+c>=0 && j+c <50){
                            if(tanque[i+l][j+c]=='-' ||
                                tanque[i+l][j+c]=='x' ||
                                tanque[i+l][j+c]=='X' ||
                                tanque[i+l][j+c]=='y' ||
                                tanque[i+l][j+c]=='Y' ){
                                    tanque[i+l][j+c]=' ';
                            }
                        }
                    }
                }
            }
            //nasce concha
            if(tanque[i][j]==' ' && rand() % 1250 == 0){
                tanque[i][j]='@';
            }
        }
    }
}

void salvar()
{
    int i, j;
    FILE * arq;
    char nome_arq[20];
    printf("digite nome do arquivo: ");
    gets(nome_arq);
    arq = fopen(nome_arq, "w");
    if (arq!=NULL)
    {
        for ( i = 0; i < 25; i++)
        {
            for ( j = 0; j < 50; j++)
            {
                fprintf(arq, "%c", tanque[i][j]);
            }
            fprintf(arq, "\n");
        }
        fprintf(arq, "%d\n", larva);
        fprintf(arq, "%d\n", alga);
        fprintf(arq, "%d\n", sais);
        fprintf(arq, "%d\n", jogadas);
        fclose(arq);
    }
    else
    {
        printf("erro no arquivo.\n");
    }
    
}
void carregar()
{
    FILE * arq;
    char nome_arq[20];
    int i , j;
    printf("nome do arquivo: ");
    gets(nome_arq);
    arq = fopen(nome_arq, "r");
    if (arq!=NULL)
    {
        for ( i = 0; i < 25; i++)
        {
            for ( j = 0; j < 50; j++)
            {
                fscanf(arq, "%c", &tanque[i][j]);
            }
            fgetc(arq);
        }
        fscanf(arq, "%d\n", &larva);
        fscanf(arq, "%d\n", &alga);
        fscanf(arq, "%d\n", &sais);
        fscanf(arq, "%d\n", &jogadas);
        fclose(arq);
    }
    else
    {
        printf("arquivo existe!!\n");
    }
}


int main( int argc, char * arv[]){
    srand(time(NULL));
    inicializa();
    char op=' ';
    printf("deseja carregar jogo[s/n]: ");
    op = getch();
    printf("%c\n", op);
    if (op=='s')
    {
        carregar();
    }
    op = ' ';
    while(op != 's'){
        imprime();
        printf("(c)ultivar / (f)ertilizar / (m)over / (q)uebrar / (p)escar / (n)oite / (s)air ");
        printf("[Jogada %d] opcao:", jogadas);
        op = getch();
        printf("%c\n",op);
        switch(op){
            case 'c' :
                cultivar();
                break;
            case 'f' :
                fertilizar();
                break;
            case 'm' :
                mover();
                break;
            case 'q' :
                quebrar();
                break;
            case 'p' :
                pescar();
                break;
            case 'n' :
                noite();
                break;
            case 's' :
                break;
            default:
                printf("[opcao invalida]");
        }
        if(jogadas >= 7){
            imprime();
            noite();
        }
    }
    printf("deseja salvar o jogo? [s/n] ");
    op = getch();
    printf("%c\n", op);
    if (op=='s')
    {
        salvar();
    }
    
    return 0;
}
