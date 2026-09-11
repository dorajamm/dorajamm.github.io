/*
Gestione lista di  numeri
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
  typedef  Nodo * PNodo;
 // typedef  Nodo *Lista; un puntatore a un nodo è una lista!



PNodo crea_lista(int s) {
    Nodo  * inizio; // o alternativamente PNodo inizio;
    Nodo * temp;
    int i, n;
    inizio = NULL;

    srand(time(NULL));

    for (i=0; i<s; i++) {
        n=1 + rand()%100;

        temp = (PNodo) malloc(sizeof(Nodo));
        temp->info = n;
        temp->next = inizio;
        inizio=temp;

    }
  return(inizio);
  }





void stampa_lista(PNodo p) {
    while (p != NULL) {
        printf("%d --> ", p->info);
        p = p->next;
    }
  printf("NULL\n");
  }



main()
{
   PNodo pstart = NULL;

   int s;

   printf("Quanti elementi vuoi inserire nella lista?:   ");
   scanf("%d",&s);

   printf("\n\n Ecco una lista  di %d interi  generata casualmente: \n\n ",s);

   pstart=crea_lista(s);
   stampa_lista(pstart);


   return 0;
}
