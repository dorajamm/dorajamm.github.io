
#include <stdio.h>

int prefisso( char *,  char *);

main()
{
   char string1[80], string2[80];



   printf("Scrivi due stringhe:\n");
   scanf("%s%s", string1, string2);
   if (prefisso(string1, string2))
       printf("La prima stringa e' prefisso della seconda" );
   else
        printf("La prima stringa NON e' prefisso della seconda" );
   return 0;
}

int prefisso( char *s1,  char *s2) /* restituisce 1 se una stringa è prefisso dell'altra, 0 altrimenti */
{
   while (  *s1 != '\0' && *s2 != '\0'){
    if (*s1 != *s2)
         return 0;
     s1++; s2++;}
   return 1;
}

