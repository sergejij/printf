/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_integer_refact.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:01:20 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/25 18:29:31 by aestella         ###   ########.fr       */
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

void    ft_pricision(char **result, int arg, t_prinlist *lst, size_t len)
{
    char *tmp;
    
    tmp = ft_itoa(arg);
    if (lst->width > len)
        ft_memset(*result, ' ', lst->width - lst->pricision);
    ft_memset(*result + (lst->width - lst->pricision), '0', lst->pricision  - len);
    *result = ft_strjoin(*result, tmp);
    free(tmp);
}

void    ft_recording(char **result, int arg, t_prinlist *lst, char fill)
{
    size_t len;

    len = ft_lennum(arg);
    if (lst->pricision > len)
        ft_pricision(result, arg, lst, len);
    else if (lst->width > len)
        ft_memset(*result, fill, lst->width - len);
    *result = ft_strjoin(*result, ft_itoa(arg));
}

void ft_add_integer(char **result, int arg, t_prinlist *lst)
{
    size_t len;
    char *tmp;
    
    len = ft_lennum(arg);
    if ((lst->flag & MINUS) == MINUS)
    {        
        if (lst->pricision > len)
        {
            ft_pricision_minus(result, arg, lst, len);
            return ;
        }
        else if(lst->width > len)
            ft_memset(*result, ' ', lst->width - len);
        else if (((lst->flag & PLUS) == PLUS))
        {
            tmp = ft_strjoin("+", tmp);
            len++;
            (*result)[lst->width - len] = '\0';
        }
        *result = ft_strjoin(tmp, *result);
    }
    else if (((lst->flag & PLUS) == PLUS)) // +
    {
        len++;
        *result = ft_itoa(arg);
        if(lst->width > len)
        {
            if (((lst->flag & ZERO) == ZERO) && lst->width > len)
            {
                ft_memset(*result, '0', lst->width - len);
                *result = ft_strjoin(*result, ft_itoa(arg));
                *result = ft_strjoin("+", *result);
                return;
            }
            ft_memset(*result, ' ', lst->width - len);
            tmp = ft_strjoin("+", ft_itoa(arg));
            *result = ft_strjoin(*result, tmp);
        }
        else
            *result = ft_strjoin("+", *result);
    }
    else if (((lst->flag & ZERO) == ZERO)) // zero
        ft_pricision(result, arg, lst, '0');
    else
        ft_pricision(result, arg, lst, ' ');
    
}
