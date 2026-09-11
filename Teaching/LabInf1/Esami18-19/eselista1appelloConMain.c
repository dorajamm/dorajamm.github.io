/* ese primo appello giugno 2019
Sia A = a0a1...an−1 una lista di interi: si vuole progettare una funzione che,
modifica la lista A trasformandola antemponendo la seconda met`a della lista alla prima met`a .
Pi`u precisamente la lista deve diventare:
a_n/2....an−1a0...an/2−1
1. Si definisca il tipo nodo lista adatto per la lista A.
2. Si implementi in C una funzione denominata ScambiaMezzeListe, che prende in input una lista A e
restituisce la lista A modificata come spiegato in precedenza. La funzione non deve creare nuovi nodi
ma deve utilizzare quelli della lista di input.
3. Si calcoli il costo della funzione sia in termini di tempo che di memoria supplementare utilizzata. */

#include<stdio.h>
#include<stdlib.h>

struct nodo{
int num;
struct nodo *next;
};

typedef struct nodo Nodo;
typedef Nodo *PNodo;




void scambiaMezzeListe(PNodo * a)
{   PNodo  s1,s2, p, q;
    int c=0; // contatore per elementi della lista

    s1=*a;
    //uso s1 per scorrere tutta la lista e contare gli elementi
    while(s1->next!=NULL){
       s1=s1->next;
       c++;
    }
    // all'uscita del while s1-next punta a NULL e lo facciamo puntare all'inizio della lista
    s1->next=*a;

    c=c/2;
    s1=*a;
    s2=s1->next;
    // riscorro la lista per c/2 elementi per arrivare a metà
    while( c>0){
        s1=s2;
        s2=s1->next;
        c--;
    }

    // a questo punto il nodo a metà sarà l'inizio lista mentre il nodo che lo precede
    // diventa l'ultimo della lista e il suo campo next deve puntare a NULL
    *a=s2;
    s1->next=NULL;
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
    PNodo lista=NULL;

    lista=crea_lista();
    printf("Ecco la lista generata random: \n  ");
    stampa_lista(lista);

    scambiaMezzeListe(&lista);
    printf("Ecco la lista richiesta dall'esame: \n  ");
    stampa_lista(lista);

}
