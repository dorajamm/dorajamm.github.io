/* lancio un dado 6000 volte */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#
int Tira1Dado()
{
    return 1 + (rand() % 6);
}
main()
{
   int faccia, tiro, freq1 = 0, freq2 = 0,
       freq3 = 0, freq4 = 0,
       freq5 = 0, freq6 = 0;

   srand(time(NULL));

      for (tiro = 1; tiro <= 6000; tiro++) {
      faccia = Tira1Dado();
      switch (faccia) {
         case 1:
            ++freq1;
            break;
         case 2:
            ++freq2;
            break;
         case 3:
            ++freq3;
            break;
         case 4:
            ++freq4;
            break;
         case 5:
            ++freq5;
            break;
         case 6:
            ++freq6;
            break;
      }
   }

   printf("%s%13s\n", "Faccia", "Frequenza");
   printf("   1%13d\n", freq1);
   printf("   2%13d\n", freq2);
   printf("   3%13d\n", freq3);
   printf("   4%13d\n", freq4);
   printf("   5%13d\n", freq5);
   printf("   6%13d\n", freq6);

   return 0;
}

