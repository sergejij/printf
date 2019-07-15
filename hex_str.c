/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:02:53 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/15 16:00:47 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uh(char **result, unsigned long long arg,
		t_plist *lst, char sym)
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

void	ft_add_hex_str_4(char *tmp, char *cpy_res, t_plist *lst, char sym)
{
	ft_strdel(&tmp);
	tmp = ft_strsub(cpy_res, lst->w - lst->pr, lst->pr);
	cpy_res[lst->w - lst->pr - 2] = '\0';
	ft_strcat(cpy_res, sym == 'x' ? "0x" : "0X");
	ft_strcat(cpy_res, tmp);
}

void	ft_add_hex_str_3(char **result, char *cpy_res,
		t_plist *lst, char *str)
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

void	ft_add_hex_str_2(char **result, char *str, char sym, t_plist *lst)
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
			ft_add_hex_str_4(tmp, cpy_res, lst, sym);
		else if (lst->w > lst->len && lst->pr > lst->len
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
		t_plist *lst, char sym)
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
