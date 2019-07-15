/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:16:22 by aestella          #+#    #+#             */
/*   Updated: 2019/07/15 17:17:19 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_type(char *c, t_plist *lst)
{
	if (*c == 'x')
		lst->h = X;
	if (*c == 's' || *c == 'c' || *c == 'p' || *c == 'i' || *c == 'd'
			|| *c == 'i' || *c == '%' || *c == 'x' || *c == 'X'
			|| *c == 'o' || *c == 'u' || *c == 'f')
		return (1);
	else if (*c == 'h' && lst->mod != HH)
	{
		c++;
		if (*c == 'h')
			lst->mod = HH;
		else
			lst->mod = H;
	}
	else if (*c == 'l' && lst->mod != LL)
	{
		c++;
		if (*c == 'l')
			lst->mod = LL;
		else
			lst->mod = L_ONE;
	}
	return (0);
}

void	ft_digit_type(char **result, va_list ap, t_plist *lst)
{
	if (lst->mod == L_ONE || lst->mod == LL)
		ft_long_to_str(result, va_arg(ap, long long int), lst);
	else
		ft_add_integer(result, va_arg(ap, int), lst);
}

void	ft_hex_type(char *format, char **result, va_list ap, t_plist *lst)
{
	if (lst->mod == L_ONE)
		ft_uh(result, va_arg(ap, unsigned long int), lst, *format);
	else if (lst->mod == LL)
		ft_uh(result, va_arg(ap, unsigned long long int), lst, *format);
	else
		ft_add_hex_str(result, va_arg(ap, int), lst, *format);
}

void	ft_octal_type(char **result, va_list ap, t_plist *lst)
{
	if (lst->mod == L_ONE || lst->mod == LL)
		ft_add_octal_u(result, va_arg(ap, unsigned long long), lst);
	else
		ft_add_octal(result, va_arg(ap, unsigned int), lst);
}

void	ft_unsigned_type(char **result, va_list ap, t_plist *lst)
{
	if (lst->mod == L_ONE)
		ft_add_unsigned(result, va_arg(ap, unsigned long int), lst);
	else if (lst->mod == LL)
		ft_add_unsigned(result, va_arg(ap, unsigned long long int), lst);
	else
		ft_add_unsigned(result, va_arg(ap, unsigned int), lst);
}
