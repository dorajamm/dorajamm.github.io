// soluzione esercizio 1 : un cammino in salita
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 17

int genera_matrice(int a[][SIZE], int s) {
    int i, j;
    srand(time(NULL));
    for(i=1; i<s-1; i++){
        for(j=1; j<s-1; j++){
            a[i][j]=1+rand()%20
            ;
        }
    }
    //Inserisco tutti 0 ai bordi
    for(i=0; i<s; i++){
        a[i][0]=0;
        a[0][i]=0;
        a[s-1][i]=0;
        a[i][s-1]=0;
        }
}

void StampaMatrice(int m[][SIZE], int s)
{
    int i,j;
    printf("       ");
    for(i=1;i<s;i++)
        printf(" %2d-",i);
    printf("\n");
    for(i=1;i<s;i++)
    {
        printf("%5d-",i);
        for(j=1;j<s;j++)
            printf("%4d",m[i][j]);
        printf("\n");
    }
}

int PosizMax(int a[][SIZE], int xc, int yc, int *xm, int *ym)
{
    int maggiore=0;

    if(a[xc+1][yc]>maggiore){
        maggiore=a[xc+1][yc];
        *xm=xc+1; *ym=yc;
    }
    if(a[xc][yc+1]>maggiore){
        maggiore=a[xc][yc+1];
        *xm=xc; *ym=yc+1;
    }
    if(a[xc-1][yc]>maggiore){
        maggiore=a[xc-1][yc];
        *xm=xc-1; *ym=yc;
    }
    if(a[xc][yc-1]>maggiore){
        maggiore=a[xc][yc+1];
        *xm=xc; *ym=yc-1;
    }

    return maggiore;
}


int percorso(int a[][SIZE], int x, int y){
    int  xm,ym;
    int passi=1;
    int cont=1;

    printf("Posizione: (%2d, %2d)  Quota: %3d  \n", x,y,a[x][y]);
    while(passi<=20 && cont){
        if (PosizMax(a,x,y,&xm,&ym) >= a[x][y]){
            x=xm; y=ym;
            printf("Posizione: (%2d, %2d)  Quota: %3d  \n", x,y,a[x][y]);
            passi++;
        }
        else
            cont=0;

    }

}


int main()
{
    srand(time(NULL));
    int m[SIZE][SIZE];

    int xc, yc;
    int massimo;
    int input;

    genera_matrice(m,SIZE);
    do{
      StampaMatrice(m,SIZE-1);
      printf("\nDove vuoi che si trovi il topolino inizialmente?\nRiga: ");
      scanf("%d", &xc);
      printf("Colonna: ");
      scanf("%d", &yc);

      percorso(m,xc,yc);
      printf("\n\nPer ripetere il cammino del topolino digitare 1 \nPer uscire dal programma digitare 0\n");
      scanf(" %d", &input);}
    while(input > 0);




}
