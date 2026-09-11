/* Copia una stringa usando la notazione con array o con puntatori
 */
#include <stdio.h>
// aggiungere in ogni funzione lo /0 nella stringa copiata!
void copy1(char *,  char *);
void copy2(char *,  char *);
void copy3(char s1[],  char s2[]);
void copy4(char s1[],  char s2[]);

int main()
{
   char string1[10], *string2 = "Hello",
        string3[10], string4[] = "GoodBye";

   printf("string2 = %s\n", string2);
   copy1(string1, string2);
   printf("string1 = %s\n\n", string1);

   printf("string4 = %s\n", string4);
   copy4(string3, string4);
   printf("string3 = %s\n", string3);
   return 0;
}

/* copy s2 to s1 using array notation */
void copy1(char *s1,  char *s2)
{
   int i;

   i=0;
   while (s2[i] != '\0'){
    s1[i] = s2[i];
    i++ ;
    }
}

/* copy s2 to s1 using pointer notation */
void copy2(char *s1,  char *s2)
{
   while (*s2 != '\0'){
      *s1 = *s2;
      s1++;
      s2++;
  }
}

/* copy s2 to s1 using pointer notation */
void copy3(char s1[],  char s2[])
{
   while (*s2 != '\0'){
      *s1 = *s2;
      s1++;
      s2++;
  }
}

/* copy s2 to s1 using array notation */
void copy4(char s1[],  char s2[])
{
   int i;

   i=0;
   while (s2[i] != '\0'){
    s1[i] = s2[i];
    i++ ;
    }
}
