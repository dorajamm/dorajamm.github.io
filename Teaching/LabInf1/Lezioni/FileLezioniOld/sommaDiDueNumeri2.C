/*  programma per la somma di due numeri */

#include <stdio.h>


int main()
{
   int int1, int2, somma;      /* dichiarazioni */

   printf("Scrivi il primo numero intero:");  /* prompt */
   scanf("%d", &int1);           /* legge u n intero */

   printf("\n Scrivi il secondo numero intero\n"); /* prompt */
   scanf("%d", &int2);             /* legge un intero */

   somma = int1 + int2;        /* assegnazione var somma */

   //printf("La somma e' %d\n", somma);       /* stampa somma */


   printf("La somma di %d e di %d e' %d\n",int1, int2, somma);
   return 0;  /* indicate that program ended successfully */
}

