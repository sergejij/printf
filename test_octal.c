/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:01:40 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/29 16:52:00 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t  ft_lennum_octal(int num)
{
    size_t len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 8;
	}
	return (len);
}

char		*ft_itoa_octal(int n)
{
	int				len;
	int				counter;
	unsigned int	number;
	char			*result;
    char *a;

    a = "0123456789abcdef";;
	len = n < 0 ? 11 : ft_lennum_octal(n);
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
		result[len - 1] = a[number % 8];
		number /= 8;
		len--;
	}
	return (result);
}

void ft_octal_zero(char **str, t_prinlist *lst, size_t len)
{
    char *tmp;
    char *tmp2;

    tmp = (char*)malloc(sizeof(char) * (lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0)));
    tmp2 = *str;
    if (lst->width > len && (lst->flag & ZERO) == ZERO)
    {
        if ((lst->flag & MINUS) == MINUS)
        {
            ft_strcpy(tmp, *str);
            ft_memset(tmp + len, ' ', lst->width - len - ((lst->flag & HASH) == HASH ? 2 : 0));
        }
        else
        {
            ft_memset(tmp, '0', lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0));
            ft_strcpy(tmp + lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0), *str);
        }
        *str = tmp;
    }
    else if (lst->width > len)
    {
        ft_memset(tmp, ' ', lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0));
        ft_strcpy(*str + len, tmp);
    }
    ft_strdel(&tmp2);
}

void ft_add_octal(char **result, int arg, t_prinlist *lst)
{
    // не заполняет нулями, не работает с отрицательными числами, не работает с #
    //size_t len;
    char *str;
    char *tmp;
    size_t len;
    
    if (arg == 0)
    {
        *result = "0";
        return ;
    }
    len = arg < 0 ? 8 : ft_lennum_octal(arg);
    str = ft_itoa_octal(arg);
    tmp = str;
    //len = ft_lennum_hex(arg);
    /*if ((lst->flag & HASH) == HASH)
    {
        tmp = str;
        if (arg < 0)
            str = ft_strjoin("0xffff", str);
        else
        str = ft_strjoin("0x", str);
        ft_strdel(&tmp);
    }*/ // такой кастыль не подходит
    if ((lst->flag & ZERO) == ZERO)
        ft_octal_zero(&str, lst, len);
    if ((lst->flag & HASH) == HASH)
        str = ft_strjoin("0", str); // тернарники огонь
    if (lst->pricision < len)
        *result = ft_add_string(*result, str, lst, 8);
    else
        ft_pricision_hex(result, lst, len, str);
        //printf("%s", str);
}