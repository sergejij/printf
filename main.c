
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
    //ft_printf("%lf|%-lf|%+lf|% lf|%#lf|%0lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);
  //  printf("%lf|%-lf|%+lf|% lf|%#lf|%0lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);


 printf("My funk\n");
 ft_printf("%o\n", 0U);
 printf("origin:\n");
 printf("%o\n",  0U);

 //ОЧЕНЬ ВАЖНЫЙ БАГ

//     printf("My funk\n");
//    ft_printf("%#23.5hx|%#1.5hx|%#23.X|%#023.5hx|\n", ULLONG_MAX, ULLONG_MAX, UINT_MAX, ULLONG_MAX);
//    printf("origin:\n");
//     printf("%#23.5hx|%#1.5hx|%#23.X|%#023.5hx|\n", ULLONG_MAX, ULLONG_MAX, UINT_MAX, ULLONG_MAX);
  // printf("My funk\n");
  // ft_printf("%-#23.5hX\n", ULLONG_MAX);
  // printf("origin:\n");
  // printf("%-#23.5hX\n",  ULLONG_MAX);
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