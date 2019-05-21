//
// Created by Asafoetida Estella on 2019-05-21.
//

#ifndef PRINTF_FT_PRINTF_H
#define PRINTF_FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "./libft/libft.h"

typedef struct  s_prinlist
{
    int flag;
    int width;
    int pricision;
}               t_prinlist;

#endif //PRINTF_FT_PRINTF_H
