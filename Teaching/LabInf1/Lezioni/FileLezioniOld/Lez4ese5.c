/*  l’utente immette 5 numeri interi,
e viene scritto sullo schermo il maggiore tra questi  */

#include <stdio.h>


int main()
{
   int a, max;
 // come inizializzo max?

   printf("\nScrivi un numero intero: ");
   scanf("%d", &a);
   if(a>max)
       max=a;

   printf("\nScrivi un numero intero: ");
   scanf("%d", &a);
   if(a>max)
       max=a;

   printf("\nScrivi un numero intero: ");
   scanf("%d", &a);
   if(a>max)
       max=a;

   printf("\nScrivi un numero intero: ");
   scanf("%d", &a);
   if(a>max)
       max=a;

   printf("\nScrivi un numero intero: ");
   scanf("%d", &a);
   if(a>max)
       max=a;

   printf("\n Il massimo dei numeri inseriti e': %d ", max);




}

