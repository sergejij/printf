/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:29:52 by aestella          #+#    #+#             */
/*   Updated: 2019/07/15 16:51:38 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_sym_count;

char	*ft_make_cpy_str(char *str_arg, t_plist *lst, int num_s)
{
	char	*arg;
	size_t	len;

	arg = NULL;
	if (!str_arg)
	{
		if (!(arg = ft_strdup("(null)")))
			exit(1);
		len = 6;
	}
	else
	{
		len = ft_strlen(str_arg);
		if (!(arg = ft_strnew(len)))
			exit(1);
		ft_strcpy(arg, str_arg);
	}
	if (lst->pr && lst->pr < len && num_s != 16)
	{
		arg[lst->pr] = '\0';
		len = lst->pr;
	}
	lst->len = len;
	return (arg);
}

char	*ft_add_string(char **result, char *str_arg, t_plist *lst, int num_s)
{
	char	*arg;

	arg = NULL;
	arg = ft_make_cpy_str(str_arg, lst, num_s);
	if (lst->w > lst->len && ((lst->flag & MINUS) == MINUS))
	{
		ft_strcpy(*result, arg);
		ft_memset((*result) + lst->len, ' ', lst->w - lst->len);
	}
	else if (lst->w && lst->w > lst->len)
	{
		ft_memset(&((*result)[0]), ' ', lst->w - lst->len);
		ft_strcpy((*result) + (lst->w - lst->len), arg);
	}
	else
		ft_strcpy(*result, arg);
	ft_strdel(&arg);
	return (*result);
}

void	ft_print_full_chr_width(t_plist *lst)
{
	char	*tmp;

	tmp = NULL;
	tmp = (char*)malloc(sizeof(char) * lst->w - 1);
	ft_memset(tmp, ' ', lst->w - 1);
	write(1, tmp, lst->w - 1);
	g_sym_count += lst->w - 1;
	ft_strdel(&tmp);
}

void	ft_add_zero_chr(t_plist *lst)
{
	if (((lst->flag & MINUS) == MINUS))
	{
		write(1, "\0", 1);
		if (lst->w > 1)
			ft_print_full_chr_width(lst);
		return ;
	}
	else if (lst->w > 1)
		ft_print_full_chr_width(lst);
	write(1, "\0", 1);
	g_sym_count += 1;
}

void	ft_add_char(char **result, int chr_arg_int, t_plist *lst)
{
	char	chr_arg;

	chr_arg = (char)chr_arg_int;
	if (chr_arg == 0)
		ft_add_zero_chr(lst);
	else
	{
		if (lst->w > 1)
		{
			ft_memset(*result, ' ', lst->w);
			if ((lst->flag & MINUS) == MINUS)
				(*result)[0] = chr_arg;
			else
				(*result)[lst->w - 1] = chr_arg;
		}
		else
			(*result)[lst->w] = chr_arg;
	}
}
