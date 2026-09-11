/*  programma per la somma di cinque numeri */

#include <stdio.h>


int main()
{
   int a, b,c,d,e, somma;

   printf("\nScrivi un numero intero: ");
   scanf("%d", &a);

   printf("\n Scrivi un numero intero: ");
   scanf("%d", &b);

   printf("\n Scrivi un numero intero: ");
   scanf("%d", &c);
   printf("\n Scrivi un numero intero: ");
   scanf("%d", &d);
   printf("\n Scrivi un numero intero: ");
   scanf("%d", &e);

   somma = a + b +c+d+e;

   printf("\n La somma dei numeri inseriti e': %d\n\n", somma);




}

