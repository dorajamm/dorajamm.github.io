#include <stdio.h>
main()
{
    int i,num;
    FILE *fp;

    fp = fopen("prova.txt", "w");

    for (i=1; i<10; i++)
        fprintf(fp,"%3d \n",50*i);
    fclose(fp);

    fp = fopen("prova.txt", "r");
    for (i=1; i<10; i++){
        fscanf(fp,"%3d",&num);
        printf("%4d", num);
    }
    fclose(fp);

}
