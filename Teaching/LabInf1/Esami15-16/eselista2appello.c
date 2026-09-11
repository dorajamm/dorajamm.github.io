/*
\textbf{Esercizio 1} (12 punti)\\
Si definisca un tipo nodo lista che contiene un campo per valori interi e un campo puntatore a tale nodo lista.
Si scriva poiuna funzione in C che, data una lista di interi positivi
$A =a_1, a_2, \ldots, a_n$,  genera una nuova lista $B= b_1, b_2, \ldots, b_n$ tale che $b_1=a_1$
 e per $i>1$, $b_i= b_{i-1} +a_i$ se $a_i$ \e pari e $b_i= b_{i-1} -a_i$ se $a_i$ \e dispari.
 */

#include<stdio.h>
#include<stdlib.h>

struct nodo{
int num;
struct nodo *next;
};

typedef struct nodo Nodo;
typedef Nodo *PNodo;

PNodo genera(PNodo a)
{   PNodo  b, p, temp;

    b= (PNodo) malloc(sizeof(Nodo)); //inizializzo b in modo che
    b ->num = a->num;                //il primo nodo di b è uguale a quello di a
    b ->next = NULL;

    a=a->next; //avanzo sulla prima lista:
    p=b; // assegno a p il primo elemento della seconda lista
         //userò p per scorrere la seconda lista

    while(a!=NULL) //scorro tutta la prima lista
    {
        temp = (PNodo) malloc(sizeof(Nodo)); //creo il nodo con il valore richiesto
        if(a->num %2 ==0)
            temp ->num = p->num + a->num;
        else
            temp ->num = p->num - a->num;
        temp ->next = NULL;

        p->next=temp; // metto tale nodo in coda alla seconda lista

        a= a->next; //avanzo nelle due liste
        p= p->next;

    }
    return b;
}
/*  ---- DA QUI IN POI E' PER PROVARE IL CODICE MA NON ERA RICHIESTO ALL'ESAME */


PNodo crea_lista(void) { //crea una lista di 10 elementi random tra 1 e 100
    Nodo *p, *temp;
    int i, n;
    p = NULL;
    srand(time(NULL));

    for (i=0; i<10; i++) {
        temp = (PNodo) malloc(sizeof(Nodo));
        temp ->num = 1 + rand()%10;
        temp ->next = p;
        p=temp;
    }
  return(p);
  }
void stampa_lista(PNodo p) {
    while (p != NULL) {
        printf("%d   --> ",  p->num);
        p = p->next;
    }
  printf("NULL\n");
  }

int main()
{   int x,y;
    PNodo lista1=NULL;
    PNodo lista2=NULL;

    lista1=crea_lista();
    printf("Ecco la lista generata random: \n  ");
    stampa_lista(lista1);

    lista2=genera(lista1);
    printf("Ecco la lista generata per l'esame: \n  ");
    stampa_lista(lista2);

}
