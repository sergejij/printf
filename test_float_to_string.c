/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_float_to_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:02:26 by aestella          #+#    #+#             */
/*   Updated: 2019/07/14 19:22:04 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_calculate(int *res, char *cn, char *cp, t_len *l)
{
	while (*cn || *cp)
	{
		if (*cn == '.' && *cp == '.')
		{
			res[l->cur_n++] = '.' - '0';
			cn++;
			cp++;
		}
		if (*cn && *cp)
			res[l->cur_n] = ((*cp++ - '0') + (*cn++ - '0') + l->is_float_p);
		else if (!(*cn) && *cp)
			res[l->cur_n] = *cp++ - '0' + l->is_float_p;
		else
			res[l->cur_n] = *cn++ - '0' + l->is_float_p;
		l->is_float_p = 0;
		if (res[l->cur_n] > 9)
		{
			l->is_float_p = res[l->cur_n] / 10;
			res[l->cur_n] %= 10;
		}
		l->cur_n++;
	}
	if (l->is_float_p)
		res[l->cur_n++] = l->is_float_p;
	l->is_float_p = 0;
}

void	ft_plus_int(char *cn, char *cp, t_len *l)
{
	int		*res;
	char	*tmp_curr;
	char	*tmp_power;

	l->cur_n = ft_strlen(cn) > ft_strlen(cp) ? ft_strlen(cn) : ft_strlen(cp);
	res = malloc(sizeof(int) * (l->cur_n + 1));
	tmp_curr = cn;
	tmp_power = cp;
	l->cur_n = 0;
	ft_strrev(cn);
	ft_strrev(tmp_power);
	l->is_float_p = 0;
	ft_calculate(res, tmp_curr, tmp_power, l);
	l->r = 0;
	while (l->cur_n--)
	{
		cn[l->r] = (char)(res[l->cur_n] + '0');
		l->r++;
	}
	cn[l->r] = '\0';
}

void	ft_paste_int_pl_float(char *int_p, char *f_part, size_t pric, t_len *l)
{
	char	*cur_n;
	int		len_int_part;

	cur_n = NULL;
	len_int_part = 0;
	if (!(*f_part))
	{
		ft_strcpy(f_part, "0.");
		ft_memset(f_part + 2, '0', pric);
	}
	cur_n = ft_strsub(f_part, 0, 1);
	ft_plus_int(int_p, cur_n, l);
	int_p[l->r] = '.';
	len_int_part = l->r;
	ft_strcat(int_p, f_part + ft_checkLenOfInt(f_part) + 1);
	ft_roundering(int_p, pric, l);
	int_p[ft_checkLenOfInt(int_p) + pric + 1] = '\0';
}

void	ft_binary_to_decimal(unsigned long mantissa, short exponent, char *int_p, char *f_part, t_len *len_l)
{
	unsigned long	one_left_one;
	char			*cur_n;

	one_left_one = 0x8000000000000000;
	while (mantissa && exponent >= 0)
	{
		if ((mantissa & one_left_one) == one_left_one)
		{
			cur_n = ft_find_power(exponent);
			ft_plus_int(int_p, cur_n, len_l);
		}
		exponent--;
		mantissa <<= 1;
	}
	while (mantissa)
	{
		if ((mantissa & one_left_one) == one_left_one)
		{
			cur_n = ft_find_power(exponent);
			ft_plus_float(f_part, cur_n, len_l);
		}
		mantissa <<= 1;
		exponent--;
	}
}

char	*ft_add_d(unsigned long mant, short exp, int sign, t_prinlist *lst)
{
	char	*int_part;
	char	*float_part;
	t_len	*len_l;

	len_l = ft_make_len_struct();
	int_part = ft_strnew(2000);
	float_part = ft_strnew(2000);
	ft_binary_to_decimal(mant, exp, int_part, float_part, len_l);
	ft_paste_int_pl_float(int_part, float_part, lst->pr, len_l);
	if (sign < 0)
		ft_add_neg_sign(&int_part, &float_part);
	return (int_part);
}
