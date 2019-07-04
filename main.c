#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"

int main()
{
    ft_printf("%-#023X\n", 0U, 0U);
    printf("%-#023X\n", 0U, 0U);
    printf("___________________\n");
    //ft_printf("%x\n", 0U);
    //printf("%x\n", 0U);
    return  0;
}
