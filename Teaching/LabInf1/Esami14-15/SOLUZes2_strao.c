#include<stdio.h>
#include<stdlib.h>

/*Soluzione sercizio 2 prova di Laboratorio appello 23/11/2015 */


int main () /*ho creato un vettore di massimo 20 caratteri, ho copiato le sue i- componenti in un altra stringa e l ho concatenata con la sua reverse, poi ho stampato la stringa modificata*/
{
    int i, j, k;
    char v[21];/*creo una stringa di dimensione 21, perchè c' è anche il carattere nullo di terminazione*/

    printf ("introduci una stringa di massimo 20 caratteri, se vuoi terminare introduci'zzz':\n");
    scanf("%s", v);


    while (v[0]!='z' || v[1]!='z' || v[2]!='z')  {
       k=0;
       for (i=0; v[i]!='\0'; i++)
        {
            k++; /*k è la lunghezza della stringa*/
        }

    char palv[2*k+1]; // stringa di lunghezza doppia di v dove creo la palindroma
    for (j=0; j<k; j++)
    {
       palv[j]=v[j]; // ricopio v nelle prime k posizioni
       palv[2*k-j-1]=v[j]; //ricopio v al contrario nellu ultime k posizioni cioè a partire da 2k-1
    }
    palv[2*k]='\0'; // metto il carattere di terminazione alla fine
    printf ("la stringa modificata e': %s\n", palv);

    printf ("\n\nIntroduci una stringa di massimo 20 caratteri, se vuoi terminare introduci'zzz':\n");
    scanf("%s", v);

 }

}




