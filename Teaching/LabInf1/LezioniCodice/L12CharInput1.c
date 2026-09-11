/*
  Inserimento di un char dopo un int ----- attenzione!
  usa  getchar(); o scanf("%c",&risposta); dopo lo scanf di un int
*/

#include <stdio.h>


main(){
  char risposta;
  int num;

  printf("\n Inserisci un numero:");
  scanf("%d",&num);
  printf("\n Bene.. vedo che hai inserito il numero %d ", num);

    printf("\n Vuoi continuare ad inserire? (s/n):");
getchar();
  scanf("%c",&risposta);
  if (risposta=='s'){
    printf("\n Bene.. hai risposto SI");


  }

  if (risposta=='n')
    printf("\n .. hai risposto NO.. dunque ...arrivederci!");

printf("\n\n\n\n");
}
