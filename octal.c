/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:01:40 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/15 16:47:11 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_if_zero_o(char **result, char *str, t_plist *lst)
{
	if (*str == '0' && lst->len == 1 && lst->pr == 0)
	{
		if (lst->w > 0 && (lst->flag & ZERO_PRIC) == ZERO_PRIC && ((lst->flag
			& MINUS) != MINUS) && ((lst->flag & ZERO) != ZERO) && !(lst->w))
		{
			memset(*result, ' ', lst->w);
			return (0);
		}
		else if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
		{
			if (((lst->flag & HASH) != HASH))
			{
				*str = '\0';
				if (!lst->w)
					return (0);
			}
		}
		else if (lst->w < 2)
		{
			*result = "0";
			return (0);
		}
	}
	return (1);
}

void	ft_add_octal_u_2(char **result, char *str, t_plist *lst)
{
	char						*tmp;
	char						*cpy_res;
	size_t						len_all;

	cpy_res = (char*)malloc(sizeof(char) * 100);
	tmp = str;
	ft_strcpy(cpy_res, tmp);
	if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) != ZERO && *str != '0')
	{
		if (lst->pr > lst->len)
			ft_pricision_hex(cpy_res, lst, lst->len, str);
		len_all = ft_strlen(cpy_res);
		if (lst->pr < len_all)
			cpy_res = ft_strjoin("0", cpy_res);
	}
	ft_transform_int_result(result, cpy_res, lst);
	if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO
			&& *str != '0' && lst->w < lst->len)
		*result = ft_strjoin("0", *result);
}

void	ft_add_octal_u(char **result, unsigned long long arg, t_plist *lst)
{
	char						*str;

	lst->len = ft_lennum_octal_u(arg);
	str = ft_itoa_octal(arg);
	if ((ft_if_zero_o(result, str, lst)) == 0)
		return ;
	ft_add_octal_u_2(result, str, lst);
}

void	ft_add_octal_2(char **result, char *str, t_plist *lst)
{
	char						*cpy_res;
	size_t						len_all;

	cpy_res = ft_strnew(100);
	if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) != ZERO && *str != '0')
	{
		if (lst->pr > lst->len)
			ft_pricision_hex(*result, lst, lst->len, str);
		len_all = ft_strlen(str);
		if (lst->pr < len_all)
			ft_strcpy(cpy_res, "0");
	}
	ft_strcat(cpy_res, str);
	ft_transform_int_result(result, cpy_res, lst);
	if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO
			&& *str != '0' && lst->w < lst->len)
	{
		ft_strcpy(cpy_res, "0");
		cpy_res[1] = '\0';
		ft_strcat(cpy_res, *result);
		ft_strcpy(*result, cpy_res);
	}
	ft_strdel(&cpy_res);
}

void	ft_add_octal(char **result, unsigned int arg, t_plist *lst)
{
	char						*str;

	if (lst->mod)
		ft_change_type_oct(&arg, lst);
	lst->len = ft_lennum_octal(arg);
	str = ft_itoa_octal(arg);
	if ((ft_if_zero_o(result, str, lst)) != 0)
		ft_add_octal_2(result, str, lst);
	ft_strdel(&str);
}
