/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:23:14 by ubartemi          #+#    #+#             */
/*   Updated: 2019/06/03 16:12:44 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static const double rounders[20 + 1] =
        {
                0.5,				        // 0
                0.05,				        // 1
                0.0049,			        	// 2
                0.00049,		        	// 3
                0.000049,		        	// 4
                0.0000049,		        	// 5
                0.00000049,		        	// 6
                0.000000049,	        	// 7
                0.0000000049,	        	// 8
                0.00000000049,		        // 9
                0.000000000049,		        // 10
                0.0000000000049,	       	// 11
                0.00000000000049,	       	// 12
                0.000000000000049,		    // 13
                0.0000000000000049,		    // 14
                0.00000000000000049,		// 15
                0.000000000000000049,		// 16
                0.0000000000000000049,		// 17
                0.00000000000000000049,		// 18
        };

char *ft_ftoa(double f, char *result, int precision)
{
    char *ptr = result;
    char *p1;
    char c;
    long long intPart;

    intPart = f;
    if (precision < 0)
        precision = 0;
   /* else if(precision == 0 && (f - intPart) == 0)
        precision = 6;
   */if (precision <= 18)
    {
        if( (f - intPart) == 0.5 && (intPart % 2) == 0)
            f -= rounders[precision];
        else
            f += rounders[precision];
    }
    intPart = f;
    f -= intPart;
    ptr = ft_itoa(intPart);//ft_ltoa(&result, intPart);
    ft_strcpy(result, ptr);
    p1 = result;
    p1 = result;
    if (precision)
    {
        *(result + ft_strlen(ptr)) = '.';
        result += ft_strlen(ptr) + 1;
        ft_strdel(&ptr);
        if (f < 0)
            f = -f;
        while (precision)
        {
            f *= 10.0;
            c = f;
            *result++ = '0' + c;
            f -= c;
            precision--;
        }
        *result = 0;
    }
    
    return p1;
}

void ft_add_float(char **result, double arg_float, t_prinlist *lst)
{
    ft_ftoa(arg_float, *result, lst->pricision);
  //  lst->pricision = 0;
   // if(lst->flag || lst->width)
     //   ft_transform_int_result(result, lst);
}