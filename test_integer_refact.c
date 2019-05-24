/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:01:20 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/24 19:30:16 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



//  не всегда компилится без ширины, один раз из трех работает, че за хрень

#include "ft_printf.h"
extern int g_sym_count;

void ft_add_integer(char **result, int arg, t_prinlist *lst)
{
    size_t len;
    char *tmp;

    len =  ft_lennum(arg);
    if (((lst->flag & MINUS) == MINUS))
    {
        if(lst->width > len)
            ft_memset(*result, '.', lst->width - len);
        tmp = ft_itoa(arg);
        if (((lst->flag & PLUS) == PLUS))
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
            ft_memset(*result, '.', lst->width - len);
            tmp = ft_strjoin("+", ft_itoa(arg));
            *result = ft_strjoin(*result, tmp);
        }
        else
            *result = ft_strjoin("+", *result);
    }
    else if (((lst->flag & ZERO) == ZERO)) // zero
    {
        if(lst->width > len)
            ft_memset(*result, '0', lst->width - len);
        *result = ft_strjoin(*result, ft_itoa(arg));
    }
    else
    {
        if(lst->width > len)
            ft_memset(*result, '.', lst->width - len);
        *result = ft_strjoin(*result, ft_itoa(arg));
    }

}

