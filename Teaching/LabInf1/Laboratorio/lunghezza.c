#include <stdio.h>

int lung( char *);

int main()
{
   char string1[80];
   int x;

   printf("Scrivi una stringa: ");
   gets( string1);
   //scanf("%s",string1);

   x=lung(string1);

   printf("La  stringa inserita e': %s\n",  string1);
   printf("La lunghezza della stringa inserita e': %d\n", x);

   return 0;
}

int lung( char *s)
{
   int x = 0;

   for ( ; *s != '\0'; s++)
      ++x;

   return x;
}

