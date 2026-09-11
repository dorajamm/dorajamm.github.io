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



int ricerca(PNodo l, int val)
{
   PNodo temp, q1,q2;
   while ( l !=NULL){
        if (l->info == val)
            return 1;
        l=l->next;
    }
    return 0;
}


  PNodo crea_lista_rand(void) {
    Nodo *p, *start;
    int i, n, val ;


    start = NULL;
    n=rand()%20+4;

    for (i=0; i<n; i++) {
        do
            val=rand()%50+1;
        while (ricerca(start, val)==1);
        p = malloc(sizeof(struct nodo));
        p->info=val;
        p->next = start;
        start = p;
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
    srand(time(NULL));
    Nodo  *l1, *l2;

    l1 = crea_lista_rand();
    printf("\n La  lista generata e':\n");
    stampa_lista(l1);
    l2=crea_lista_rand();
    printf("\n La  lista generata e':\n");
    stampa_lista(l2);
   /*
    INSERIRE CHIAMATE ALLE FUNZIONI e stampare i risultati ottenuti
   */



    return(1);
  }
