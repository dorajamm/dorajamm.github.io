/*
  Conversione di un carattere da minuscolo a maiuscolo
  Vale per la codifica ASCII
*/

#include <stdio.h>


main(){
  char minu,mai;
  int diff =32;

  printf("\n Conversione minuscolo-maiuscolo");
  printf("\n Introduci un carattere minuscolo: ");
  scanf("%c",&minu);
  if (minu>=97 && minu<=122) {
    mai = minu-diff;
    printf("\n Rappresentazione maiuscola %c",mai);
    printf("\n Codice ASCII %d",mai);
  }else
    printf("\n Carattere non convertibile");
}
