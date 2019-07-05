
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"
#include <math.h>

int main()
{

    int a = 1;
    int a_neg = -5;
    //ft_printf("% 023i|%-+ 023i\n",  a, a);
   // printf("% 023i|%-+ 023i\n", a, a);

    printf("My funk\n");
    ft_printf("%lX|%-lX|%#lX|%0lX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
    printf("origin:\n");
    printf("%lX|%-lX|%#lX|%0lX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);


  /*  printf("3My funk\n");
    ft_printf("%+023lld|% 023lld|%-+ 023lld\n", LLONG_MAX, LLONG_MAX, LLONG_MAX);
    printf("origin:\n");
    printf("%+023lld|% 023lld|%-+ 023lld\n", LLONG_MAX, LLONG_MAX, LLONG_MAX);
*/
//printf("\n\n\n");
//    printf("4My funk\n");
//    ft_printf("%+23.ld|% 23.ld|%023.ld\n", LLONG_MIN, LLONG_MIN, LLONG_MIN);
//    printf("origin:\n");
//    printf("%+23.ld|% 23.ld|%023.ld\n", LLONG_MIN, LLONG_MIN, LLONG_MIN);
//    printf("My funk\n");
//    ft_printf("%+23.5ld|% 23.5ld|%023.5ld\n", LLONG_MIN, LLONG_MIN, LLONG_MIN); //
//    printf("origin:\n");
//    printf("%+23.5ld|% 23.5ld|%023.5ld\n", LLONG_MIN, LLONG_MIN, LLONG_MIN);

//    printf("My funk\n");
//
//    ft_printf("%+ 23ld|%+023ld|% 023ld|%-+ 023ld\n",  LLONG_MAX, LLONG_MAX);
//    printf("origin:\n");
//    printf("%+ 23ld|%+023ld|% 023ld|%-+ 023ld\n",  LLONG_MAX, LLONG_MAX,);

//   // ft_printf("%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\n", a, a, a, a, a);
//   // printf("%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\n", a, a, a, a, a);
//
//
//   // printf("%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX);
//   // ft_printf("%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX);
//    ft_printf("%-#023X\n", 0U, 0U);
//    printf("%-#023X\n", 0U, 0U);
//    printf("___________________\n");
//    //ft_printf("%x\n", 0U);
//    //printf("%x\n", 0U);
    return  0;
}