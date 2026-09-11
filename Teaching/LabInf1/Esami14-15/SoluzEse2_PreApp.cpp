
#include <stdio.h>
#include <time.h>
#define SIZE_F 60
#define SIZE_P 6

// controllo se la parola y è contenuta in x a partire dalla posizione h
int controlloParola (char *x, char *y, int h ){
    int k=0;
    int trovata=1;
    while(trovata && y[k]!='\n')
        if (x[h+k] == y[k])
            k++;
        else
            trovata=0;
    return trovata;

}
int main()
{
    char f[SIZE_F];
    char p[SIZE_P];
    int lp=0; // per la lunghezza della parola p
    int i,j;
    printf("Inserire una frase:   ");
    fgets(f,SIZE_F,stdin);
    printf("Inserire una parola:   ");
    fgets(p,SIZE_P,stdin);

    lp=0;
    while(p[lp]!='\n'){ // calcolo la lunghezza di p
     lp++;
    }
    i=0;
    while (f[i]!='\n') // scorro la frase
    {
        if (controlloParola(f,p,i) ){ //se la parola è contenuta per intero
            for (j=0; j<lp; j++)
                f[i+j]='*'; // la sostituisco con *
            i=i+lp;
            }       // sposto l'indice i alla fine dei *
        else
        i++;               // altrimenti incremento indice solo di 1
    }


   // stampo la parola modificata
    printf("\n %s", f);

    return 0;
}

