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
    size_t width;
    size_t pricision;
}               t_prinlist;


int ft_printf(const char *apformat, ...);
int ft_analise_flags(char *format, t_prinlist *lst);
int ft_is_type(char c);
void ft_analise_types(char *format, char *result, char *str_arg, t_prinlist *lst);
char *ft_add_string(char *result, char *str_arg, t_prinlist *lst);

#endif //PRINTF_FT_PRINTF_H
