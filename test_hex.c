/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:58:18 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/27 12:18:27 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t  ft_lennum_hex(int num)
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

char		*ft_itoa_hex(int n, char sym)
{
	int				len;
	int				counter;
	unsigned int	number;
	char			*result;
    char *a;

    if (sym == 'x')
        a = "0123456789abcdef";
    else 
        a = "0123456789ABCDEF";
	len = ft_lennum(n);
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

/*void    ft_minus_hex(char **result, int arg, t_prinlist *lst, size_t len)
{
    if (lst->pricision > len)
        ft_pricision_minus(result, arg, lst, len);
    else
    {
        if (((lst->flag & PLUS) == PLUS))
        {
            ft_strcpy(*result, "+");
            ft_strcpy(*result + 1, ft_itoa(arg));
            ft_memset(*result + len + 1, ' ', lst->width - len);
            return ;
        }
        ft_strcpy(*result, ft_itoa(arg));
        ft_memset(*result + len, ' ', lst->width - len);
    }
}*/

void ft_hex_zero(char **str, t_prinlist *lst, size_t len)
{
    char *tmp;
    char tmp2[lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0) + 1];

    if (lst->width > len)
    {
        tmp = *str;
        ft_memset(tmp2, '0', lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0));
        *str = ft_strjoin(tmp2, *str);
        ft_strdel(&tmp);
    }
}

void ft_add_hex(char **result, int arg, t_prinlist *lst, char sym)
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
    len = ft_lennum(arg);
    str = ft_itoa_hex(arg, sym);
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
        ft_hex_zero(&str, lst, len);
        //str = ft_strjoin(sym == 'x' ? "0x" : "0X", str);
    if ((lst->flag & HASH) == HASH)
        str = ft_strjoin(sym == 'x' ? "0x" : "0X", str); // тернарники огонь
    if (lst->pricision == 0)
        *result = ft_add_string(*result, str, lst);
    //printf("%s", str);
}