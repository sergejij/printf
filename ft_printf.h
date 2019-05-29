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
#define H 1
#define L_ONE 2
#define HH 4
#define LL 8

typedef struct  s_prinlist
{
    int flag;
    int modifier;
    size_t width;
    size_t pricision;
    size_t len;

}               t_prinlist;


int ft_printf(const char *apformat, ...);
int ft_analise_flags(char *format, t_prinlist *lst);
int ft_is_type(char *c, t_prinlist *lst);
void ft_analise_types(char *format, char *result, va_list ap, t_prinlist *lst);
char *ft_add_string(char *result, char *str_arg, t_prinlist *lst, int numSys);
void ft_add_char(char **result, int chr_arg_int, t_prinlist *lst);
void ft_add_integer(char **result, int arg, t_prinlist *lst);
void ft_add_pointer(char **result, unsigned long arg, t_prinlist *lst);
char		*ft_itoa_base_ul(unsigned long n);
int		ft_lennum_base(unsigned long num);
void ft_add_hex(char **result, int arg, t_prinlist *lst, char sym);
char		*ft_itoa_base_hex(int n);
size_t  ft_lennum_hex(int num);
void ft_add_octal(char **result, int arg, t_prinlist *lst);
void ft_change_type_int(int *arg, t_prinlist *lst);
void ft_long_to_str(char **result, long long int arg, t_prinlist *lst);


void    ft_minus_l(char **result, char *arg, t_prinlist *lst, size_t len);
void    ft_minus_negative_l(char **result, char *arg, t_prinlist *lst, size_t len);
void    ft_recording_l(char **result, char *arg, t_prinlist *lst, char fill);
void    ft_recording_negative_l(char **result, char *arg, t_prinlist *lst, char fill);
void    ft_pricision_l(char **result, t_prinlist *lst, size_t len, char *arg);
void    ft_plus_l(char **result, char *arg, t_prinlist *lst, size_t len);
void    ft_plus_negative_l(char **result, char *arg, t_prinlist *lst, size_t len);
void    ft_pricision_hex(char **result, t_prinlist *lst, size_t len, char *str);



#endif //PRINTF_FT_PRINTF_H
