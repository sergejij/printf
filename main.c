
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
    //ft_printf("%0.5o\n", 0U);
    //printf("%0.5o\n", 0U);
    //printf("--------------\n");

    ft_printf("%0o\n", UINT_MAX);
    printf("%0o\n", UINT_MAX);
    printf("--------------\n");

    //ft_printf("%-#1.o|%#01.o|%-#01.o\n", 0U, 0U, 0U);
    //printf("%-#1.o|%#01.o|%-#01.o\n", 0U, 0U, 0U);
    //printf("--------------\n");

   // ft_printf("%#023.o\n", 0U);
   // printf("%#023.o\n", 0U);


   /* printf("My funk\n");
    ft_printf("%1f|%-1f|%+1f|% 1f|%#1f|%01f\n", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);
    printf("origin:\n");
    printf("%1f|%-1f|%+1f|% 1f|%#1f|%01f\n", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);
    printf("My funk\n");
    ft_printf("% f|%#f|%0f\n", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);
    printf("origin:\n");
    printf("%f|%-f|%+f|% f|%#f|%0f\n", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);
    printf("My funk\n");
    ft_printf("%-+8.14f|%- 8.14f|%-#8.14f|%-08.14f|%-+#8.14f|%-+ #08.14f\n", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);
    printf("origin:\n");
    printf("%-+8.14f|%- 8.14f|%-#8.14f|%-08.14f|%-+#8.14f|%-+ #08.14f\n", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);

    printf("My funk\n");
    ft_printf("%5f|%-5f|%+5f|% 5f|%#5f|%05f\n", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);
    printf("origin:\n");
    printf("%5f|%-5f|%+5f|% 5f|%#5f|%05f\n", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);*/
//
// ОЧЕНЬ ВАЖНЫЙ БАГ
//    printf("3My funk\n");
//    ft_printf("%.lf|%-.lf|%+.lf|% .lf|%#.lf|%0.lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);
//    printf("origin:\n");
//    printf("%.lf|%-.lf|%+.lf|% .lf|%#.lf|%0.lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);

    return  0;
}