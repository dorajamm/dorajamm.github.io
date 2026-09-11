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




  PNodo crea_lista_rand(void) {
    Nodo *p, *start;
    int i, n;
    srand(time(NULL));

    start = NULL;
    printf("Numero di elementi? ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        p = malloc(sizeof(struct nodo));
        p->info=rand()%50+1;
        p->next = start;
        start = p;
    }
  return(start);
  }
PNodo crea_lista_inser(void) {
    Nodo *p, *start;
    int i, n, elem;

    start=NULL;

    printf("Numero di elementi? ");
    scanf("%d", &n);
for (i=0; i<n; i++) {
        p = malloc(sizeof(struct nodo));
        printf("\nInserisci elemento: ");
        scanf("%d", &elem);
        p->info=elem;
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
    Nodo  *l1, *l2, *l3;
    int i,j;
    l1 = crea_lista_rand();
    printf("\n La lista generata e':\n");
    stampa_lista(l1);
    l2=crea_lista_inser();
    /* la seconda lista è generata inserendo  da tastiera
    (inserimento in testa)così da poter generare i casi vari per
    testare il programma
    */

    printf("\n La lista generata e':\n");
    stampa_lista(l2);
   /*
    INSERIRE CHIAMATE ALLE FUNZIONI e stampare i risultati ottenuti
   */


    

    return(1);
  }
