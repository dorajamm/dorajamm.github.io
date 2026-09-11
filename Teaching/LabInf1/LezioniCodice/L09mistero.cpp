
#include <stdio.h>
int main()
{
  int r = 10;
  int c;

while ( r >= 1 )
{
  c = 1; //
  while ( c <= 10 ) {
      if (r % 2)
          printf(  "<");
      else printf(  ">" );
      c = c + 1;
  }
  r = r - 1;
  printf("\n" );
 }

}
