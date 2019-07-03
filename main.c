
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"
#include <math.h>

int main()
{

    int a = 5;
    int a_neg = -5;
    //ft_printf("%f\n", 1234.5678);


    printf("My funk\n");
    ft_printf("%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\n", 0, 0, 0, 0, 0, 0, 0);
    printf("origin:\n");
    printf("%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\n", 0, 0, 0, 0, 0, 0, 0);

    printf("My funk\n");
    ft_printf("%1.d|%-1.d|%+1.d|% 1.d|%01.d\n", 0, 0, 0, 0, 0);
    printf("origin:\n");
    printf("%1.d|%-1.d|%+1.d|% 1.d|%01.d\n\n", 0, 0, 0, 0, 0);

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