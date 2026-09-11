#include<stdio.h>

int main ()
{
   FILE *fp;
   char str[] = "Benvenuti alla lezione sui file in C!";
   char risp;

   fp = fopen( "prova3.txt" , "w" );
  //printf("\n scrivi una stringa:   ");
   do{
   // getchar();
     printf("\n scrivi una stringa:   ");
     gets(str);

     fputs(str , fp );
     fputc('\n',fp);
     printf("\n Vuoi scriverne un'altra? (s/n):   ");
     risp=getchar();
     getchar();
   }while (risp!='n');
   fputc(EOF,fp);
   fclose(fp);

   return(0);
}

