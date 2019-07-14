/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:24:11 by aestella          #+#    #+#             */
/*   Updated: 2019/07/14 19:38:19 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_space_pls(char **result, char *arg, t_plist *lst, size_t len)
{
	**result = ' ';
	ft_memset(*result + 1, '0', lst->pr - len);
	ft_strcpy(*result + 1 + lst->pr - len, arg);
	ft_memset((*result) + 1 + lst->pr, ' ', lst->w - lst->pr - 1);
}

void	ft_minus_neg_prec(char **res, char *arg, t_plist *lst, size_t len)
{
	if ((lst->flag & PLUS) == PLUS)
		(*res)[0] = '+';
	ft_memset((*res)[0] == '+' ? *res + 1 : *res, '0', lst->pr - len);
	ft_strcpy(((*res)[0] == '+' ? *res + 1 : *res) + lst->pr - len, arg);
	if (lst->w > lst->pr)
	{
		if ((lst->flag & SPACE) == SPACE)
		{
			ft_add_space_pls(res, arg, lst, len);
			return ;
		}
		if ((*res)[0] == '+')
			ft_memset((*res) + 1 + lst->pr, ' ', lst->w - lst->pr - 1);
		else
			ft_memset(*res + lst->pr, ' ', lst->w - lst->pr);
	}
}

void	ft_minus_negative(char **result, char *arg, t_plist *lst, size_t len)
{
	if (lst->pr++ > len--)
	{
		(*result)[0] = '-';
		ft_memset((*result) + 1, '0', lst->pr - len);
		ft_strcpy((*result) + (lst->pr - len), ++arg);
		if (lst->w > lst->pr)
		{
			ft_memset((*result) + lst->pr, ' ', lst->w - lst->pr);
			(*result)[lst->w] = '\0';
		}
		else
			(*result)[lst->pr] = '\0';
	}
	else
	{
		ft_strcpy(*result, arg);
		if (lst->w > len)
			ft_memset((*result) + lst->len, ' ', lst->w - len - 1);
	}
}

void	ft_minus_hzs(char **result, char *arg, t_plist *lst, size_t len)
{
	if (lst->w > len)
	{
		if ((lst->flag & SPACE) == SPACE)
		{
			**result = ' ';
			ft_strcpy((*result) + 1, arg);
			ft_memset(*result + len + 1, ' ', lst->w - (len + 1));
		}
		else
		{
			ft_strcpy(*result, arg);
			ft_memset(*result + len, ' ', lst->w - len);
		}
	}
	else
		ft_strcpy(*result, arg);
}

void	ft_minus(char **result, char *arg, t_plist *lst, size_t len)
{
	if (*arg == '-')
		ft_minus_negative(result, arg, lst, lst->len);
	else if (lst->pr > len)
		ft_minus_neg_prec(result, arg, lst, lst->len);
	else
	{
		if (((lst->flag & PLUS) == PLUS))
		{
			ft_strcpy(*result, "+");
			ft_strcpy(*result + 1, arg);
			if (lst->w > len)
				ft_memset(*result + len + 1, ' ', lst->w - len - 1);
		}
		else
			ft_minus_hzs(result, arg, lst, lst->len);
	}
}
