/*  programma per la somma di due numeri */

#include <stdio.h>


int main()
{
   int int1, int2, somma;      /* dichiarazioni */

   int1 =123;
   printf("Il primo numero intero e' %d: \n", int1);

   int2 =456;
   printf("Il secondo numero intero e' %d: \n", int2);


   somma = int1 + int2;        /* assegnazione var somma */

   printf("La somma e' %d\n", somma);       /* stampa somma */


   //printf("La somma di %d e di %d e' %d\n",int1, int2, somma);
   return 0;  /* indicate that program ended successfully */
}

