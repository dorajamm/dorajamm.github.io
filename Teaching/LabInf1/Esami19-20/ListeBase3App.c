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

void stampa_lista(Nodo *p) {
    while (p != NULL) {
        printf("%d --> ", p->info);
        p = p->next;
    }
  printf("NULL\n\n");
  }



int main(void) {
    Nodo *p, *l;
    int n;
    l = crea_lista_rand();
    printf("\n La lista generata e':\n");
    stampa_lista(l);

   /*
    INSERIRE CHIAMATA ALLA FUNZIONE
   */
     p=l; //per provare il codice senza la funzione porzione
      n=3;
    printf("\n La nuova lista modificata e':\n");
    stampa_lista(p);
    printf("\n Sono stati cancellati %d elementi:\n", n);
    return(1);
  }
