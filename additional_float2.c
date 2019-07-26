/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_float2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:51:07 by aestella          #+#    #+#             */
/*   Updated: 2019/07/15 16:02:43 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_neg_sign(char **float_nbr, char **buff)
{
	char	*tmp;

	tmp = NULL;
	**buff = '-';
	(*buff)[1] = '\0';
	tmp = *float_nbr;
	ft_strcat(*buff, *float_nbr);
	*float_nbr = *buff;
	*buff = tmp;
}

int		is_nan_inf(char *dbl)
{
	if (!dbl)
		return (0);
	else if ((ft_strcmp(dbl, "inf")) && (ft_strcmp(dbl, "-inf"))
			&& (ft_strcmp(dbl, "nan")))
		return (0);
	else
		return (1);
}

t_len	*ft_make_len_struct(void)
{
	t_len	*len_l;

	len_l = malloc(sizeof(t_len));
	len_l->r = 0;
	len_l->pow = 0;
	len_l->cur_n = 0;
	len_l->i_part = 0;
	len_l->is_float_p = 0;
	len_l->one_left_one = 0x8000000000000000;
	return (len_l);
}

void	ft_plus_float(char *cur_n, char *power_two, t_len *l)
{
	if (!(*cur_n))
	{
		ft_strcpy(cur_n, power_two);
		return ;
	}
	ft_make_even(cur_n, power_two);
	l->cur_n = ft_strlen(cur_n);
	l->pow = ft_strlen(power_two);
	if (l->cur_n < l->pow)
	{
		ft_memset((cur_n) + (l->cur_n), '0', (l->pow - l->cur_n));
		l->cur_n += l->pow - l->cur_n;
	}
	if (l->cur_n > l->pow)
	{
		ft_memset((power_two) + (l->pow), '0', (l->cur_n - l->pow));
		l->pow += l->cur_n - l->pow;
	}
	l->is_float_p = 1;
	ft_plus_int(cur_n, power_two, l);
	if (ft_strlen(cur_n) > (l->cur_n > l->pow ?
				l->cur_n - 2 : l->pow - 2))
		cur_n[0] = *cur_n;
}

void	ft_choice_options(char **result, char *tmp_result, t_plist *lst)
{
	if (tmp_result && (lst->flag & ZERO_PRIC) == ZERO_PRIC
			&& (lst->flag & HASH) != HASH && !(is_nan_inf(tmp_result)))
		tmp_result[ft_check_len_int(tmp_result)] = '\0';
	lst->pr = 0;
	if (lst->flag || lst->w)
	{
		if (lst->w > 2000)
			lst->w = 0;
		ft_transform_int_result(result, tmp_result, lst);
	}
	else
		ft_strcpy(*result, tmp_result);
}
