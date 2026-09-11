/* mcd-game */
#include <stdio.h>


int MCD ( int a, int b )
{
    int r;
    while (b!=0)
    {
       r=a%b;
       a= b;
       b=r;
    }
    return a;
}
int main()
{
    int x,y;
    int risul;


   printf("Benvenuti al corso di Programmazione in C!\n\n");
   printf("Inserisci i due numeri di cui vuoi calcolare il massimo comune divisore: \n");

   printf("Primo numero: ");
   scanf("%d",&x);

   printf("Secondo numero: ");
   scanf("%d",&y);

    risul=MCD(x,y);

    printf("Il Massimo Comune Divisore tra %d e %d  e': %d \n",x, y,risul);



}


