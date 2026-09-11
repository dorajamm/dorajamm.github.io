
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void IniziaRandom(int *pa, int s)
{
   int j;
   srand(time(NULL));

   for (j = 0; j <= s - 1; j++)
      {*pa = rand() % 100 ;
       pa++;
      }
}

void StampaVettore(int *pa, int s)
{
    int i;
    for (i = 0; i <= s - 1; i++)
     {printf("%3d", *pa);
      pa++;
    }
   printf("\n\n");

}

int main()
{
  // int vett[SIZE];

   int *vett;
   vett = (int *) malloc(SIZE * sizeof(int));

  // vett =  malloc(SIZE * sizeof(int));

    if( vett == NULL )
        return 0;

   IniziaRandom(vett,SIZE);
   StampaVettore(vett,SIZE);

   printf("\n\n\n Indirizzo primo elemento stampando vett %p",vett);
   printf("\n\n\n Indirizzo primo elemento stampando &vett[0] %p",vett);

   printf("\n\n\n Indirizzo secondo elemento  %p",&vett[1]);
   vett++;
    printf("\n\n\n Indirizzo primo elemento stampando &vett[0] %p",vett);

   printf("\n\n\n ");

   return(0);
}
