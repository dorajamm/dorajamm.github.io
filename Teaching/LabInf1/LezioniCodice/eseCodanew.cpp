/*
Gestione CODA di  numeri
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
          "   1 per inserire un elemento nella coda (ENQUEUE).\n"
          "   2 per estrarre un elemento dalla coda (DEQUEUE)\n"
          "   0 per uscire\n");
}

int isEmpty(PNodo p)
{
   return p == NULL;
}

void enqueue(PNodo *head,PNodo *tail, int val) //inserimento nella coda
{
   PNodo p;

   p = (PNodo) malloc(sizeof(Nodo));

    p->info = val;
    p->next = NULL;
    if (isEmpty(*head))
         *head = p;
    else
         (*tail)->next = p;

      *tail = p;


}



int dequeue(PNodo *head,PNodo *tail) //estrazione di un elemento dalla coda
{
   PNodo p;
   int valore;

   p = *head;
   valore = (*head)->info;
   *head = (*head)->next;

   if (*head == NULL)
      *tail = NULL;
   free(p);
   return valore;
}



void stampa_coda(Nodo *p) {
    if (p == NULL)
      printf("la coda e' vuota\n\n");
   else {
      printf("La coda e' :\n");
      while (p != NULL) {
        printf("%d --> ", p->info);
        p = p->next;
       }
       printf("NULL\n");
   }
  }



main()
{
   PNodo inizio = NULL;
   PNodo fine = NULL;
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
            enqueue(&inizio, &fine, item);
            stampa_coda(inizio);
            break;
         case 2:
            if (!isEmpty(inizio)) {
               item=dequeue(&inizio, &fine);
               stampa_coda(inizio);
             }
            else
              printf("La coda e' vuota \n\n");
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
