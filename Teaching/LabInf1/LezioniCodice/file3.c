#include <stdio.h>
main()
{
FILE *fp;
int dati[100], k;
fp=fopen("dati.bin", "rb");
k=fread(dati, sizeof(int),100, fp);
printf("numero di valori letti: %d\n",k);
fclose(fp);
}
