#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 35

void IniziaRandom(int a[], int s, int ini, int fin)
{
   int j;
   srand(time(NULL));

   for (j = 0; j < s ; j++)
      a[j] = rand() % (fin-ini+1) + ini ;
}
void StampaVettore(int a[], int s)
{
    int i;
    for (i = 0; i < s ; i++){
      if (i%7 ==0)     printf("\n\n");
      printf("%5d", a[i]);
    }
    printf("\n\n");
}
double Media(int a[], int s)
{
  int k , som=0;
  double med;
  for(k=0 ; k<s ; k++){
    som=som+a[k];}
  med=(double)som/s;
  return(med);
}
int minimo(int a[], int s)
{ //calcola l'indice del minimo
    int k, m;
    m=0;
    for(k=1 ; k<s ; k++)
    {
        if(a[k]<a[m])
           m=k;
    }
    return(m);
}
int consecutiv(int a[], int s)
{ // restituisce l'indice del primo elemento di
  //  una coppia di elementi consecutivi oppure -1
    int j , c=-1;
    for(j=0 ; j<s-1 ; j++)
    {
        if(a[j+1]==a[j])
            c=j;
    }
    return(c);
}
int numid(int a[], int s)
{
    int i, j, diver=1; //diver=1 se sono tutti diversi
    i=0;
        while(( i<s-1)&& diver==1){
            for(j=i+1; j<s ; j++){
                if(a[i]==a[j])
                    diver=0;
            }
            i++ ;
        }

     return(diver);
    }




int main()
{
   int vett[SIZE];
   int min;
   float media;

   IniziaRandom(vett,SIZE, 15, 85); //GENERA IL VETTORE

   StampaVettore(vett,SIZE); //STAMPA IL VETTORE

   media= Media(vett, SIZE);
   printf("La media e' %f\n",media ); //CALCOLA LA MEDIA

   min=vett[minimo(vett, SIZE)];
   printf("Il minimo tra i numeri e' %d\n",min ); //CALCOLA IL MINIMO

   if(consecutiv(vett, SIZE)==-1)                                //NUMERI CONSECUTIVI
    printf("Non ci sono numeri consecutivi uguali\n");
   else
    printf("Il numero %d compare due volte consecutive\n",
            vett[consecutiv(vett,SIZE)]);

   if(consecutiv(vett,SIZE)!=-1 || numid(vett,SIZE)==0)     //NUMERI UGUALI NELLA SERIE
    printf("Ci sono numeri uguali\n");
   else
    printf("Non ci sono numeri uguali\n");


}
