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

#define HASH 1 
#define ZERO 2
#define MINUS 4
#define PLUS 8
#define SPACE 16

typedef struct  s_prinlist
{
    int flag;
    size_t width;
    size_t pricision;
}               t_prinlist;


int ft_printf(const char *apformat, ...);
int ft_analise_flags(char *format, t_prinlist *lst);
int ft_is_type(char c);
void ft_analise_types(char *format, char *result, va_list ap, t_prinlist *lst);
char *ft_add_string(char *result, char *str_arg, t_prinlist *lst);
void ft_add_char(char **result, char chr_arg, t_prinlist *lst);
void ft_add_integer(char **result, int arg, t_prinlist *lst);
void ft_add_pointer(char **result, unsigned long arg, t_prinlist *lst);
char		*ft_itoa_base_ul(unsigned long n);
int		ft_lennum_base(unsigned long num);


#endif //PRINTF_FT_PRINTF_H
