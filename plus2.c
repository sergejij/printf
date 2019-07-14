/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:34:29 by aestella          #+#    #+#             */
/*   Updated: 2019/07/14 19:42:40 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus_neg_width_zero(char **res, char *arg, t_plist *lst, size_t len)
{
	char	*tmp;

	tmp = NULL;
	if (lst->pr > len)
	{
		tmp = (char*)malloc(sizeof(char) * (lst->pr));
		ft_memset(*res, ' ', lst->w - (lst->pr + 1));
		*tmp = '-';
		ft_memset(tmp + 1, '0', lst->pr - (len - 1));
		ft_strcat(*res, tmp);
		ft_strcat(*res, arg + 1);
		ft_strdel(&tmp);
	}
	else if (lst->pr && lst->pr < len)
	{
		ft_memset(*res, ' ', lst->w - len);
		ft_strcat(*res, arg);
	}
}

void	ft_plus_neg_width_prec(char **res, char *arg, t_plist *lst, size_t len)
{
	char	*tmp;
	char	*tmp1;

	tmp = NULL;
	tmp = (char*)malloc(sizeof(char) * (lst->pr + len));
	tmp1 = tmp;
	if (lst->w > lst->pr)
	{
		ft_memset(*res, ' ', lst->w - lst->pr - 1);
		ft_strcat(*res, "-");
		ft_memset(tmp, '0', lst->pr - len + 1);
		ft_strcat(*res, tmp);
		ft_strcat(*res, (arg) + 1);
		ft_strdel(&tmp);
		return ;
	}
	tmp = ft_memset(tmp, '0', lst->pr - len);
	ft_strcat(tmp, arg);
	ft_memset(*res, ' ', lst->w - (lst->pr + 1));
	tmp = ft_strjoin("+", arg);
	ft_strdel(&tmp1);
	ft_strcpy((*res) + lst->w - (lst->pr + 1), tmp);
	ft_strdel(&tmp);
}

void	ft_plus_negative_width(char **res, char *arg, t_plist *lst, size_t len)
{
	if (lst->pr > len && (lst->flag & ZERO) != ZERO)
		ft_plus_neg_width_prec(res, arg, lst, len);
	else if (((lst->flag & ZERO) == ZERO) && lst->w > len && lst->w > lst->pr)
	{
		if (lst->pr)
			ft_plus_neg_width_zero(res, arg, lst, len);
		else
		{
			(*res)[0] = '-';
			ft_memset(&(*res)[1], '0', lst->w - len);
			ft_strcat(*res, ++arg);
		}
	}
	else
	{
		ft_memset(*res, ' ', lst->w - lst->len);
		ft_strcpy(*res + lst->w - lst->len, arg);
	}
}

void	ft_plus_negative(char **result, char *arg, t_plist *lst, size_t len)
{
	if (lst->w > len)
		ft_plus_negative_width(result, arg, lst, len);
	else if (lst->pr >= len)
	{
		ft_strncpy(*result, arg, 1);
		ft_memset((*result) + 1, '0', lst->pr - (len - 1));
		arg++;
		ft_strcat(*result, arg);
	}
	else
		*result = arg;
}
