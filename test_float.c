/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:23:14 by ubartemi          #+#    #+#             */
/*   Updated: 2019/06/02 16:36:23 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




char *ftoa(double f, char *result, int precision)
{
    char *ptr = result;
    char *p1;
    char c;
    long intPart;

    if (precision < 0)
    {
        precision = 0;
        /*if (f < 1.0)
            precision = 6;
        else if (f < 10.0)
            precision = 5;
        else if (f < 100.0)
            precision = 4;
        else if (f < 1000.0)
            precision = 3;
        else if (f < 10000.0)
            precision = 2;
        else if (f < 100000.0)
            precision = 1;
        else
            precision = 0;*/
    }

    intPart = f;
    f -= intPart;
    ptr = ft_itoa(intPart);
    ft_strcpy(result, ptr);
    p1 = result;
   
    
    if (precision)
    {
        *(result + ft_strlen(ptr)) = '.';
        result += ft_strlen(ptr) + 1;
        ft_strdel(&ptr);
        if (f < 0)
            f = -f;
        while (precision--)
        {
            if (precision == 1 && f > 0.5)  //&& (f / 10 < 0.05))
            {
                f += 0.05; 
                if(f > 0.99)
                { 
                    f /= 10.0;
                    precision += 2;
                    continue ;
                }
                    
            }
                
            f *= 10.0;
            c = f;
            *result++ = '0' + c;
            f -= c;
        }
        *result = 0;
    }
    
    return p1;
}

void ft_add_float(char **result, double arg_float, t_prinlist *lst)
{
    //int i = 0;

    //i |= (1 << 7);

    //  printf("\n-%d-\n", i);
    ftoa(arg_float, *result, lst->pricision);
}