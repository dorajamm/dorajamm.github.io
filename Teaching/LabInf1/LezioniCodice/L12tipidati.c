#include <stdio.h>
#include <limits.h>
#include <float.h>

main(){
  printf("Codifica del tipo SHORT \n");
  printf("Valore minimo = %d \n",SHRT_MIN);
 printf("Valore massimo = %d \n",SHRT_MAX);
 printf("\n");

 printf("Codifica del tipo INT \n");
 printf("Valore minimo = %d \n",INT_MIN);
 printf("Valore massimo = %d \n",INT_MAX);
printf("\n");

 printf("Codifica del tipo LONG INT \n");
 printf("Valore minimo = %ld \n", LONG_MIN);
 printf("Valore massimo =%ld \n", LONG_MAX);
printf("\n");

 printf("Codifica del tipo UNSIGNED SHORT \n");
 printf("Valore minimo = 0 \n");
 printf("Valore massimo = %u \n", USHRT_MAX);
printf("\n");

 printf("Codifica del tipo UNSIGNED INT \n");
 printf("Valore minimo = 0 \n");
 printf("Valore massimo = %u \n", UINT_MAX);
printf("\n");

 printf("Codifica del tipo UNSIGNED LONG INT \n");
 printf("Valore minimo = 0 \n");
 printf("Valore massimo = %lu \n", ULONG_MAX);
printf("\n");


printf("\n");printf("\n");

  printf("\nFLOAT dim. %d\n",sizeof(float));
  printf("Codifica del tipo FLOAT \n ");
 printf("Valore minimo = %e \n", FLT_MIN);
 printf("Valore massimo = %e \n", FLT_MAX);


  printf("\nDOUBLE dim. %d\n",sizeof(double));
  printf("Codifica del tipo DOUBLE \n ");
 printf("Valore minimo = %e \n", DBL_MIN);
 printf("Valore massimo = %e \n", DBL_MAX);


  printf("\nLONG DOUBLE dim. %d\n",sizeof(long double));
  printf("Codifica del tipo LONG DOUBLE \n ");
 printf("Valore minimo = %Le \n", LDBL_MIN);
 printf("Valore massimo = %Le \n", LDBL_MAX);

}
