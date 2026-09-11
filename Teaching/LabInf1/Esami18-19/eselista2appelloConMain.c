/* ese secondo appello luglio 2019
Sia $A = a_0a_1 . . . a_{n-1}$ una lista e $i, j, k$ tre interi: si vuole progettare una
funzione che, nel caso $ 0 \leq i < j < k \leq n$, modifica la lista $A$
trasformandola scambiando le posizioni delle sotto-liste $a_i a_{i+1} . . . a_{j-1}$
e $a_j a_{j+1} . . . a_{k-1}$, ovvero deve restituire:

\begin{tabular}{ll}
$a_0 . . . a_{i-1}a_ja_{j+1} . . . a_{k-1}a_ia_{i+1} . . . a_{j-1}a_k . . . a_{n-1}$  \hspace{2cm}& se $0 < i < j < k < n$\\
$a_j a_{j+1} . . . a_{k-1}a_i a_{i+1} . . . a_{j-1}a_k . . . a_{n-1}$ & se $0 = i < j < k < n$\\
$a_0 . . . a_{i-1}a_ja_{j+1} . . . a_{k-1}a_i a_{i+1} . . . a_{j-1}$ & se $ 0 < i < j < k = n$\\
$a_j a_{j+1} . . . a_{k-1}a_ia_{i+1 }. . . a_{j-1}$ & se $0 = i < j < k = n$\\
$A$ & altrimenti.
\end{tabular}
1.Si definisca il tipo nodo lista adatto per la lista $A$.
2. Si implementi in C una funzione denominata {\tt ScambiaSottoliste}, che prende in input una lista $A$
e tre interi $i, j, k$ e restituisce la lista a modificata come spiegato in precedenza. La funzione non deve
creare nuovi nodi ma deve utilizzare quelli della lista di input.
*/

#include<stdio.h>
#include<stdlib.h>

struct nodo{
int num;
struct nodo *next;
};

typedef struct nodo Nodo;
typedef Nodo *PNodo;




void scambiaSottoListe(PNodo * a, int i, int j, int k)
{   PNodo  pi,qi, pj, qj, pk,qk;
    int c=0; // contatore per elementi della lista

    if (i!=0){
    pi=*a;
    qi=pi->next;
    for(c=1; c<i; c++){
        pi=qi;
        qi=pi->next;   }
                //pi punta all'elemento a(i-1) e qi punta all'elemento a(i)
    }
    else{
        qi=*a; // in questo caso voglio partire da a(0)
    }
    pj=qi;
    qj=pj->next;
    for(c=i+1; c<j; c++){
        pj=qj;
        qj=pj->next;   }
                //pj punta all'elemento a(j-1) e qj punta all'elemento a(j)
    pk=qj;
    qk=pk->next;
    for(c=j+1; c<k; c++){
        pk=qk;
        qk=pk->next;  }
                //pk punta all'elemento a(k-1) e qk punta all'elemento a(k)
                // nota se k=n, l'elemento a(k) = NULL e quindi qk->NULL
    if (i>0)
        pi->next = qj;

    else // se i=0 la lista deve cominciare da a(j) quindi devo riassegnare *a
        *a = qj;
    pk->next = qi;
    pj->next = qk;

}


/*  ---- DA QUI IN POI E' PER PROVARE IL CODICE MA NON ERA RICHIESTO ALL'ESAME */


PNodo crea_lista_ord(void) { //crea una lista di 15 elementi tra 0 e 14
    Nodo *p, *temp;
    int i, n;
    p = NULL;
    srand(time(NULL));

    for (i=14; i>=0; i--) {
        temp = (PNodo) malloc(sizeof(Nodo));
        temp ->num = i;
        temp ->next = p;
        p=temp;
    }
  return(p);
  }
void stampa_lista(PNodo p) {
    while (p != NULL) {
        printf("%d -> ",  p->num);
        p = p->next;
    }
  printf("NULL\n");
  }

int main()
{   int x,y,z;
    PNodo lista=NULL;

    lista=crea_lista_ord();
    printf("Ecco la lista iniziale: \n  ");
    stampa_lista(lista);

     printf("Inserisci i tre punti (tra 0 e 15) dove spezzare la lista separati da spazi: ");
     scanf("%d %d %d", &x,&y,&z);

    scambiaSottoListe(&lista, x,y,z);
    printf("\n Ecco la lista scambiata richiesta dall'esame: \n  ");
    stampa_lista(lista);

}
