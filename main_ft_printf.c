/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:58:23 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/14 18:56:59 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_sym_count = 0;

int		ft_is_type(char *c, t_prinlist *lst)
{
	if (*c == 'x')
		lst->h = x;
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

void	ft_digit_type(char **result, va_list ap, t_prinlist *lst)
{
	if (lst->mod == L_ONE || lst->mod == LL)
		ft_long_to_str(result, va_arg(ap, long long int), lst);
	else
		ft_add_integer(result, va_arg(ap, int), lst);
}

void	ft_hex_type(char *format, char **result, va_list ap, t_prinlist *lst)
{
	if (lst->mod == L_ONE)
		ft_uh(result, va_arg(ap, unsigned long int), lst, *format);
	else if (lst->mod == LL)
		ft_uh(result, va_arg(ap, unsigned long long int), lst, *format);
	else
		ft_add_hex_str(result, va_arg(ap, int), lst, *format);
}

void	ft_octal_type(char **result, va_list ap, t_prinlist *lst)
{
	if (lst->mod == L_ONE || lst->mod == LL)
		ft_add_octal_u(result, va_arg(ap, unsigned long long), lst);
	else
		ft_add_octal(result, va_arg(ap, unsigned int), lst);
}

void	ft_unsigned_type(char **result, va_list ap, t_prinlist *lst)
{
	if (lst->mod == L_ONE)
		ft_add_unsigned(result, va_arg(ap, unsigned long int), lst);
	else if (lst->mod == LL)
		ft_add_unsigned(result, va_arg(ap, unsigned long long int), lst);
	else
		ft_add_unsigned(result, va_arg(ap, unsigned int), lst);
}

void	ft_a_typ(char *format, char *res, va_list ap, t_prinlist *lst)
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

void	ft_delete_excess_flags(t_prinlist *lst)
{
	if ((lst->flag & ZERO_PRIC) == ZERO_PRIC && (lst->flag & ZERO) == ZERO)
		lst->flag = lst->flag ^ ZERO;
	if ((lst->flag & PLUS) == PLUS && (lst->flag & SPACE) == SPACE)
		lst->flag = lst->flag ^ SPACE;
	if ((lst->flag & MINUS) == MINUS && (lst->flag & ZERO) == ZERO)
		lst->flag = lst->flag ^ ZERO;
	if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO && lst->pr)
		lst->flag = lst->flag ^ ZERO;
}

void	ft_analise_flags3(char **format, t_prinlist *lst, unsigned int *flag)
{
	if (ft_isdigit(**format))
	{
		lst->w = (size_t)ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '.')
	{
		lst->pr = (size_t)ft_atoi(++(*format));
		if (lst->pr == 0)
			*flag = *flag | ZERO_PRIC;
		while (ft_isdigit(**format))
			(*format)++;
	}
}

int		ft_analise_flags2(char *format, unsigned int *flag)
{
	if (*format == '#')
		*flag = (*flag | HASH);
	else if (*format == '0')
		*flag = *flag | ZERO;
	else if (*format == '-')
		*flag = *flag | MINUS;
	else if (*format == '+')
		*flag = *flag | PLUS;
	else if (*format == ' ')
		*flag = *flag | SPACE;
	else
		return (0);
	return (1);
}

int		ft_analise_flags(char *format, t_prinlist *lst)
{
	unsigned int flag;

	flag = 0;
	format++;
	while (*format && !(ft_is_type(format, lst)))
	{
		if (ft_analise_flags2(format, &flag))
			;
		else if (ft_isdigit(*format) || *format == '.')
		{
			ft_analise_flags3(&format, lst, &flag);
			continue ;
		}
		format++;
	}
	lst->flag = flag;
	ft_delete_excess_flags(lst);
	return (flag);
}

t_prinlist	*make_struct_for_flags(char *format)
{
	t_prinlist *new;

	new = NULL;
	if (!(new = (t_prinlist *)malloc(sizeof(t_prinlist))))
		return (NULL);
	new->pr = 0;
	new->w = 0;
	new->mod = 0;
	new->flag = 0;
	new->len = 0;
	ft_analise_flags(format, new);
	return (new);
}

void	ft_free_result_and_lst(char **result, t_prinlist **lst)
{
	if (*result)
		ft_strdel(&(*result));
	free(*lst);
	*lst = NULL;
}

void	ft_printf_1(char *result, t_prinlist *lst,
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
	va_list			ap;
	const char		*p_ap_f;
	t_prinlist		*lst;
	char			*result;

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
