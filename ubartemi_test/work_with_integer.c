/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:01:20 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/22 17:10:21 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstrr(char const *s)
{
    int counter;

    counter = 0;
    if (s)
    {
        while (s[counter] != '\0')
        {
            ft_putchar(s[counter]);
            counter++;
        }
    }
}

int ft_is_type(char c)
{
    if (c == 's' || c == 'c' || c == 'p' || c == 'i' || c == 'd')
        return (1);
    return (0);
}

void ft_add_integer(char **result, int int_arg, t_prinlist *lst)
{
    int len;
    char *tmp;

    len =  ft_lennum(int_arg);
    tmp = *result + (lst->width - len);
    if (lst->width && ((lst->flag | ZERO) == ZERO) && lst->width > len) // zero
    {
        while (lst->width > len++)
            write(1, "0", 1);
        ft_putstr(ft_itoa(int_arg));
        //while (lst->width > len++)
        //ft_memset(*result, 48, lst->width - len);
        //tmp = ft_strjoin(tmp, ft_itoa(int_arg));
    }
    if (lst->width && ((lst->flag | 4) == 4))
    {
        
    }
    if (lst->width && ((lst->flag | 8) == 8))
    {

    }
    *result = ft_strjoin(*result, ft_itoa(int_arg));
}

int ft_analise_types(char *format, char *result, int int_arg, t_prinlist *lst)
{
    if(*format == 'd')
    {
        ft_add_integer(&result, int_arg, lst);
        //ft_putstrr(result);
    }
    return 1;
}

int ft_analise_flags(char *format, t_prinlist *lst)
{
    int flag = 0;
    while(!(ft_is_type(*format)))
    {
        if (*format == '#')
            flag = (flag | 1);
        else if (*format == '0')
            flag = flag | 2;
        else if (*format == '-')
            flag = flag | 4;
        else if (*format == '+')
            flag = flag | 8;
        else if (ft_isdigit(*format))//записываем ширину
        {
            lst->width = ft_atoi(format);
            while (ft_isdigit(*format))
                format++;
            continue ;
        }
        else if (*format == '.')//записываем точность
        {
            lst->pricision = ft_atoi(++format);
            while (ft_isdigit(*format))
                format++;
            continue ;
        }
        format++;
    }
    lst->flag = flag;
    return (flag);
}

int ft_printf(const char *apformat, ...)
{
    va_list ap;         //указатель va_list | poit on next unnamed argument
    va_start(ap, apformat);    // устанавливаем указатель
    const char *p_apFormat = apformat;
    char *result;

    result = (char*)malloc(sizeof(char) + 10);
    int flag;
    t_prinlist *lst;

    while (*p_apFormat)
    {
        if (*p_apFormat == '%')
        {
            lst = (t_prinlist *)malloc(sizeof(t_prinlist));
            flag = ft_analise_flags((char *)p_apFormat, lst);
            while(!(ft_is_type(*p_apFormat)))
                p_apFormat++;
            ft_analise_types((char *)p_apFormat, result, va_arg(ap, int), lst);
            continue ;
        }
        p_apFormat++;
    }
    return (1);
}

int main(void)
{
    int a = 5;
    ft_printf("%019d", a);
    printf("\n%019d", a);
    return (0);
}