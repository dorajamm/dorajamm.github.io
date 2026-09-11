#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
   srand(time(NULL));
   int i, j;
   int max1, max2;
   struct squadre
    {
        char * nome;
        int punteggio;
    };
   typedef struct squadre Squadra;

     //definisco un array di stringhe cioè char *
     char * nomi[6]={"atalanta", "bologna",  "chievo", "empoli","sassuolo",  "palermo"};


    // definisco un array di "squadre"
    Squadra Campionato[6];
    //inizializzazione
    for(j=0; j<6; j++){
         Campionato[j].nome=nomi[j];
          Campionato[j].punteggio=rand()%20;
    }

    //stampa
    for(j=0; j<6; j++){
       printf("%s %d\n", Campionato[j].nome, Campionato[j].punteggio);
    }

    //calcolo vincitore
    max1=0;
    for(j=1; j<6; j++){
            if (Campionato[j].punteggio > Campionato[max1].punteggio)
                max1= j;
    }
        printf("\n\n La squadra che ha vinto il campionato e': %s  con %d punti\n", Campionato[max1].nome, Campionato[max1].punteggio);



}
