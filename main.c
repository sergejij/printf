
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
//    ft_printf("%03.2d\n", -1);
//    printf("%03.2d\n", -1);




 //ОЧЕНЬ ВАЖНЫЙ БАГ

     printf("My funk\n");
    ft_printf("% u\n", 4294967295);
    printf("origin:\n");
     printf("% u\n", 4294967295);
//   printf("My funk\n");
//   ft_printf("%-#23.5hX\n", ULLONG_MAX);
//   printf("origin:\n");
//   printf("%-#23.5hX\n",  ULLONG_MAX);
//
//   printf("My funk\n");
//    ft_printf("%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\n", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN);
//    printf("origin:\n");
//    printf("%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\n", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN);

// ОЧЕНЬ ВАЖНЫЙ БАГ
//    printf("3My funk\n");
//    ft_printf("%.lf|%-.lf|%+.lf|% .lf|%#.lf|%0.lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);
//    printf("origin:\n");
//    printf("%.lf|%-.lf|%+.lf|% .lf|%#.lf|%0.lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);

    return  0;
}