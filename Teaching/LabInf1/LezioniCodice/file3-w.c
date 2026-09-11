#include <stdio.h>
main()
{
FILE *fp;
int i;
fp=fopen("dati.bin", "wb");
for(i=0; i<90; i++)
fwrite(&i, sizeof(int),1, fp);
fclose(fp);
}
