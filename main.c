
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"
#include <math.h>


int main()
{


    short int a = 1;

    printf("My funk\n");
    ft_printf("%hd\n", a);
    printf("origin:\n");
    printf("%hd\n", a);


    printf("My funk\n");
    ft_printf("%f\n", DBL_MAX);
    printf("origin:\n");
    printf("%f\n", DBL_MAX);

    printf("My funk\n");
    ft_printf("%020o|%u|%x|%X\n", 42, 42, 42, 42);
    printf("origin:\n");
    printf("%020o|%u|%x|%X\n", 42, 42, 42, 42);



    return  0;
}