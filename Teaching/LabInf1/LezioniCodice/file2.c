#include<stdio.h>

int main ()
{
   FILE *fp;
   char *c;
   char str[20];
   fp = fopen( "prova3.txt" , "r" );
   c=fgets(str ,20, fp );
   while (c!='\0'){
      printf("\n ho letto dal file: %s   ",str);
      c=fgets(str ,20, fp );
   };
   fclose(fp);

   return(0);
}
 int fgetline(FILE *f, char line[], int maxlen) {
    int c, n = 0;
    do {
        c = fgetc(f);
        if (c != EOF && c != '\n' && n < maxlen)
            line[n++] = c;
    } while (c != EOF && c != '\n');
    line[n] = '\0';
    return n;
}
/*
 int fgetint(FILE *f) {
    int n;
    fscanf(f, "%d", &n);
    while (fgetc(f) != '\n');
    return n;
}
*/
