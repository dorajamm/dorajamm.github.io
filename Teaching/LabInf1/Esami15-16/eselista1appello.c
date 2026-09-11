/*
\textbf{Esercizio 1} (2+10=12 punti)\\
Una frazione si dice \emph{irriducibile} se il numeratore e il denominatore non hanno divisori comuni cio\'e sono coprimi. Inoltre,
si assuma gi\a definita una funzione \texttt{int MCD(int x, int y)} per il calcolo del Massimo Comune Divisore.

\bigskip
\noindent
Sia $L$ una lista di frazioni rappresentate come coppie di interi  corrispondenti al numeratore e al denominatore.
\begin{enumerate}
\item Si definisca il tipo nodo lista che contiene i due campi  per memorizzare rispettivamente numeratore e denominatore suddetti.

 \item Si scriva una funzione  \texttt{semplifica} che, prende in input una lista  $L$ di frazioni e ne produce/restituisce un'altra che contiene tutte le frazioni irriducibili equivalenti a quelle della lista $L$. Pi\u precisamente: se una frazione $f$ di $L$ \e irriducibile andr\a inserita direttamente nella nuova lista, se invece $f$ pu\o essere semplificata in una frazione irriducibile equivalente $f'$, allora nella nuova lista bisogner\a inserire $f'$.
\\
\underline{NOTA}: Gli elementi della nuova lista potranno trovarsi anche in un diverso ordine rispetto a quello  che hanno in $L$.
*/

#include<stdio.h>
#include<stdlib.h>

struct nodo{
int num;
int den;
struct nodo *next;
};

typedef struct nodo Nodo;
typedef Nodo *PNodo;
int MCD(int a, int b);

void Inserisciintesta(PNodo *l, int num1, int num2)
{
    PNodo temp;
    temp=(PNodo) malloc(sizeof(Nodo));
    temp->num=num1;
    temp->den=num2;
    temp->next=(*l);

    *l=temp;
}

void semplifica(PNodo *l, PNodo *l1)
{
   //Suppongo data la lista puntata da l e inizializzata la lista puntata da l1

    PNodo p;

    p=(*l);
    while(p!=NULL)
    {
        if(MCD(p->num, p->den)==1)
            Inserisciintesta(l1, p->num, p->den);

        else
            Inserisciintesta(l1, (p->num)/MCD(p->num, p->den), (p->den)/MCD(p->num, p->den));

        p=p->next;

    }
}
/*  ---- DA QUI IN POI E' PER PROVARE IL CODICE MA NON ERA RICHIESTO ALL'ESAME */
int MCD(int a, int b)
{
 int r;
    while (b!=0)
    {
       r=b;
       b=a%b;
       a=r;
    }
    return r;
}
void stampa_lista(PNodo p) {
    while (p != NULL) {
        printf("%d / %d  --> ",  p->num, p->den);
        p = p->next;
    }
  printf("NULL\n");
  }

int main()
{   int x,y;
    PNodo l=NULL;
    PNodo l1=NULL;

    printf("Inserisci alcuni elementi nella lista 0, 0 per terminare:  ");
    scanf( "%d%d", &x, &y );
    while (x!=0 && y!=0){
        Inserisciintesta(&l, x, y);
        printf("Inserisci alcuni elementi nella lista 0, 0 per terminare:  ");
        scanf( "%d%d", &x, &y );
    }

    stampa_lista(l);
    semplifica(&l, &l1);
    stampa_lista(l1);
}
