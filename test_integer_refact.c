/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_integer_refact.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:01:20 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/25 19:54:26 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



//  не всегда компилится без ширины, один раз из трех работает, че за хрень

#include "ft_printf.h"
extern int g_sym_count;

void    ft_pricision_minus(char **result, int arg, t_prinlist *lst, size_t len)
{
    ft_memset(*result, '0', lst->pricision  - len);
    ft_strcpy(*result + lst->pricision  - len, ft_itoa(arg));
    if (lst->width > lst->pricision)
    {    ft_memset(*result + lst->pricision, ' ', lst->width - lst->pricision);
        (*result)[lst->width] = '\0';
    }
    else
        (*result)[lst->pricision] = '\0';
}

void    ft_pricision(char **result, t_prinlist *lst, size_t len)
{
    if (lst->width > len && lst->width > lst->pricision)
        ft_memset(*result, ' ', lst->width - lst->pricision);
    else if (lst->width < lst->pricision)
        ft_memset(*result, '0', lst->pricision - len);
    ft_memset(*result + (lst->width - lst->pricision), '0', lst->pricision  - len);
}

void    ft_recording(char **result, int arg, t_prinlist *lst, char fill)
{
    size_t len;

    len = ft_lennum(arg);
    if (lst->pricision > len)
        ft_pricision(result, lst, len);
    else if (lst->width > len)
        ft_memset(*result, fill, lst->width - len);
    *result = ft_strjoin(*result, ft_itoa(arg));
}

void    ft_plus(char **result, int arg, t_prinlist *lst, size_t len)
{
    char *tmp;
    *result = ft_itoa(arg);
    if(lst->width > len)
    { //ft_strcpy(*result + lst->pricision  - len, ft_itoa(arg));
        if (((lst->flag & ZERO) == ZERO) && lst->width > len)
        {
            ft_memset(*result, '0', lst->width - len);
            ft_strcpy(*result + lst->width - len, ft_itoa(arg));
            *result = ft_strjoin("+", *result);
            return;
        }
        ft_memset(*result, ' ', lst->width - len);
        tmp = ft_strjoin("+", ft_itoa(arg));
        // тут надо править! при  printf("\n%d\n", ft_printf("%+10.5d",  i)); не заполняет нуляями
        ft_strcpy(*result + lst->width - len, tmp);
    }
    else
    {
        tmp = *result;
        *result = ft_strjoin("+", *result);
        ft_strdel(&tmp);
    }
}

void    ft_minus(char **result, int arg, t_prinlist *lst, size_t len)
{
    if (lst->pricision > len)
        ft_pricision_minus(result, arg, lst, len);
    else
    {
        if (((lst->flag & PLUS) == PLUS))
        {
            ft_strcpy(*result, "+");
            ft_strcpy(*result + 1, ft_itoa(arg));
            ft_memset(*result + len + 1, ' ', lst->width - len);
            return ;
        }
        ft_strcpy(*result, ft_itoa(arg));
        ft_memset(*result + len, ' ', lst->width - len);
    }
}

void ft_add_integer(char **result, int arg, t_prinlist *lst)
{
    size_t len;
    
    len = ft_lennum(arg);
    if ((lst->flag & MINUS) == MINUS)
        ft_minus(result, arg, lst, len);
    else if (((lst->flag & PLUS) == PLUS)) // +
        ft_plus(result, arg, lst, len + 1); // + 1 так как + это тоже часть числа 
    else if (((lst->flag & ZERO) == ZERO)) // zero
        ft_recording(result, arg, lst, '0');
    else
        ft_recording(result, arg, lst, ' ');
}
