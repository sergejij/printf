/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_str3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:19:21 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/15 16:04:51 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_uhex_str2(char **result, char *str, char sym, t_plist *lst)
{
	char						*tmp;
	char						*cpy_res;

	cpy_res = (char*)malloc(sizeof(char) * 100);
	tmp = str;
	ft_strcpy(cpy_res, str);
	if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) != ZERO && *str != '0')
	{
		if (lst->pr > lst->len)
			ft_pricision_hex(cpy_res, lst, lst->len, str);
		cpy_res = ft_strjoin(sym == 'x' ? "0x" : "0X", cpy_res);
	}
	ft_transform_int_result(result, cpy_res, lst);
	if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO && *str != '0')
	{
		if (lst->w > lst->len)
			*result = ft_strjoin(sym == 'x' ? "0x" : "0X", (*result) + 2);
		else
			*result = ft_strjoin(sym == 'x' ? "0x" : "0X", *result);
	}
}

size_t	ft_lennum_hex(long long int num)
{
	size_t						len;

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

char	*ft_itoa_hex(long long int n, char sym)
{
	int							len;
	unsigned long long int		number;
	char						*result;
	char						*a;

	a = (sym == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	len = n < 0 ? 8 : ft_lennum_hex(n);
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

char	*ft_itoa_uhex(unsigned long long int n, char sym)
{
	int							len;
	unsigned long long int		number;
	char						*result;
	char						*a;

	a = (sym == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	len = ft_lennum_uhex(n);
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

int		ft_if_zero_x(char **result, char *str, t_plist *lst)
{
	if (*str == '0' && lst->len == 1 && lst->pr == 0)
	{
		if (lst->w > 0 && (lst->flag & ZERO_PRIC) == ZERO_PRIC)
		{
			memset(*result, ' ', lst->w);
			return (0);
		}
		else if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
		{
			*str = '\0';
			lst->len = 0;
			if (!lst->w)
				return (0);
		}
		else if (!(lst->w))
		{
			*result = "0";
			return (0);
		}
	}
	return (1);
}
