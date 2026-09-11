//Implementazione di una coda e delle operazioni
//di EnQueue e DeQueue utilizzando 2 pile//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 20

void menu(void)
{
    printf("\n\n Operazioni possibili:\n"
          "   1 per inserire un elemento nella coda (ENQUEQUE).\n"
          "   2 per estrarre un elemento dalla coda (DEQUEQUE).\n"
          "   3 per stampare le due pile.\n"
          "   0 per uscire.\n");
}

int isEmptyPila(int top)
{
   return top == -1;
}

int isFullPila(int top)
{
   return top == SIZE-1;
}
void push(int S[], int * top, int val) //inserimento nella pila di val
{
   if (! isFullPila(*top)) {
        *top = *top+1;
        S[*top] = val;
   }
   else
      printf("memoria esaurita!\n");
}



int pop(int S[], int *top) //estrazione di un elemento dalla pila
{
   int valore;
   valore = S[*top];
   *top = *top-1;
   return valore;
}








void stampaPila(int S[], int top) {
    if (isEmptyPila(top))
      printf("la pila e' vuota\n\n");
   else {
      printf("La pila e' :\n");
      while (top !=-1) {
        printf("%d --> ", S[top]);
        top = top-1;
       }
       printf("fine\n");
   }
  }


int IsEmptyCoda(int t1, int t2)
{
    return isEmptyPila(t1)&&isEmptyPila(t2);
}

int IsFullCoda(int t1, int t2)
{
    return isFullPila(t1)&&isFullPila(t2);
}
void EnQueue(int P1[],  int *t1, int val){
    push(P1, t1, val);
}
int DeQueue(int P1[], int *t1,int P2[],  int *t2)
{
    int valore;
    if ( isEmptyPila(*t2) ){ // se la pila2 è vuota
        while( ! isEmptyPila(*t1) )   //svuoto TUTTA la pila1 nella pila2
           push(P2, t2, pop(P1,t1));
     }
    pop(P2,t2);  // estraggo da pila2
}


int main()
{
    int pila1[SIZE];
    int pila2[SIZE];
    int top1=-1; // le due pile sono vuote
    int top2=-1;
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
           EnQueue(pila1,&top1,  item);
           break;
       case 2:
           if(! IsEmptyCoda(top1, top2)){
             item=DeQueue(pila1, &top1, pila2, &top2);
             printf("Ho estratto l'elemento %d.\n", item);
           }
           else
               printf("La pila e' vuota!\n\n");
           break;
        case 3:
            printf("\n \t Contenuto pila 1:  ");
            stampaPila(pila1,top1);
            printf("\n \t Contenuto pila 2:  ");
            stampaPila(pila2,top2);
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

