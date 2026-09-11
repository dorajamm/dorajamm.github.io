
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 250

// genera un vettore random di valori compresi tra ini e fin
void IniziaRandom(int a[], int s, int ini, int fin)
{
   int j;
   srand(time(NULL));

   for (j = 0; j < s ; j++)
      a[j] = rand() % (fin-ini+1) + ini ;
}

// stampa il vettore su righe di 15 elementi
void StampaVettore(int a[], int s)
{
    int i;
    for (i = 0; i < s ; i++){
      if (i%15 ==0)     printf("\n");
      printf("%3d", a[i]);
    }
    printf("\n\n");
}


int main()
{
   int vett[SIZE]={0};


   IniziaRandom(vett,SIZE, 10,99);
   StampaVettore(vett,SIZE);

	return(0);
}
