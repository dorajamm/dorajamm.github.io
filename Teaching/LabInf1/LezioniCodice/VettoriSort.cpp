/*
MINI PROGETTO SUL SORTING:
Completare tutte le parti mancanti del codice

Lo scopo è quello di confrontare vari algoritmi di sorting su vettori di lunghezza n= 30, 150, 500, 2000, (10000)
generare un vettore di lunghezza stabilita e applicare gli algoritmi sempre sullo stesso vettore (fare una copia prima di ordinarlo)

Di ogni algoritmo valutare il numero di confronti effettuati e il tempo in millisecondi.

Produrre una tabella per il numero dei confronti del tipo :
  n    | conf selection | conf bubble | conf insertion | tempo selection | tempo bubble | tempo insertion |
  30   |                |             |
  200  |                |             |                |                 |              |                 |
  500  |
  2000 |
  10000|

  Produrre una tabella per il tempo dei confronti del tipo :
  n    |tempo selection | tempo bubble | tempo insertion |
  30   |                |              |
  200  |                |              |                 |                 |              |                 |
  500  |
  2000 |
  10000|

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE1 30
//aggiungere le altre SIZE

/* Inizializza il vettore a di s elementi con numeri interi random tra 10 e 10000
*/
void IniziaRandom(int a[], int s)
{

}

/* Stampa il vettore a di s elementi visualizzando 10 elementi per riga.
   Utilizzare  printf("%10d", a[i]) per distanziare gli elementi.
ATTENZIONE: usare la stampa solo per la size piccola per provare gli algoritmi!
*/
void StampaVettore(int a[], int s)
{

}




/* Copia ordinatamente gli elementi del vettore a nel vettore b. Entrambi i vettori hanno s elementi
*/
void copiaVettore(int a[], int b[], int s)
{

}




/*  Ordina il vettore a di s elementi utilizzando l'algoritmo bubblesort.
    Restituisce il numero di confronti effettuati tra elementi del vettore
*/
int bubbleSort(int a[], int s)
{


}

/*  Ordina il vettore a di s elementi utilizzando l'algoritmo selectionsort.
    Restituisce il numero di confronti effettuati tra elementi del vettore
*/
int SelectionSort(int a[], int s)
{


}

/*  Ordina il vettore a di s elementi utilizzando l'algoritmo Insertionsort.
    Restituisce il numero di confronti effettuati tra elementi del vettore
*/
int InsertionSort(int a[], int s)
{

}






int main()
{
   int vett[SIZE1], vett1[SIZE1];
   // vett sarà il vettore generato, vett1 una sua copia per provare l'algoritmo di sorting


   // aggiungere i vettori corrispondenti per le altre size

   int bconf, sconf, iconf; // numero confronti di bubble, selection e insertion
   int btime, stime, itime; // tempo in millisecondi di bubble, selection e insertion

   IniziaRandom(vett,SIZE1);
   printf("Il vettore generato per il test e': \n\n");
   StampaVettore(vett,SIZE1);
   //eseguire le stampe solo per controllare l'algoritmo di ordinamento e solo su size piccoli

   copiaVettore(vett,vett1,SIZE1);
   bconf=bubbleSort(vett1,SIZE1);

   printf("Il vettore ordinato con bubblesort e': \n\n");
   StampaVettore(vett1,SIZE1);
    //eseguire le stampe solo per controllare l'algoritmo di ordinamento e solo su size piccoli,
    //poi eliminare le istruzioni

   /*
   aggiungere le istruzioni per calcolare il tempo

   ripetere le 4 istruzioni precedenti + quelle per il tempo
   per ordinare nuovamente il vettore vett con gli altri algoritmi
   */


  //stampare intestazione tabella

   //Stampare il numero di confronti effettuati per ordinare lo stesso vettore dai vari algoritmi utilizzati
   // (variabili bconf, iconf, sconf)
 //Stampare il tempo passato per ordinare lo stesso vettore dai vari algoritmi utilizzati
  // (variabili btime, itime, stime)

   //rieseguire  il tutto con una diversa size e stampare risultati a seguire nella tabella
	return(0);
}
