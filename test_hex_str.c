/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:02:53 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/14 18:55:38 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_change_type_hex_l(long long int *arg, t_prinlist *lst)
{
	unsigned long				new_arg_l;
	unsigned long long			new_arg_ll;

	new_arg_l = 0;
	new_arg_ll = 0;
	if ((lst->mod & L_ONE) == L_ONE)
	{
		new_arg_l = *arg;
		*arg = new_arg_l;
	}
	else if ((lst->mod & LL) == LL)
	{
		new_arg_ll = *arg;
		*arg = new_arg_ll;
	}
}

void	ft_change_type_hex(long long int *arg, t_prinlist *lst)
{
	unsigned short				new_arg_h;
	unsigned char				new_arg_hh;

	new_arg_h = 0;
	new_arg_hh = 0;
	if ((lst->mod & H) == H)
	{
		new_arg_h = *arg;
		*arg = new_arg_h;
	}
	else if ((lst->mod & HH) == HH)
	{
		new_arg_hh = *arg;
		*arg = new_arg_hh;
	}
	else
		ft_change_type_hex_l(arg, lst);
}

void	ft_pricision_hex(char *result, t_prinlist *lst, size_t len, char *str)
{
	char						*tmp;

	tmp = (char*)malloc(sizeof(char) * (lst->pr + len + lst->w + 1));
	if (lst->w > lst->pr + len)
	{
		ft_memset(tmp, ' ', lst->w - lst->pr);
		if ((lst->flag & MINUS) == MINUS)
		{
		    if(lst->pr > len)
		        ft_memset(result, '0', lst->pr - len);
		    else
		        ft_strcpy(result, "0");
			ft_strcat(result, str);
			ft_strcat(result, tmp);
		}
		else
		{
			ft_memset(tmp + lst->w - lst->pr, '0', lst->pr - len);
			ft_strcpy(result, tmp);
			ft_strcat(result, str);
		}
	}
	else
	{
		ft_memset(tmp, '0', lst->pr - len);
		ft_strcpy(result, tmp);
		ft_strcat(result, str);
	}
	ft_strdel(&tmp);
}

size_t	ft_lennum_uhex(unsigned long long int num)
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

int	ft_if_zero_x(char **result, char *str, t_prinlist *lst)
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

void	ft_add_uhex_str2(char **result, char *str, char sym, t_prinlist *lst)
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

void	ft_uh(char **result, unsigned long long arg,
              t_prinlist *lst, char sym)
{
	char						*str;
	char						*tmp;

	lst->len = ft_lennum_uhex(arg);
	str = ft_itoa_uhex(arg, sym);
	tmp = str;
	if ((ft_if_zero_x(result, str, lst)) == 0)
		return ;
	ft_add_uhex_str2(result, str, sym, lst);
}

void	ft_add_hex_str_3(char **result, char *cpy_res,
		t_prinlist *lst, char *str)
{
	ft_transform_int_result(result, cpy_res, lst);
	ft_strdel(&cpy_res);
	if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO && *str != '0')
	{
		if (lst->w > lst->len)
			*result = ft_strjoin((lst->h & x) == x ? "0x" : "0X", *result + 2);
		else
			*result = ft_strjoin((lst->h & x) == x ? "0x" : "0X", *result);
	}
}

void	ft_add_hex_str_2(char **result, char *str, char sym, t_prinlist *lst)
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
		if (lst->w > lst->len && lst->pr > lst->len
				&& (lst->flag & MINUS) != MINUS)
		{
			ft_strdel(&tmp);
			tmp = ft_strsub(cpy_res,
					lst->w - lst->pr, lst->pr);
			cpy_res[lst->w - lst->pr - 2] = '\0';
			ft_strcat(cpy_res, sym == 'x' ? "0x" : "0X");
			ft_strcat(cpy_res, tmp);
		}
		else if(lst->w > lst->len && lst->pr > lst->len
                && (lst->flag & MINUS) == MINUS)
        {
            cpy_res[lst->len + lst->w - lst->pr - 2] = '\0';
            cpy_res = ft_strjoin(sym == 'x' ? "0x" : "0X", cpy_res);
        }
		else
			cpy_res = ft_strjoin(sym == 'x' ? "0x" : "0X", cpy_res);
	}
	ft_add_hex_str_3(result, cpy_res, lst, str);
}

void	ft_add_hex_str(char **result, long long int arg,
		t_prinlist *lst, char sym)
{
	char						*str;

	if (lst->mod)
		ft_change_type_hex(&arg, lst);
	lst->len = arg < 0 ? 8 : ft_lennum_hex(arg);
	str = ft_itoa_hex(arg, sym);
	if ((ft_if_zero_x(result, str, lst)) != 0)
	    ft_add_hex_str_2(result, str, sym, lst);
	ft_strdel(&str);
}
