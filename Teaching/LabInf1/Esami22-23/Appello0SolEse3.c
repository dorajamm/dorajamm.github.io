// soluzione ese 3 appello0 2023
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



void inserisciInTesta(PNodo *l, int el){
PNodo temp;
temp = (PNodo) malloc(sizeof(Nodo));
temp->info = el;
temp->next = *l;
*l=temp;
}


//restituisce 1 se sono disgiunti altrimenti 0
int disgiunti(PNodo l1, PNodo l2)
{
    if (l1==NULL || l2==NULL) return 1;
    while(l1!=NULL)
    {
        if(ricerca(l2,l1->info)==1)
            return 0;
        l1=l1->next;
    }
    return 1;
}

PNodo intersezione(PNodo l1, PNodo l2)
{
    PNodo inter, p;
    inter=NULL;
    while(l1!=NULL){
        if(ricerca(l2,l1->info)==1)
            inserisciInTesta(&inter,l1->info);
        l1=l1->next;
    }
    return inter;
}

PNodo intersezioneBis(PNodo l1, PNodo l2)
{
    PNodo inter, p;
    inter=NULL;
    while(l1!=NULL){
        p=l2;
        while ( p !=NULL){
            if (p->info == l1->info)
                inserisciInTesta(&inter,l1->info);
            p=p->next;
        }
        l1=l1->next;
    }
    return inter;
}
PNodo unione(PNodo l1, PNodo l2)
{
    PNodo uni, p;
    uni=NULL;
    p=l2;
    //inserisco tutta la lista L2
    while(p!=NULL)
    {
        inserisciInTesta(&uni,p->info);
        p=p->next;
    }
    // adesso aggiungo/inserisco tutti gli elementi di L1 che non sono in L2
    p=l1;
    while(p!=NULL)
    {
        if(ricerca(l2,p->info)==0)
            inserisciInTesta(&uni,p->info);
        p=p->next;
    }

    return uni;

}



int main(void)
{
    srand(time(NULL));
    Nodo  *l1, *l2, *inter, *uni;
    int x;
    l1 = crea_lista_rand();
    printf("\n La  lista generata e':\n");
    stampa_lista(l1);
    l2=crea_lista_rand();
    printf("\n La  lista generata e':\n");
    stampa_lista(l2);
   /*
    INSERIRE CHIAMATE ALLE FUNZIONI e stampare i risultati ottenuti
   */

   if(disgiunti(l1,l2)==0)
   {
       printf("l1 e l2 sono disgiunti");
   }
   else
   {
       printf("l1 e l2 non sono disgiunti");
       inter=intersezione(l1,l2);
       printf("\n l'intersezione e'\n");
       stampa_lista(inter);
   }
    printf("\n l'unione dei due insiemi e'");
    uni=unione(l1,l2);
    stampa_lista(uni);
}
