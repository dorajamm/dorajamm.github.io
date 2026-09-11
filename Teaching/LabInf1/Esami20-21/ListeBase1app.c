/*
programma base per liste
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

 struct nodo {
  int info;
  struct nodo *next;
  };

  typedef struct nodo Nodo;
  typedef  Nodo *PNodo;


  void insOrdine(PNodo *inizio, int val) //inserimento in ordine
{
   PNodo p, q1,q2;

   p = (PNodo) malloc(sizeof(Nodo));
   if (p == NULL) {
       printf("memoria esaurita!\n");
       return;
   }

    p->info = val; //prepare un nuovo nodo
    p->next = NULL;

    if ((*inizio == NULL) || ((*inizio)->info > val))  {
        // la lista  è vuota o il primo elemento è maggiore e devo comunque insierire all'inizio
        p->next = *inizio;
        *inizio = p;
    }
    else{
    q1= *inizio;
    q2= q1->next;

    while ( (q2 !=NULL)  &&(q2->info < val)   ){ //vado avanti finche' trovo la posizione o fine lista
        q1= q2;
        q2= q1->next;
        }

    q1->next = p;
    p->next =q2;
   }
}




  PNodo crea_lista_rand(void) {
    Nodo *p, *start;
    int i, n,x;
    srand(time(NULL));

    start = NULL;
    printf("Numero di elementi? ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
         x=1 + rand()%7;
        insOrdine(&start,x);

    }
  return(start);
  }

void stampa_lista(Nodo *p) {
    while (p != NULL) {
        printf("%d --> ", p->info);
        p = p->next;
    }
  printf("NULL\n\n");
  }



int main(void) {
    Nodo *p, *l;
    int i,j;
    l = crea_lista_rand();
    printf("\n La lista generata e':\n");
    stampa_lista(l);

   /*
    INSERIRE CHIAMATA ALLA FUNZIONE RICHIESTA e stampa dei risultati
   */

    return(1);
  }
