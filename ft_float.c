/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:29:58 by aestella          #+#    #+#             */
/*   Updated: 2019/07/14 19:30:45 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_roundering(char *cur_res, size_t pric, t_len *len_l)
{
	char			*round;
	char			*tmp;
	int				r_nbr;

	r_nbr = ft_check_len_int(cur_res) + pric + 1;
	if (!(round = (char *)malloc(sizeof(char) * (pric + 5))))
		return ;
	tmp = round;
	ft_strcpy(round, "0.");
	ft_memset((tmp + 2), '0', pric);
	tmp[pric + 2] = '5';
	tmp[pric + 3] = '\0';
	if (cur_res[r_nbr - 1] == '.')
	{
		if ((cur_res[r_nbr - 2] - '0') % 2 != 0 || (cur_res[r_nbr] - '0') >= 5)
			ft_plus_float(cur_res, round, len_l);
	}
	else
	{
		if ((cur_res[r_nbr - 1] - '0') % 2 != 0 || (cur_res[r_nbr] - '0') >= 5)
			ft_plus_float(cur_res, round, len_l);
	}
}

unsigned long	ft_make_mantissa(long double nbr)
{
	unsigned long	mantissa;
	unsigned char	mem_p;
	int				bits;
	int				byte;
	unsigned long	g;

	mantissa = 0;
	mem_p = 0;
	bits = 0;
	byte = -1;
	g = 1;
	while (byte++ < 8)
	{
		bits = 0;
		mem_p = *((unsigned char *)&nbr + byte);
		while (bits++ < 8)
		{
			if (mem_p & 1 && byte * 8 + bits <= 64)
				mantissa |= g;
			mem_p >>= 1;
			if (byte * 8 + bits <= 64)
				g <<= 1;
		}
	}
	return (mantissa);
}

short			ft_make_exponent(long double nbr)
{
	unsigned short	exponent;
	unsigned char	mem_p;
	short			*ptr;

	exponent = 0;
	mem_p = *((unsigned char *)&nbr + 9);
	exponent |= mem_p;
	exponent <<= 8;
	mem_p = *((unsigned char *)&nbr + 8);
	exponent |= mem_p;
	exponent = exponent - 16383;
	ptr = (short*)&exponent;
	return (*ptr);
}

char			*ft_inf_nan(int sign, long double arg_d, t_plist *lst)
{
	char	*res;

	if (!(res = ft_strnew(4)))
		exit(1);
	if ((arg_d != arg_d))
	{
		ft_strcpy(res, "nan");
		if ((lst->flag & MINUS) == MINUS)
		{
			lst->flag = 0;
			lst->flag = lst->flag ^ MINUS;
		}
		else if (lst->flag)
			lst->flag = 0;
	}
	else
	{
		sign < 0 ? ft_strcpy(res, "-inf") : ft_strcpy(res, "inf");
		if ((lst->flag & ZERO) == ZERO)
			lst->flag = lst->flag ^ ZERO;
	}
	return (res);
}

void			ft_parse_d(char **result, long double arg_d, t_plist *lst)
{
	char			*tmp_result;
	unsigned long	mantissa;
	unsigned char	mem_p;
	short			exponent;
	int				sign;

	tmp_result = NULL;
	mem_p = *((unsigned char *)&arg_d + 9);
	sign = (mem_p >> 7) == 0 ? 1 : -1;
	if (sign < 0)
		arg_d = -arg_d;
	mantissa = ft_make_mantissa(arg_d);
	exponent = ft_make_exponent(arg_d);
	if ((lst->pr == 0 || lst->pr > 2000)
			&& (lst->flag & ZERO_PRIC) != ZERO_PRIC)
		lst->pr = 6;
	if (exponent == 16384)
		tmp_result = ft_inf_nan(sign, arg_d, lst);
	if (!(is_nan_inf(tmp_result)))
		tmp_result = ft_add_d(mantissa, exponent, sign, lst);
	ft_choice_options(result, tmp_result, lst);
}
