/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_str2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:07:51 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/15 16:01:37 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_change_type_hex_l(long long int *arg, t_plist *lst)
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

void	ft_change_type_hex(long long int *arg, t_plist *lst)
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

void	ft_pricision_hex2(char *result, t_plist *lst, size_t len, char *str)
{
	char						*tmp;

	tmp = (char*)malloc(sizeof(char) * (lst->pr + len + lst->w + 1));
	ft_memset(tmp, ' ', lst->w - lst->pr);
	if ((lst->flag & MINUS) == MINUS)
	{
		if (lst->pr > len)
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

void	ft_pricision_hex(char *result, t_plist *lst, size_t len, char *str)
{
	char						*tmp;

	tmp = (char*)malloc(sizeof(char) * (lst->pr + len + lst->w + 1));
	if (lst->w > lst->pr + len)
		ft_pricision_hex2(result, lst, len, str);
	else
	{
		ft_memset(tmp, '0', lst->pr - len);
		ft_strcpy(result, tmp);
		ft_strcat(result, str);
		ft_strdel(&tmp);
	}
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
