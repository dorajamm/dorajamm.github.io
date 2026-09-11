#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*Soluzione sercizio 1 prova di Laboratorio appello 23/11/2015 */




int baricentro (int v[], int n, int *k)
{
    int i, som1, som2;

    som1=v[0];   //inizializzo le due somme
    som2=0;
    for(i=1; i<n; i++)
        som2= som2+v[i];

    i=1;
    while (som1!=som2 && i<n-1){
        som1=som1+v[i];
        som2=som2-v[i];
        i++;
    }

    if(som1== som2){ // le somme sono uguali, allora i è un baricentro e lo assegno alla variabile k*/
            *k=i;
            return 1;
    }
    else
            return 0;

    }

/*genero la rotazione r del vettore v[]  */
void rotazione (int v[], int n, int r)
{
    int i, j, temp[n];

    for(i=0;i<n;i++) //genero una copia "temporanea del vettore v
        temp[i]=v[i];

    i=0;
    for (j=r; j<n;j++ ) { //copio gli elementi da r a n all'inizio
        v[i]=temp[j];
        i++;
    }
    for (j=0; j<r;j++ ){ //copio gli elementi da 0 a r a seguire
        v[i]=temp[j];
        i++;
    }
}


int main(){
    int a, b, temp;
    int i;
    int bar=0,r;
    int v[20]={0}; /* vettore nullo dove immettere i valori random compresi tra a e b*/

    srand( time( NULL ));
    printf ("Immetti gli estremi dell' intervallo di valori interi per generare un vettore:\n");
    scanf ("%d%d", &a, &b);
    if (b<a){/*se b è minore di a, scambio gli estremi dell' intervallo*/
        temp=b;
        b=a;
        a=temp;
    }

    for (i=0; i<20; i++){
        v[i]=(rand() % (b-a+1))+a; /*genero un vettore con elementi compresi nell intervallo chiuso [a,b]*/
    }

    printf("Il vettore generato e':\n");
    for (i=0;i<20;i++){
        printf("%3d", v[i]);/*stampo il vettore sullo schermo*/
    }


    if (baricentro(v,20,&bar)==1){
        printf("\n Il vettore ha  un baricentro in %d\n", bar);
    }
    else
    {
         printf("\n Il vettore NON ha  un baricentro ... controllo le sue rotazioni");
         r=1;

         while( r<20){  //genero tutte le rotazione di v, partendo da 1,
            rotazione (v, 20, r);
            if (baricentro(v,20,&bar)==1){
               printf("il vettore con rotazione %d ha  un baricentro in %d\n", r, bar);
               return;
            }
            r++;
         }
         printf("\nNon ho trovato nessuna rotazione che ammette baricentro");
    }

}

