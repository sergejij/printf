/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:13:07 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/14 14:49:23 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_change_type_u(unsigned long long *arg, t_prinlist *lst) 
{
    unsigned short new_arg_h = 0;
    unsigned char new_arg_hh = 0;
    unsigned long new_arg_l = 0;
    unsigned long long new_arg_ll = 0;

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
    else if((lst->modifier & L_ONE) == L_ONE)
    {
        new_arg_l = *arg;
        *arg = new_arg_l;
    }
    else if((lst->modifier & LL) == LL)
    {
        new_arg_ll = *arg;
        *arg = new_arg_ll;
    }
}

int    ft_ultoa_set_piace(unsigned long long arg, char **new_res)
{
    int piece;
    unsigned long long del;
    int i;

    del = 100000;
    i = 0;
    while(arg > del)
    {
        piece = (int)(arg % del);
        arg /= del;
        new_res[i] = ft_itoa(piece);
        i++;
    }
    new_res[i] = ft_itoa((int)arg);
    new_res[++i] = NULL;
    return (i);
}

void ft_ultoa(char **result, unsigned long long arg)
{
    char **new_res;
    int i;
    char *tmp = *result;

    i = 0;
    if(!(new_res = (char **)malloc(sizeof(char*) * 5)))
        return;
    i = ft_ultoa_set_piace(arg, new_res);
    while(i-- > 0)
    {
        ft_strcat(*result, new_res[i]);
        tmp = *result + 5; //без тмп не компилилось(
        ft_strdel(&(new_res[i]));
    }
    free(new_res);
}

void ft_add_unsigned(char **result, unsigned long long arg, t_prinlist *lst)
{
    char *arg_str;

    arg_str = ft_strnew(22);
    if(lst->modifier)
        ft_change_type_u(&arg, lst);
    ft_ultoa(&arg_str, arg);
    if ((lst->flag & PLUS) == PLUS)
        lst->flag = lst->flag ^ PLUS;
    if ((lst->flag & ZERO_PRIC) == ZERO_PRIC && arg_str[0] == '0')
    {
        if(lst->width)
            arg_str[0] = ' ';
        else
            arg_str[0] = '\0';
    }

    if(lst->flag || lst->width || lst->pricision)
        ft_transform_int_result(result, arg_str, lst);
    else
        ft_strcpy(*result, arg_str);
    ft_strdel(&arg_str);
}