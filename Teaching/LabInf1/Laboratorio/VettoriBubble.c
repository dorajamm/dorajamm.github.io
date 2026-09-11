
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

void IniziaRandom(int a[], int s)
{
   int j;
   srand(time(NULL));

   for (j = 0; j <= s - 1; j++)
      a[j] = rand() % 100 ;
}

void StampaVettore(int a[], int s)
{
    int i;
    for (i = 0; i < s ; i++)
      printf("%3d", a[i]);
    printf("\n");
}

void bubbleSort2(int v[], int n) {
int i,j,scambi, tmp;
scambi = 1;
for (i=0; i< n && scambi ;i++)
{ 	scambi = 0;
	for (j=0; j<n-1-i ; j++)
		if (v[j] > v[j+1])
		{ 	scambi = 1;
			tmp = v[j];
			v[j] = v[j+1];
			v[j+1] = tmp; }
    printf("%3d : ",i);
    StampaVettore(v,n);
    getchar();
}
}
void bubbleSort(int a[], int s) //versione che esegue i cicli lunghi
{
   int i, j, tmp;

   for (i =0 ; i < s-1 ; i++){
      for (j = 0; j < s - 1; j++){
         if (a[j] > a[j+1]) {
            tmp = a[j]; //scambio a[j]e a[j+1]
            a[j] = a[j+1];
            a[j+1] = tmp;
         }
      }
    printf("%3d : ",i);
    StampaVettore(a,s);
    getchar();
   }
}

int main()
{
   int vett[SIZE];


   IniziaRandom(vett,SIZE);

   printf("%3c : "," ");
   StampaVettore(vett,SIZE);
   getchar();

    bubbleSort2(vett,SIZE);
   //bubbleSort2(vett,SIZE);

   printf("%3c : "," ");
   StampaVettore(vett,SIZE);


	return(0);
}
