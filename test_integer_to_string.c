/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_integer_to_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:01:20 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/09 16:17:58 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_sym_count;

void ft_change_type_int(int *arg, t_prinlist *lst) {
    short new_arg_h = 0;
    char new_arg_hh = 0;

    if((lst->modifier & H) == H)
    {
        new_arg_h = *arg;
        *arg = new_arg_h;
    }
    else if((lst->modifier & HH) == HH)
    {
        new_arg_hh = *arg;
        *arg = new_arg_hh;
    }
}

void ft_add_integer(char **result, int arg_int, t_prinlist *lst)
{
    size_t len;
    char *arg;

    arg = NULL;
    if(lst->modifier)
        ft_change_type_int(&arg_int, lst);
    arg = ft_itoa(arg_int);
    len = ft_strlen(arg);
    if(*arg == '0' && len == 1)
    {
        if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
        {
            *arg = '\0';
            len = 0;
        }
    }
    lst->len = len;
    if ((lst->flag & MINUS) == MINUS)
        ft_minus(result, arg, lst, lst->len);
    else if (((lst->flag & PLUS) == PLUS)) // +
        ft_plus(result, arg, lst, lst->len); // + 1 так как + это тоже часть числа
    else if (((lst->flag & ZERO) == ZERO)) // zero
        ft_recording(result, arg, lst, '0');
    else
        ft_recording(result, arg, lst, ' ');
    if ((lst->flag & SPACE) == SPACE && (lst->flag & PLUS) != PLUS &&  arg_int >=0 && lst->width <= len)
        *result = ft_strjoin(" ", *result);
    //ft_strdel(&arg); // распечатать когда уберем все strjoin
}
