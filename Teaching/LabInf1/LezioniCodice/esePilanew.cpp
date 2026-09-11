/*
Gestione PILA di  numeri
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

  struct nodo {
  int info;
  struct nodo *next;
  };

  typedef struct nodo Nodo;
  typedef  Nodo *PNodo;


void menu(void)
{
   printf("\n\n Operazioni possibili:\n"
          "   1 per inserire un elemento nella pila (PUSH).\n"
          "   2 per estrarre un elemento dalla pila (POP)\n"
          "   0 per uscire\n");
}

int isEmpty(PNodo top)
{
   return top == NULL;
}

void push(PNodo *top, int val) //inserimento nella pila
{
   PNodo p;

   p = (PNodo) malloc(sizeof(Nodo));
   p->info = val;
   p->next = *top;
   *top = p;
}



int pop(PNodo *top) //estrazione di un elemento dalla pila
{
   PNodo p;
   int valore;

   p = *top;
   valore = (*top)->info;
   *top = (*top)->next;
   free(p);
   return valore;
}








void stampa_pila(Nodo *top) {
    if (top == NULL)
      printf("la pila e' vuota\n\n");
   else {
      printf("La pila e' :\n");
      while (top != NULL) {
        printf("%d --> ", top->info);
        top = top->next;
       }
       printf("NULL\n");
   }
  }



main()
{
   PNodo pila = NULL;
   int scelta;
   int item;

   menu();
   printf("? ");
   scanf("%d", &scelta);

   while (scelta != 0) {

      switch (scelta) {
         case 1:
            printf("Inserisci un intero: ");
            scanf("\n%d", &item);
            push(&pila, item);
            stampa_pila(pila);
            break;
         case 2:
            if (!isEmpty(pila)) {
               item=pop(&pila);
               stampa_pila(pila);
             }
            else
              printf("La pila e' vuota \n\n");
                        break;
         default:
            printf("Scelta non valida.\n\n");
            menu();
            break;
      }

      printf("? ");
      scanf("%d", &scelta);
   }

   printf("arrivederci....\n");
   return 0;
}
