/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:16:07 by aestella          #+#    #+#             */
/*   Updated: 2019/07/15 17:17:19 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_delete_excess_flags(t_plist *lst)
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

void	ft_analise_flags3(char **format, t_plist *lst, unsigned int *flag)
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

int		ft_analise_flags(char *format, t_plist *lst)
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

t_plist	*make_struct_for_flags(char *format)
{
	t_plist *new;

	new = NULL;
	if (!(new = (t_plist *)malloc(sizeof(t_plist))))
		return (NULL);
	new->pr = 0;
	new->w = 0;
	new->mod = 0;
	new->flag = 0;
	new->len = 0;
	ft_analise_flags(format, new);
	return (new);
}
