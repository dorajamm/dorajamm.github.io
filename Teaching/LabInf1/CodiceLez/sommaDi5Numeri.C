/*  programma per la somma di cinque  numeri e poi media */
#include <stdio.h>
int main()
{
   int num, somma;      /* dichiarazioni */
   float media;

   somma=0;
   printf("Scrivi un numero intero:");
   scanf("%d", &num);
   somma=somma+num;

   printf("Scrivi un numero intero:");
   scanf("%d", &num);
   somma=somma+num;

   printf("Scrivi un numero intero:");
   scanf("%d", &num);
   somma=somma+num;

   printf("Scrivi un numero intero:");
   scanf("%d", &num);
   somma=somma+num;

   printf("Scrivi un numero intero:");
   scanf("%d", &num);
   somma=somma+num;

   media=somma/5.0;
   printf("La somma e' %d\n", somma);       /* stampa somma */
   printf("La media e' %f\n", media);

   return 0;  /* indicate that program ended successfully */
}

