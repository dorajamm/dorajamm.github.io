#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int *px;
    int x;
    x=5;

    px=&x;
    printf(" il valore di x e' %d\n",x);
    printf(" il valore di px e' %p\n",px);
    px=px+5;;
     printf(" il valore di px e' %p\n",px);

    printf(" il valore di *px e' %d\n",*px);

    (*px)++;
    printf(" il valore di *px e' %d\n",*px);
}
