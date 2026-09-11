/*  l’utente immette 5 numeri interi, e viene scritto
sullo schermo quanti sono i numeri pari.  */

#include <stdio.h>


int main()
{
   int a, pari;
   pari=0;

   printf("\nScrivi un numero intero: ");
   scanf("%d", &a);
   if(a%2==1)
       pari=pari+1;

   printf("\n Scrivi un numero intero: ");
   scanf("%d", &a);
   if(a%2==1)
       pari=pari+1;

  printf("\n Scrivi un numero intero: ");
   scanf("%d", &a);
   if(a%2==1)
       pari=pari+1;

   printf("\n Scrivi un numero intero: ");
   scanf("%d", &a);
   if(a%2==1)
       pari=pari+1;

   printf("\n Scrivi un numero intero: ");
   scanf("%d", &a);
   if(a%2==1)
       pari=pari+1;


   printf("\n Hai inserito %d numeri pari", pari);




}

