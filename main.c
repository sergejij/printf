
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"
#include <math.h>

int main()
{

    int a = 55;
    int a_neg = -5;
    //ft_printf("%f\n", 1234.5678);

    printf("My funk\n");
    ft_printf("|%+023.5i|% 023.5i|%-+ 023.5i\n", INT_MAX, INT_MAX, INT_MAX);
    printf("origin:\n");
    printf("|%+023.5i|% 023.5i|%-+ 023.5i\n", INT_MAX, INT_MAX, INT_MAX);

    printf("\n\n\n");
    printf("My funk\n");
    ft_printf("%023.5i\n", INT_MAX);//%23.5i|%-23.5i|%+23.5i|% 23.5i|
    printf("origin:\n");
    printf("%023.5i\n", INT_MAX);



    printf("My funk\n");
    ft_printf("%23d|%-23d|%+23d|% 23d|%023d\n", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN);
    printf("origin:\n");
    printf("%23d|%-23d|%+23d|% 23d|%023d\n", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN);


    printf("My funk\n");
    ft_printf("%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\n", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN);
    printf("origin:\n");
    printf("%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\n", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN);


    printf("My funk\n");
    ft_printf("%-+5d|%- 5d|%-05d|%+ 5d|%+05d|% 05d|%-+ 05d|\n", 0, 0, 0, 0, 0, 0, 0);
    printf("origin:\n");
    printf("%-+5d|%- 5d|%-05d|%+ 5d|%+05d|% 05d|%-+ 05d|\n", 0, 0, 0, 0, 0, 0, 0);
    //printf("%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\n", 0, 0, 0, 0, 0); //
    //ft_printf("%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\n", 0, 0, 0, 0, 0);
   // ft_printf("%+1.5d\n%+ 5.1d\n", 5, 5);
   // printf("%+1.5d\n%+ 5.1d\n", 5, 5);

   // ft_printf("%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\n", a, a, a, a, a);
   // printf("%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\n", a, a, a, a, a);


   // printf("%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX);
   // ft_printf("%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX);
    return  0;
}