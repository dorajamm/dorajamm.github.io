
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 20
#define VALORI 100

void IniziaRandom(int a[][COL], int r, int c)
{
   int i,j;


   for (i = 0; i <= r - 1; i++)
     for (j = 0; j <= c - 1; j++)
        a[i][j] = rand() % 99 ;
}
void IniziaRandomVettore(int a[], int s)
{
   int j;
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



int main()
{   int i;
   int mat[ROW][COL];

 srand(time(NULL));
   IniziaRandom(mat,ROW,COL);



    printf("Stampo la matrice usando la funzione StampaMatrice :\n");
   StampaMatrice(mat,ROW,COL);

    printf("\n\n");
    printf("Stampo la matrice usando la funzione StampaVettore :\n");
   for (i = 0; i < ROW ; i++)
       StampaVettore(mat[i],COL);

    printf("\n Creo un'altra matrice usando IniziaRandomVettore\n");
  for (i = 0; i < ROW ; i++)
       IniziaRandomVettore(mat[i],COL);

   printf("\n Stampo la matrice usando la funzione StampaVettore :\n");
   for (i = 0; i < ROW ; i++)
       StampaVettore(mat[i],COL);

    printf("\n Stampo la matrice usando la funzione StampaMatrice :\n");
    StampaMatrice(mat,ROW,COL);

	return(0);
}
