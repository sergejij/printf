/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:21:19 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/15 16:48:48 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_change_type_oct_h(unsigned int *arg, t_plist *lst)
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
}

void	ft_change_type_oct(unsigned int *arg, t_plist *lst)
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
	else
		ft_change_type_oct_h(arg, lst);
}

size_t	ft_lennum_octal(long long num)
{
	size_t						len;

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

size_t	ft_lennum_octal_u(unsigned long long num)
{
	size_t						len;

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

char	*ft_itoa_octal(unsigned long long n)
{
	long long				len;
	long long				counter;
	unsigned long long		number;
	char					*result;
	char					*a;

	a = "0123456789abcdef";
	len = ft_lennum_octal_u(n);
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
