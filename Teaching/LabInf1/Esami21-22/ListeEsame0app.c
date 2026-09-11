/*
programma base per esercizio d'esame sulle liste
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




  PNodo crea_lista(void) {
    Nodo *p, *q, *start;
    int  n;

    start=NULL;
    printf("Inserisci numeri interi positivi e negativi (0 per terminare): \n", n);
    scanf("%d", &n);
    if (n!=0){
        start=malloc(sizeof(struct nodo));
        start->info=n;
        start->next = NULL;
        q=start;
        scanf("%d", &n);
        while (n!=0) {
            p = malloc(sizeof(struct nodo));
            p->info=n;
            p->next = NULL;
            q->next = p;
            q=q->next;
            scanf("%d", &n);
    }
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
    l = crea_lista();
    printf("\n La lista generata e':\n");
    stampa_lista(l);

   /*
    INSERIRE CHIAMATA ALLA FUNZIONE e stampa dei risultati
   */

    return(1);
  }
