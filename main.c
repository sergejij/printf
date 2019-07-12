
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
//    ft_printf("%#23.5hx|%#1.5hx|%#23.X|%#023.5hx|\n", ULLONG_MAX, ULLONG_MAX, UINT_MAX, ULLONG_MAX);
//    printf("origin:\n");
//     printf("%#23.5hx|%#1.5hx|%#23.X|%#023.5hx|\n", ULLONG_MAX, ULLONG_MAX, UINT_MAX, ULLONG_MAX);
   printf("My funk\n");
   ft_printf("%-#X|%-0X|%#0X|%-#0X\n", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX);
   printf("origin:\n");
   printf("%-#X|%-0X|%#0X|%-#0X\n", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX);
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