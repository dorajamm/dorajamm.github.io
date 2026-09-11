#include<stdio.h>
typedef struct{ char nome[15];
    char cognome[15];
    int eta;
} persona;
main()
{ FILE *fp;
  persona p;
  int fine=0;
  fp=fopen("archivio1.dat","wb");
  do{
    printf("Dati persona (nome cogmome eta)?");
    scanf("%s%s%d",&p.nome,&p.cognome,&p.eta);
    fwrite(&p,sizeof(persona),1,fp);
    printf("Fine (si=1,no=0)?");
    scanf("%d", &fine);
  }while(!fine);
  fclose(fp);
}
