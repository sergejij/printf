/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:01:20 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/24 11:58:53 by ubartemi         ###   ########.fr       */
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

//  не всегда компилится без ширины, один раз из трех работает, че за хрень
void ft_add_integer(char **result, int int_arg, t_prinlist *lst)
{
    int len;

    len =  ft_lennum(int_arg);
    // чет я херню всякую делаю!
    if (lst->width == 0)
        lst->width = 1;
    if (((lst->flag & 4) == 4)) // -
    {
        if (((lst->flag & 8) == 8)) // +
        {
            ft_strncat(*result, "+", 1);
            *result = ft_strjoin(*result, ft_itoa(int_arg));
            /*if (lst->width == 0)
            {
                *result = ft_strjoin(*result, ft_itoa(int_arg));
                return ;
            }*/
            while (lst->width > len++ + 1) // из-за + 1 не выводит без ширины печатать
                *result = ft_strjoin(*result, " ");
            return ;
        }
        *result = ft_strjoin(*result, ft_itoa(int_arg));
        while (lst->width > len++)
            *result = ft_strjoin(*result, " ");
    }
    else if (((lst->flag & 8) == 8)) // +
    {
        if (((lst->flag & ZERO) == ZERO))
        {
            ft_strncat(*result, "+", 1);
            while (lst->width > len++ + 1)
                *result = ft_strjoin(*result, "0");
            *result = ft_strjoin(*result, ft_itoa(int_arg));
            return ;
        }
        if (lst->width == 0)
        {
            ft_strncat(*result, "+", 1);
            *result = ft_strjoin(*result, ft_itoa(int_arg));
            return ;
        }
        while (lst->width > len++ + 1)
            *result = ft_strjoin(*result, " ");
        ft_strncat(*result, "+", 1);
        *result = ft_strjoin(*result, ft_itoa(int_arg));
    }
    else if (((lst->flag & ZERO) == ZERO)) // zero
    {
        if ((lst->flag & 8) == 8) // +
        {
            ft_strncat(*result, "+", 1);
            while (lst->width > len++)
                *result = ft_strjoin(*result, "0");
            *result = ft_strjoin(*result, ft_itoa(int_arg));
            return ;
        }
        while (lst->width > len++)
            *result = ft_strjoin(*result, "0");
        *result = ft_strjoin(*result, ft_itoa(int_arg));
    }
    else
    {
        /*if (lst->width == 0)
        {
            *result = ft_strjoin(*result, ft_itoa(int_arg));
            return ;
        }*/
        while (lst->width > len++)
            *result = ft_strjoin(*result, " ");
        *result = ft_strjoin(*result, ft_itoa(int_arg));
    }
    return ;
}

int ft_analise_types(char *format, char *result, int int_arg, t_prinlist *lst)
{
    if(*format == 'd')
    {
        ft_add_integer(&result, int_arg, lst);
        ft_putstrr(result);
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
            flag = ft_analise_flags((char*)p_apFormat, lst);
            while(!(ft_is_type(*p_apFormat)))
                p_apFormat++;
            ft_analise_types((char*)p_apFormat, result, va_arg(ap, int), lst);
            continue ;
        }
        p_apFormat++;
    }
    return (1);
}

int main(void)
{
    int a = 1305;
    ft_printf("%1d", a);
    printf("\n%1d", a);
    return (0);
}