
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"

int main()
{
    ft_printf("%+15.8f|\n", 0.);
    printf("%+15.8f|\n", 0.);
    printf("___________________\n");
    ft_printf("% f|\n", -0.);
    printf("% f|\n", -0.);

    return  0;
}