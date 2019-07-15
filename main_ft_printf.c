/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:58:23 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/15 17:17:19 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_sym_count = 0;

void	ft_a_typ(char *format, char *res, va_list ap, t_plist *lst)
{
	if (*format == 'c')
		ft_add_char(&res, va_arg(ap, int), lst);
	else if (*format == 's')
		res = ft_add_string(&res, va_arg(ap, char*), lst, 1);
	else if (*format == 'p')
		ft_add_pointer(&res, va_arg(ap, unsigned long), lst);
	else if (*format == 'd' || *format == 'i')
		ft_digit_type(&res, ap, lst);
	else if (*format == 'x' || *format == 'X')
		ft_hex_type(format, &res, ap, lst);
	else if (*format == 'o')
		ft_octal_type(&res, ap, lst);
	else if (*format == 'u')
		ft_unsigned_type(&res, ap, lst);
	else if (*format == 'f')
		ft_parse_d(&res, va_arg(ap, double), lst);
	else if (*format == '%')
		ft_add_char(&res, '%', lst);
	if (!res)
		res = ft_strdup("(null)");
	ft_putstr(res);
	g_sym_count += ft_strlen(res);
}

void	ft_free_result_and_lst(char **result, t_plist **lst)
{
	if (*result)
		ft_strdel(&(*result));
	free(*lst);
	*lst = NULL;
}

void	ft_printf_1(char *result, t_plist *lst,
		const char **p_ap_f, va_list ap)
{
	char *tmp;

	result = (char *)malloc(sizeof(char) * 10000);
	ft_strclr(result);
	tmp = result;
	lst = make_struct_for_flags((char *)*p_ap_f);
	(*p_ap_f)++;
	while (!(ft_is_type((char *)*p_ap_f, lst)))
		(*p_ap_f)++;
	ft_a_typ((char *)*p_ap_f, result, ap, lst);
	(*p_ap_f)++;
	ft_free_result_and_lst(&result, &lst);
}

int		ft_printf(const char *apformat, ...)
{
	va_list		ap;
	const char	*p_ap_f;
	t_plist		*lst;
	char		*result;

	va_start(ap, apformat);
	p_ap_f = apformat;
	result = NULL;
	lst = NULL;
	while (*p_ap_f)
	{
		if (*p_ap_f == '%')
		{
			ft_printf_1(result, lst, &p_ap_f, ap);
			continue ;
		}
		else
		{
			write(1, p_ap_f, 1);
			g_sym_count++;
		}
		p_ap_f++;
	}
	return (g_sym_count);
}
