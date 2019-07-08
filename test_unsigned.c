/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:13:07 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/08 18:24:32 by aestella         ###   ########.fr       */
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

void ft_add_unsigned(char **result, unsigned long long arg, t_prinlist *lst)
{
    int piece;
    unsigned long long del;
    char **new_res;
    int i;
    char *tmp = *result;

    del = 100000;
    i = 0;
    ft_change_type_u(&arg, lst);
    if(!(new_res = (char **)malloc(sizeof(char*) * 5)))
        return;
    while(arg > del)
    {
        piece = (unsigned int)(arg % del);
        arg /= del;
        new_res[i] = ft_strdup(ft_itoa(piece));
        i++;
    }
    new_res[i] = ft_strdup(ft_itoa((int)arg));
    new_res[++i] = NULL;
    while(i-- > 0)
    {
        ft_strcat(*result, new_res[i]);
        tmp = *result + 5; //без тмп не компилилось(
    }
    if ((lst->flag & PLUS) == PLUS)
        lst->flag = lst->flag ^ PLUS;
    //if ((lst->flag & ZERO_PRIC) == ZERO_PRIC && new_res[0] == '0')
    //    new_res[0] = ' ';
    if(lst->flag || lst->width || lst->pricision)
        ft_transform_int_result(result, lst);
}