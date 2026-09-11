/* lancio un dado 20 volte */
#include <stdio.h>
#include <stdlib.h>

main()
{
   int i;
   unsigned seme;

   printf("Scrivi il seme: ");
   scanf("%u", &seme);
   srand(seme);

   for (i = 1; i <= 20; i++) {
      printf("%10d", 1 + (rand() % 6));

      if (i % 5 == 0)
         printf("\n");
   }



   return 0;
}

