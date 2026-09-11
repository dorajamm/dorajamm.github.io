//File di record: scrive il contenuto di un
//vettore di record (inizializzato con dati
//forniti da stdin) in un file binario dato da input.
#include <stdio.h>
#include <ctype.h>
#define DIM 5
typedef struct {
    char nome[15];
    char cognome[15];
    int eta;
} Persona;

 int crea_vettore(Persona V[], int dim);
main(){
Persona P[DIM];
int i, n;
FILE *file;
char nome[30];
printf("Scrivi il nome del file:  ");
gets(nome);
n=crea_vettore(P,DIM);
if ((file=fopen(nome, "wb"))==NULL)
{   printf("Impossibile aprire file%s\n", nome);
    return 1;
}
fwrite(P,sizeof(Persona),n,file);
fclose(file);
}

int crea_vettore(Persona P[], int dim){
int i=0;
int cont=1;
while (cont && i<dim){
        printf("scrivi i dati della persona\n");
    scanf("%s\n",&(P[i].nome));
    scanf("%s\n",&(P[i].cognome));
    scanf("%d",&(P[i].eta));getchar();

    printf("%s\n%s\n%d\n",P[i].nome,P[i].cognome,P[i].eta);
    i++;
    printf("scrivi 1 per continuare ad inserire e 0 per terminare \n");
    scanf("%d",&cont); getchar();
}
return i;
}
