//Programma che legge e stampa il contenuto di
//un file binario:
#include<stdio.h>
typedef struct{
    char nome[15];
    char cognome[15];
    int eta;
}persona;
main()
{
FILE *fp;
persona p;
char nomeF[20];
printf("Inserisci nome del file di persone da leggere: ");
scanf("%s", nomeF);
fp=fopen(nomeF,"rb");
while( fread(&p, sizeof(persona),1, fp)>0)
    printf("%s  %s  %d\n",p.nome,p.cognome,p.eta);
fclose(fp);
}
