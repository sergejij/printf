/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:23:14 by ubartemi          #+#    #+#             */
/*   Updated: 2019/06/02 17:57:42 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static const double rounders[20 + 1] =
        {
                0.499,				// 0
                0.049,				// 1
                0.0049,				// 2
                0.00049,				// 3
                0.000049,			// 4
                0.0000049,			// 5
                0.00000049,			// 6
                0.000000049,			// 7
                0.0000000049,		// 8
                0.00000000049,		// 9
                0.000000000049,		// 10
                0.0000000000049,		// 11
                0.00000000000049,		// 12
                0.000000000000049,		// 13
                0.0000000000000049,		// 14
                0.00000000000000049,		// 15
                0.000000000000000049,		// 16
                0.0000000000000000049,		// 17
                0.00000000000000000049,		// 18
        };

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
    if (precision <= 18)
        f += rounders[precision];
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
        while (precision)
        {
          /*  if (precision == 1 && ((f > 0.5)  || (f > 0.5 && (f / 10 < 0.05))))
            {
                f += 0.05;
                if(f > 0.99)
                {
                    result--;
                    f /= 10.0;
                    precision ++;
                    continue ;
                }
                    
            }
            //else if ((f > 0.5) && (f / 10 < 0.05)
*/
                
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
    //int i = 0;

    //i |= (1 << 7);

    //  printf("\n-%d-\n", i);
    ftoa(arg_float, *result, lst->pricision);
}