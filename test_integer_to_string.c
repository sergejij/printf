/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_integer_to_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:01:20 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/15 17:09:13 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_sym_count;

void	ft_change_type_int(int *arg, t_plist *lst)
{
	short	new_arg_h;
	char	new_arg_hh;

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

void	ft_check_flags_int(char **result, char *arg, int arg_i, t_plist *lst)
{
	char *tmp;

	tmp = NULL;
	if ((lst->flag & MINUS) == MINUS)
		ft_minus(result, arg, lst, lst->len);
	else if (((lst->flag & PLUS) == PLUS))
		ft_plus(result, arg, lst, lst->len);
	else if (((lst->flag & ZERO) == ZERO))
		ft_recording(result, arg, lst, '0');
	else
		ft_recording(result, arg, lst, ' ');
	if ((lst->flag & SPACE) == SPACE && (lst->flag & PLUS) != PLUS
			&& arg_i >= 0 && lst->w <= lst->len)
	{
		tmp = ft_strnew(ft_strlen(*result) + 1);
		*tmp = ' ';
		ft_strcat(tmp, *result);
		ft_strcpy(*result, tmp);
		ft_strdel(&tmp);
	}
}

void	ft_add_integer(char **result, int arg_int, t_plist *lst)
{
	size_t	len;
	char	*arg;

	arg = NULL;
	if (lst->mod)
		ft_change_type_int(&arg_int, lst);
	arg = ft_itoa(arg_int);
	len = ft_strlen(arg);
	if (*arg == '0' && len == 1)
	{
		if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
		{
			*arg = '\0';
			len = 0;
		}
	}
	lst->len = len;
	ft_check_flags_int(result, arg, arg_int, lst);
}
