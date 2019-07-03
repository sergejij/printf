/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:23:14 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/01 17:31:57 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static const double rounders[20 + 1] =
        {
                0.5,				        // 0
                0.05,				        // 1
                0.005,			        	// 2
                0.0005,		        	// 3
                0.00005,		        	// 4
                0.000005,		        	// 5
                0.0000005,		        	// 6
                0.00000005,	        	// 7
                0.000000005,	        	// 8
                0.0000000005,		        // 9
                0.00000000005,		        // 10
                0.000000000005,	       	// 11
                0.0000000000005,	       	// 12
                0.00000000000005,		    // 13
                0.000000000000005,		    // 14
                0.0000000000000005,		// 15
                0.00000000000000005,		// 16
                0.000000000000000005,		// 17
                0.0000000000000000005,		// 18
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
        if(((f - intPart) == 0.5 && (intPart % 2) == 0 )|| f < 0)
            f -= rounders[precision];
        else
            f += rounders[precision];
    }
    intPart = f;
    f -= intPart;
    ptr = ft_itoa(intPart);//ft_ltoa(&result, intPart);
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
            f *= 10.0; //мб для больших точностей округлять прям внутри цикла самый последний? на точность 32 уже проблемы с округлением
            c = f;
            *result++ = '0' + c;
            f -= c;
            precision--;
        }
        *result = 0;
    }
    
    return p1;
}

char *ft_simple_ftoa(double f, char *result, int precision)
{
    char *ptr = result;
    char *p1;
    char c;
    long long intPart;

    intPart = f;
    f -= intPart;
    ptr = ft_itoa(intPart);//ft_ltoa(&result, intPart);
    ft_strcpy(result, ptr);
    p1 = result;
    if (precision <= 18)
    {
        if( (f - intPart) == 0.5 && (intPart % 2) == 0)
            f -= rounders[precision];
        else
            f += rounders[precision];
    }
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
    if(lst->pricision || (lst->flag & ZERO_PRIC) == ZERO_PRIC)
        ft_ftoa(arg_float, *result, lst->pricision);
    else
        ft_simple_ftoa(arg_float, *result, 6);
    lst->pricision = 0;
    if(lst->flag || lst->width)
        ft_transform_int_result(result, lst);
    if ((lst->flag & SPACE) == SPACE && (lst->flag & PLUS) != PLUS && arg_float >=0 && lst->width <= lst->len)
        *result = ft_strjoin(" ", *result);
}