/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:48:10 by aestella          #+#    #+#             */
/*   Updated: 2019/07/15 16:54:46 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pricision(char **res, t_plist *lst, size_t len, char *arg)
{
	if (lst->w > len && lst->w > lst->pr)
		ft_memset(*res, ' ',
				arg[0] == '-' ? lst->w - (lst->pr + 1) : lst->w - lst->pr);
	else if (lst->w < lst->pr && lst->pr >= len)
	{
		ft_memset(*res, '0',
				arg[0] == '-' ? lst->pr - (len - 1) : lst->pr - len);
		(*res)[arg[0] == '-' ? lst->pr - (len - 1) : lst->pr - len] = '\0';
		return ;
	}
	if (ft_strncmp(arg, "-", 1) == 0)
	{
		ft_strcat(*res, "-");
		ft_memset(*res + (lst->w - lst->pr), '0', lst->pr - (len - 1));
		if (lst->w > lst->len)
			ft_strcat(*res, arg + 1);
	}
	else
		ft_memset(*res + (lst->w - lst->pr), '0', lst->pr - len);
}

void	ft_transform_int_result(char **result, char *cpy_num, t_plist *lst)
{
	lst->len = ft_strlen(cpy_num);
	if ((lst->flag & MINUS) == MINUS)
		ft_minus(result, cpy_num, lst, lst->len);
	else if (((lst->flag & PLUS) == PLUS))
		ft_plus(result, cpy_num, lst, lst->len);
	else if (((lst->flag & ZERO) == ZERO))
		ft_recording(result, cpy_num, lst, '0');
	else
	{
		ft_recording(result, cpy_num, lst, ' ');
	}
	if ((lst->flag & SPACE) == SPACE && (lst->flag & PLUS) != PLUS
			&& **result != '-' && lst->w < lst->len)
	{
		ft_strcpy(*result, " ");
		ft_strcat(*result, cpy_num);
	}
}

int		ft_ltoa_set_piace(long long arg, char **new_res)
{
	int	piece;
	int del;
	int i;

	del = 100000;
	i = 0;
	while (arg > del)
	{
		piece = (int)(arg % del);
		arg /= del;
		new_res[i] = ft_itoa(piece);
		i++;
	}
	new_res[i] = ft_itoa((int)arg);
	new_res[++i] = NULL;
	return (i);
}

void	ft_ltoa(char **result, long long arg, int i)
{
	char	**new_res;
	char	*tmp;

	tmp = *result;
	if (!(new_res = (char **)malloc(sizeof(char*) * 5)))
		return ;
	if (arg < 0)
	{
		if (-9223372036854775807 > arg)
		{
			ft_strcpy(*result, "-9223372036854775808");
			return ;
		}
		**result = '-';
		arg *= -1;
	}
	i = ft_ltoa_set_piace(arg, new_res);
	while (i-- > 0)
	{
		ft_strcat(*result, new_res[i]);
		tmp = *result + 5;
		ft_strdel(&(new_res[i]));
	}
	free(new_res);
}

void	ft_long_to_str(char **result, long long int arg, t_plist *lst)
{
	char	*arg_str;
	int		i;

	i = 0;
	arg_str = ft_strnew(22);
	ft_ltoa(&arg_str, arg, i);
	if (lst->flag || lst->w || lst->pr)
		ft_transform_int_result(result, arg_str, lst);
	else
		ft_strcpy(*result, arg_str);
	ft_strdel(&arg_str);
}
