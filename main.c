
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"
#include <math.h>


int main()
{


    int a = 111111;
//    int a_neg = -5;
//    ft_printf("% 023i|%-+ 023i\n",  a, a);
//    printf("% 023i|%-+ 023i\n", a, a);

    

//     printf("My funk\n");
//    ft_printf("%1.o|%-1.o|%#1.o|%01.o\n", 0U, 0U, 0U, 0U); 
//    printf("origin:\n");
//     printf("%1.o|%-1.o|%#1.o|%01.o\n", 0U, 0U, 0U, 0U);
   printf("My funk\n");
   ft_printf("%llo|%-llo|%#llo|%0llo\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
   printf("origin:\n");
   printf("%llo|%-llo|%#llo|%0llo\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
//
//    printf("My funk\n");
//    ft_printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", -0, -0, -0, -0, -0, -0, -0);
//    printf("origin:\n");
//    printf("%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", -0, -0, -0, -0, -0, -0, -0);
//
// ОЧЕНЬ ВАЖНЫЙ БАГ
//    printf("3My funk\n");
//    ft_printf("%.lf|%-.lf|%+.lf|% .lf|%#.lf|%0.lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);
//    printf("origin:\n");
//    printf("%.lf|%-.lf|%+.lf|% .lf|%#.lf|%0.lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);

    return  0;
}