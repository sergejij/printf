/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:01:20 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/24 13:35:02 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



//  не всегда компилится без ширины, один раз из трех работает, че за хрень

#include "ft_printf.h"

void ft_add_integer(char **result, int arg, t_prinlist *lst)
{
    size_t len;

    len =  ft_lennum(arg);
    // чет я херню всякую делаю!
    if (lst->width == 0)
        lst->width = 1;
    if (((lst->flag & MINUS) == MINUS)) // -
    {
        if (((lst->flag & PLUS) == PLUS)) // +
        {
            ft_strncat(*result, "+", 1);
            *result = ft_strjoin(*result, ft_itoa(arg));
            /*if (lst->width == 0)
            {
                *result = ft_strjoin(*result, ft_itoa(int_arg));
                return ;
            }*/
            while (lst->width > len++ + 1) // из-за + 1 не выводит без ширины печатать
                *result = ft_strjoin(*result, " ");
            return ;
        }
        *result = ft_strjoin(*result, ft_itoa(arg));
        while (lst->width > len++)
            *result = ft_strjoin(*result, " ");
    }
    else if (((lst->flag & PLUS) == PLUS)) // +
    {
        if (((lst->flag & ZERO) == ZERO))
        {
            ft_strncat(*result, "+", 1);
            while (lst->width > len++ + 1)
                *result = ft_strjoin(*result, "0");
            *result = ft_strjoin(*result, ft_itoa(arg));
            return ;
        }
        if (lst->width == 0)
        {
            ft_strncat(*result, "+", 1);
            *result = ft_strjoin(*result, ft_itoa(arg));
            return ;
        }
        while (lst->width > len++ + 1)
            *result = ft_strjoin(*result, " ");
        ft_strncat(*result, "+", 1);
        *result = ft_strjoin(*result, ft_itoa(arg));
    }
    else if (((lst->flag & ZERO) == ZERO)) // zero
    {
        if ((lst->flag & 8) == 8) // +
        {
            ft_strncat(*result, "+", 1);
            while (lst->width > len++)
                *result = ft_strjoin(*result, "0");
            *result = ft_strjoin(*result, ft_itoa(arg));
            return ;
        }
        while (lst->width > len++)
            *result = ft_strjoin(*result, "0");
        *result = ft_strjoin(*result, ft_itoa(arg));
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
        *result = ft_strjoin(*result, ft_itoa(arg));
    }
    return ;
}

