/*scrivere un programma che richiede all'utente di inserire 5 numeri
interi corrispondenti ai voti di esami superati (valori tra 18 e 30)
e poi scrive sullo schermo  la media */

#include<stdio.h>
int main()
{
  int voto,somma=0,i;
  float media;
  printf("Questo programma calcola la media tra i voti di 5 esami\n");
  for(i=0; i<5; i++){
    do{
      printf("inserisci il voto\n");
      scanf("%d",&voto);}
    while(voto< 18 || voto >30); /* controllo correttezza input */
                /* attenzione bisogna usare la condizione contraria! */
      somma = somma + voto;
  }

  media = (float) somma/5;
  printf("\nla media dei tuoi esami e' %.2f",media);
 }
