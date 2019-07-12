
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


 printf("My funk\n");
 ft_printf("%.1f|%.2f|%.5f|%.12f\n", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999);
 printf("origin:\n");
 printf("%.1f|%.2f|%.5f|%.12f\n", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999);

 //ОЧЕНЬ ВАЖНЫЙ БАГ
//    printf("3My funk\n");
//    ft_printf("%.lf|%-.lf|%+.lf|% .lf|%#.lf|%0.lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);
//    printf("origin:\n");
//    printf("%.lf|%-.lf|%+.lf|% .lf|%#.lf|%0.lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);

    return  0;
}