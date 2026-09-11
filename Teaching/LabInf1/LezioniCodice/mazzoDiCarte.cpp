/* Programma per mescolare le carte */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct carta {
   int val;
   char *seme;
};

typedef struct carta Carta;

void inizializza(Carta m[]);
void mescola(Carta m[]);
void stampaCarta(Carta c);
void stampaMazzo(Carta m[]);
main()
{
   Carta mazzo[40];


   srand(time(NULL));

   inizializza(mazzo);
   printf("\nIl mazzo ordinato e': \n\n");
   stampaMazzo(mazzo);
   mescola(mazzo);
   printf("\nIl mazzo dopo aver mescolato e': \n\n");
   stampaMazzo(mazzo);
   return 0;
}

void inizializza(Carta m[])
{
   int i;

   for (i = 0; i < 10; i++) {
      m[i].val = i+1;
      m[i].seme = "oro";
      m[10+i].val = i+1;
      m[10+i].seme = "coppe";
      m[20+i].val = i+1;
      m[20+i].seme = "spade";
      m[30+i].val = i+1;
      m[30+i].seme = "mazze";
   }
}

void mescola(Carta m[])
{
   int i, j;
   Carta temp;

   for (i = 0; i < 40; i++) {
      j = rand() % 40;
      temp = m[i];
      m[i] = m[j];
      m[j] = temp;
   }
}
void stampaCarta(Carta c)
{

      printf("%5d di %-8s \n", c.val, c.seme);
}

void stampaMazzo(Carta m[])
{
   int i;

   for (i = 0; i < 40; i++)
      stampaCarta( m[i]);
}

