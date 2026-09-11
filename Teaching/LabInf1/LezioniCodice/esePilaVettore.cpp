/*
Gestione PILA di  numeri interi con un vettore
i valori sono inseriti dalla posizione 0
se top=-1 la pila è vuota
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SIZE 20


void menu(void)
{
   printf("\n\n Operazioni possibili:\n"
          "   1 per inserire un elemento nella pila (PUSH).\n"
          "   2 per estrarre un elemento dalla pila (POP)\n"
          "   0 per uscire\n");
}

int isEmpty(int top)
{
   return top == -1;
}

int isFull(int top)
{
   return top == SIZE-1;
}
void push(int S[], int * top, int val) //inserimento nella pila di val
{
   if (! isFull(*top)) {
        *top = *top+1;
        S[*top] = val;
   }
   else
      printf("memoria esaurita!\n");
}



int pop(int S[], int *top) //estrazione di un elemento dalla pila
{
   int valore;
   valore = S[*top];
   *top = *top-1;
   return valore;
}








void stampa_pila(int S[], int top) {
    if (isEmpty(top))
      printf("la pila e' vuota\n\n");
   else {
      printf("La pila e' :\n");
      while (top !=-1) {
        printf("%d --> ", S[top]);
        top = top-1;
       }
       printf("fine\n");
   }
  }



main()
{
   int pila[SIZE];
   int t=-1;

   int scelta;
   int item;

   menu();
   printf("operazione? ");
   scanf("%d", &scelta);

   while (scelta != 0) {

      switch (scelta) {
         case 1:
            printf("Inserisci un intero: ");
            scanf("\n%d", &item);
            push(pila, &t, item);
            stampa_pila(pila, t);
            break;
         case 2:
            if (!isEmpty(t)) {
               item=pop(pila, &t);
               printf("Ho estratto il valore %d \n", item);
               stampa_pila(pila, t);
             }
            else
              printf("La pila e' vuota \n\n");
                        break;
         default:
            printf("Scelta non valida.\n\n");
            menu();
            break;
      }

      printf("operazione? ");
      scanf("%d", &scelta);
   }

   printf("arrivederci....\n");
   return 0;
}
