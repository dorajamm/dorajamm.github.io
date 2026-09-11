/*  programma per stampare il minimo tra due numeri */

#include <stdio.h>

int main()
{
   int a, b, min;

   printf("\nScrivi un numero intero: ");
   scanf("%d", &a);

   printf("\nScrivi un numero intero: ");
   scanf("%d", &b);

   if (a < b){
    min=a;
   }
   if (b < a){
    min=b;
   }
   /*in alternativa si può usare un'altra istruzione
    if (a< b){
        min=a;
   }
   else{
        min=b;
   }
*/
   printf("\nIl minimo tra i  numeri inseriti e': %d\n\n", min);
/*
ATTENZIONE il programma non funziona bene nel caso
in cui si inseriscano numeri uguali. Modificarlo in modo che sia
considerata anche   questa possibilità
}

