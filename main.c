
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"
#include <math.h>


int main()
{


    int a = 111111;
    int a_neg = -5;
//    ft_printf("0.000001 %f\n", 0.1);
//
//    ft_printf("0.000001 %f\n", 0.000001);
//    ft_printf("-42. %f\n", -42.);
//    ft_printf("42.%f\n", 42.);
//     ft_printf("0.000099 %f\n", 0.000099);
//    ft_printf("999.99999 %f\n", 999.99999);
//    ft_printf("LDBL_MAX %Lf\n", LDBL_MAX);
//    ft_printf("DBL_MAX %f\n", DBL_MAX);
//    ft_printf("LDBL_MIN %Lf\n", LDBL_MIN);
//    ft_printf("DBL_MIN %f\n", DBL_MIN);
//    ft_printf("%inf Lf\n", INFINITY);
//    ft_printf("%nan Lf\n", 0. / 0.);

//    ft_printf("%Lf\n", LDBL_MAX);
//    printf("%Lf\n", LDBL_MAX);
    ft_printf("%.2147483649f|%2147483649f\n", 1.0, 1.0);
    printf("%.2147483649f|%2147483649f\n", 1.0, 1.0);
// printf("My funk\n");
// ft_printf("%23.5hhX|%-23.5hhX|%#23.5hhX|%023.5hhX", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
// printf("origin:\n");
// printf("%li|%-li|%+li|% li|%0li\n", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX);

 //ОЧЕНЬ ВАЖНЫЙ БАГ

//     printf("My funk\n");
//    ft_printf("%#23.5hx|%#1.5hx|%#23.X|%#023.5hx|\n", ULLONG_MAX, ULLONG_MAX, UINT_MAX, ULLONG_MAX);
//    printf("origin:\n");
//     printf("%#23.5hx|%#1.5hx|%#23.X|%#023.5hx|\n", ULLONG_MAX, ULLONG_MAX, UINT_MAX, ULLONG_MAX);
//   printf("My funk\n");
//   ft_printf("%-#23.5hX\n", ULLONG_MAX);
//   printf("origin:\n");
//   printf("%-#23.5hX\n",  ULLONG_MAX);
//
   /* printf("My funk\n");
    ft_printf("%-#23.5hx|%-023.5hx|%#023.5hx|%-#023.5hx\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
    printf("origin:\n");
    printf("%-#23.5hx|%-023.5hx|%#023.5hx|%-#023.5hx\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
*/
// ОЧЕНЬ ВАЖНЫЙ БАГ
//    printf("3My funk\n");
//    ft_printf("%.lf|%-.lf|%+.lf|% .lf|%#.lf|%0.lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);
//    printf("origin:\n");
//    printf("%.lf|%-.lf|%+.lf|% .lf|%#.lf|%0.lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);

    return  0;
}