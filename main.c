
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
    ft_printf("%-#23.5hhX|%-023.5hhX|%#023.5hhX|%-#023.5hhX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
    printf("%-#23.5hhX|%-023.5hhX|%#023.5hhX|%-#023.5hhX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);


    printf("My funk\n");
    ft_printf("%-#10.5hx|%-023.5hx|%#023.5hx|%-#023.5hx|\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
    printf("origin:\n");
    printf("%-#10.5hx|%-023.5hx|%#023.5hx|%-#023.5hx|\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
    printf("My funk\n");
    ft_printf("%-#x|%-0x|%#0x|%-#0x\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
    printf("origin:\n");
    printf("%-#x|%-0x|%#0x|%-#0x\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);

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