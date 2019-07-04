/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:02:53 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/04 15:18:02 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_pricision_hex(char **result, t_prinlist *lst, size_t len, char *str)
{
    char *tmp;
    //char *spaces;

    tmp = (char*)malloc(sizeof(char) * (lst->pricision - len));
    /*if (lst->width > len && lst->width > lst->pricision)
        ft_memset(*result, ' ', lst->width - lst->pricision);
    else */
    if (lst->width > lst->pricision + len)
    {
        //spaces = (char*)malloc(sizeof(char) * (lst->width - lst->pricision));
        ft_memset(tmp, ' ', lst->width - lst->pricision);
        if ((lst->flag & MINUS) == MINUS)
        {
            
            *result = ft_strjoin(ft_strjoin("0", str), tmp);
        }
        else
        { 
            ft_memset(tmp + lst->width - lst->pricision, '0', lst->pricision - len);
            *result = ft_strjoin(tmp, str);
        }
    }
    else
    {
        ft_memset(tmp, '0', lst->pricision - len);
        *result = ft_strjoin(tmp, str);
    }
    //ft_memset(*result + (lst->width - lst->pricision), '0', lst->pricision  - len);
}

size_t  ft_lennum_hex(long long int num)
{
    size_t len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

char		*ft_itoa_hex(long long int n, char sym)
{
	int				len;
	int				counter;
	unsigned long long int	number;
	char			*result;
    char *a;

    if (sym == 'x')
        a = "0123456789abcdef";
    else 
        a = "0123456789ABCDEF";
	len = n < 0 ? 8 : ft_lennum_hex(n);
	counter = 0;
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	number = n;
	if (number == 0)
		result[0] = '0';
	while (number > 0)
	{
		result[len - 1] = a[number % 16];
		number /= 16;
		len--;
	}
	return (result);
}

void ft_add_hex_str(char **result, long long int arg, t_prinlist *lst, char sym)
{
    // не заполняет нулями, не работает с отрицательными числами, не работает с #
    //size_t len;
    char *str;
    char *tmp;
    size_t len;
    
    len = arg < 0 ? 8 : ft_lennum_hex(arg);
    str = ft_itoa_hex(arg, sym);
    tmp = str;
    if(*str == '0' && len == 1 && lst->pricision == 0)
    {
        if (lst->width > 0 && (lst->flag & ZERO_PRIC) == ZERO_PRIC)
        {
            memset(*result, ' ', lst->width);
            return ;
        }
        else if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
        {
            *str = '\0';
            len = 0;
            if (!lst->width)
                return ;  
        }
        else if (!(lst->width))
        {   
            *result = "0";
            return ;
        }
    }
    ft_strcpy(*result, str);
    if ((lst->flag & HASH) == HASH && /*(lst->flag & ZERO) != ZERO &&*/ *str != '0')
        *result = ft_strjoin(sym == 'x' ? "0x" : "0X", *result);    
    ft_transform_int_result(result, lst);



    //if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO)
    //    *result = ft_strjoin(sym == 'x' ? "0x" : "0X", *result);
    
    // тернарники огонь
    /*if ((lst->flag & ZERO) == ZERO  && (lst->flag & MINUS) != MINUS)
        ft_hex_zero(&str, lst, len);
    if ((lst->flag & HASH) == HASH)
        str = ft_strjoin(sym == 'x' ? "0x" : "0X", str); // тернарники огонь
    if (lst->pricision < len)
        *result = ft_add_string(*result, str, lst, 16);
    else
        ft_pricision_hex(result, lst, len, str);*/

}
