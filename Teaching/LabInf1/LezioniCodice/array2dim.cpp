
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 20
#define VALORI 100

void IniziaRandom(int a[][COL], int r, int c)
{
   int i,j;
   srand(time(NULL));

   for (i = 0; i <= r - 1; i++)
     for (j = 0; j <= c - 1; j++)
        a[i][j] = rand() % 99 ;
}
void IniziaRandomVettore(int a[], int s)
{
   int j;
   srand(time(NULL));

   for (j = 0; j <= s - 1; j++)
      a[j] = rand() % 99 ;
}
void StampaVettore(int a[], int s)
{
    int i;
    for (i = 0; i <= s - 1; i++)
      printf("%3d", a[i]);
    printf("\n");
}

void StampaMatrice(int a[][COL], int r, int c)
{  int i,j;

    for (i = 0; i <= r - 1; i++){
        for (j = 0; j <= c - 1; j++)
           printf("%3d", a[i][j]);
        printf("\n");
   }
}

void scambia(int a[], int h, int k) // scambia i valori in posizione h e k
{   int tmp;
    tmp = a[h];
    a[h] = a[k];
    a[k] = tmp;
}// fine scambia


int main()
{   int i;
   int mat[ROW][COL];


   IniziaRandom(mat,ROW,COL);
    printf("Stampo la matrice usando la funzione StampaMatrice :\n");
   StampaMatrice(mat,ROW,COL);

     printf("\n\n");


   printf("Stampo la matrice usando la funzione StampaVettore :\n");
   for (i = 0; i < ROW ; i++)
       StampaVettore(mat[i],COL);



	return(0);
}
