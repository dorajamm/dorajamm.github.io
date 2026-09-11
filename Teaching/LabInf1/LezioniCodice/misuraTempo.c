#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
ESEMPIO DI VALUTAZIONE TEMPO DI CALCOLO DI UN PROGRAMMA.

La funzione clock() consente di ottenere il tempo di utilizzo del
microprocessore (CPU), espresso virtualmente in cicli di CPU.
In pratica, viene definita la macro-variabile CLOCKS_PER_SEC,
contenente il valore che esprime convenzionalmente la quantità di cicli
di CPU per secondo; quindi, il valore restituito dalla funzione clock()
si traduce in secondi dividendolo per CLOCKS_PER_SEC.

Il valore restituito dalla funzione clock() e il valore
CLOCKS_PER_SEC sono di tipo clock_t.


Per valutare l'intervallo di tempo di utilizzo della CPU, da una certa
posizione del programma, a un'altra,
occorre memorizzare i valori ottenuti dalla funzione clock()
e poi procedere a una sottrazione.
*/
void stampaTempo(clock_t mill){
    int sec,min;
    if (mill> 999){
        printf("\n\n\n .. o meglio...\n");
        sec=  mill/1000;
        if (sec < 59)
        printf("\n Tempo impiegato: %d secondi", sec);
        else{
            min=   sec/60;
            printf("\n Tempo impiegato: %d minuti", min);
        }
    }

printf("\n\n\n\n");

}


int main()
{    clock_t start,  fine;
     int millisec, tempo;

    int i,j,s;

    /* per vedere il valore della costante CLOCKS_PER_SEC */
    printf("\n costante  CLOCKS_PER_SEC: %d \n\n", CLOCKS_PER_SEC);



	/*prendere il tempo di inizio (in variabile start): */
	 start = clock();
    printf("\n Tempo iniziale: %d clock_t", start);

printf("\n eseguo il programma .....\n\n");
	/*Esegui le istruzioni di cui vuoi misurare il tempo di esecuzione*/
	s=0;
	for (i=0; i<= 500000000; i++)
        //for (j=0; j<= 10  ; j++)
        s=s;

	/*prendere il tempo di fine (end)  */
	 fine = clock();
    printf("\n Tempo finale: %d clock_t", fine);

	/*converte il tempo trascorso  in millisecondi.  */
	millisec = (fine - start)*1000/CLOCKS_PER_SEC;
	printf("\n Tempo impiegato: %d millisec", millisec);




	stampaTempo(millisec);
}



