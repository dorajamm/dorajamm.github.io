//FUNZIONAMENTO DI UNA CODA VETTORE//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 20

void menu(void)
{
    printf("\n\n Operazioni possibili:\n"
          "   1 per inserire un elemento nella coda (ENQUEQUE).\n"
          "   2 per estrarre un elemento dalla coda (DEQUEQUE).\n"
          "   0 per uscire.\n");
}
int IsEmpty(int head, int tail)//FUNZIONE CHE VERIFICA SE LA CODA E' VUOTA//
{
    return (head%SIZE) == (tail%SIZE);//E' VUOTA SOLO SE HEAD = TAIL//
}
int IsFull(int head, int tail)
{
    return (head%SIZE) == (tail%SIZE)+1;
}
void EnQueque(int Q[], int * head, int *tail, int val)
{
    if(! IsFull(*head, *tail)) {
        Q[*tail]=val;
        *tail=(*tail+1)%SIZE;
    }
    else{
       printf("Memoria esaurita!\n");
    }
}
int DeQueque(int Q[], int * head, int * tail)
{
    int valore;
    valore=Q[*head];//COPIO IL VALORE CHE VOGLIO ELIMINARE NELLA VARIABILE VALORE, PER POI FARMELO RIDARE//
    *head = (*head+1)%SIZE;
    return valore;

}
void StampaCoda(int Q[], int head, int tail)
{
    if(IsEmpty(head, tail))
    {
        printf("La coda e' vuota\n\n");
    }
    else
    {
        printf("La coda e':\n");

        while((tail)!=(head%SIZE))//FINTANTO CHE LA CODA NON E' VUOTA//
        {
            printf("%d-->", Q[tail-1]);
            tail=(tail-1)%SIZE;
        }
        printf("testa.\n");
    }
}
int main()
{
    int Coda[SIZE];
    int h=0;
    int t=0;
    int scelta;
    int item;
    menu();
    printf("operazione? ");
    scanf("%d", &scelta);
    while(scelta!=0)
    {
        switch(scelta)
        {
       case 1:
           printf("Inserisci un intero:\n");
           scanf("%d", &item);
           EnQueque(Coda, &h, &t, item);
           StampaCoda(Coda, h, t);
           break;
       case 2:
           if(! IsEmpty(h, t))
           {
             item=DeQueque(Coda, &h, &t);
             printf("Ho estratto l'elemento %d.\n", item);
             StampaCoda(Coda, h, t);
           }
           else
               printf("La pila e' vuota!\n\n");
           break;

       default:
        printf("Carattere inserito non valido");
        break;
        }
      printf("operazione? ");
      scanf("%d", &scelta);
    }

    printf("....BYE!\n");
    return 0;
}

