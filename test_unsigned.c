/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:13:07 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/30 13:33:28 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void ft_add_unsigned(char **result, unsigned long long int arg, t_prinlist *lst)
{
    int piece;
    unsigned long long int del;
    char **new_res;
    int i;
    char *tmp = *result;

    del = 100000;
    i = 0;
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
    if(lst->flag || lst->width || lst->pricision)
        ft_transform_int_result(result, lst);
}