/*
   Dimostrazione uso funzioni: Stampa quadrati vari di lato 3-30 con utilizzo menu di selezione per la tipologia di quadrato.
*/
#include <stdio.h>

void stampaRiga(char simb, int lung)
 {     int i;
     for ( i= 1; i <= lung; i++)
         printf("%c", simb);
 }

 void stampaQuadratoPieno( int lato)
 {   int i;
     for (  i= 1; i <= lato; i++){
          stampaRiga('*',lato);
          printf("\n");
          }
      printf("\n\n");
  }

 void stampaQuadratoVuoto( int lato)
 {    int i;
      stampaRiga('*',lato); //lato superiore
      printf("\n");

      for ( i= 1; i <= lato-2; i++){  // parte interna
          printf("*");
          stampaRiga(' ',lato-2);
          printf("*");
          printf("\n");
      }

      stampaRiga('*',lato); //lato inferiore
      printf("\n\n");
  }

void stampaQuadratoDiag( int lato)
 {   int i;
     for ( i= 1; i <= lato; i++){
          stampaRiga('*',i);
          stampaRiga('o',lato-i);
          printf("\n");
          }
     printf("\n\n");
  }


void Menu()
{

    printf("\t Scrivi 1 per disegnare un quadrato pieno \n");
    printf("\t Scrivi 2 per disegnare un quadrato vuoto \n");
    printf("\t Scrivi 3 per disegnare un quadrato diviso in due triangoli \n");
    printf("\t Scrivi 0 per uscire \n\n");
    return ;
}

int InputInRange( int x, int y)
{   int num;
    do{
       printf("scrivi un valore tra %d e %d: \t",x,y);
       scanf("%d",&num);
       }
    while (num < x || num >y);
    return num;
}

int main()
{
    int scelta;
    int lungh;

    do{
    Menu();
    scelta= InputInRange(0,3);   // selezione il tipo di quadrato
    if (scelta ==0)
        printf("arrivederci! \n");
    else
    {
        printf("adesso inserisci la misura del lato del quadrato \n");
        lungh= InputInRange(3,30);

        switch(scelta){
            case 1:
                stampaQuadratoPieno(lungh);
                break;
            case 2:
                stampaQuadratoVuoto(lungh);
                break;
            case 3:
                stampaQuadratoDiag(lungh);
                break;
        }
    }
    }
    while(scelta != 0);
	return(0);
}
