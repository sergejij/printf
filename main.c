
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"
#include <math.h>

int main()
{

    int a = 1;
    long long int lon = LLONG_MAX;
    int in = 0;
    unsigned short sh = 0;
    int a_neg = -5;
//    ft_printf("%x\n",  a);
//    printf("%x\n",  a);


in = lon;
sh = lon;
sh = in;

    //printf("My funk\n\n");
    ft_printf("%#5f|%05f\n", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX);
   // printf("origin:\n\n");
    printf("%#5f|%05f\n", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX);

//    printf("3My funk\n\n");
//    ft_printf("%f|%-f|%+f|% f|%#f|%0f\n", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY);
//    printf("origin:\n\n");
//    printf("%f|%-f|%+f|% f|%#f|%0f\n", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY);
//


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