/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:29:58 by aestella          #+#    #+#             */
/*   Updated: 2019/07/14 18:12:35 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_roundering(char *cur_res, size_t pric, t_len *len_l)
{
	char			*rounder;
	char			*tmp;
	int				r_nbr;

	r_nbr = ft_checkLenOfInt(cur_res) + pric + 1;
	if (!(rounder = (char *)malloc(sizeof(char) * (pric + 5))))
		return ;
	tmp = rounder;
	ft_strcpy(rounder, "0.");
	ft_memset((tmp + 2), '0', pric);
	tmp[pric + 2] = '5';
	tmp[pric + 3] = '\0';
	if (cur_res[r_nbr - 1] == '.')
		if ((cur_res[r_nbr - 2] - '0') % 2 != 0 || (cur_res[r_nbr] - '0') >= 5)
			ft_plus_float(cur_res, rounder, len_l);
		else
		{
			if ((cur_res[r_nbr - 1] - '0') % 2 != 0 || (cur_res[r_nbr] - '0') >= 5)
				ft_plus_float(cur_res, rounder, len_l);
		}
}

unsigned long	ft_make_mantissa(long double nbr)
{
	unsigned long	mantissa;
	unsigned char	memoryPointer;
	int				bits;
	int				byte;
	unsigned long	g;

	mantissa = 0;
	memoryPointer = 0;
	bits = 0;
	byte = -1;
	g = 1;
	while (byte++ < 8)
	{
		bits = 0;
		memoryPointer = *((unsigned char *)&nbr + byte);
		while (bits++ < 8)
		{
			if (memoryPointer & 1 && byte * 8 + bits <= 64)
				mantissa |= g;
			memoryPointer >>= 1;
			if (byte * 8 + bits <= 64)
				g <<= 1;
		}
	}
	return (mantissa);
}

short	ft_make_exponent(long double nbr)
{
	unsigned short	exponent;
	unsigned char	memoryPointer;
	short			*ptr;

	exponent = 0;
	memoryPointer = *((unsigned char *)&nbr + 9);
	exponent |= memoryPointer;
	exponent <<= 8;
	memoryPointer = *((unsigned char *)&nbr + 8);
	exponent |= memoryPointer;
	exponent = exponent - 16383;
	ptr = (short*)&exponent;
	return (*ptr);
}

char	*ft_add_infOrNan(int sign, long double arg_double, t_prinlist *lst)
{
	char	*res;

	if (!(res = ft_strnew(4)))
		exit(1);
	if ((arg_double != arg_double))
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

void	ft_parse_double(char **result, long double arg_double, t_prinlist *lst)
{
	char			*tmp_result;
	unsigned long	mantissa;
	unsigned char	memoryPointer;
	short			exponent;
	int				sign;

	memoryPointer = *((unsigned char *)&arg_double + 9);
	sign = (memoryPointer >> 7)  == 0 ? 1 : -1;
	if (sign < 0)
		arg_double = -arg_double;
	mantissa = ft_make_mantissa(arg_double);
	exponent = ft_make_exponent(arg_double);
	if ((lst->pricision == 0 || lst->pricision > 2000) && (lst->flag & ZERO_PRIC) != ZERO_PRIC)
		lst->pricision = 6;
	if (exponent == 16384)
		tmp_result = ft_add_infOrNan(sign, arg_double, lst);
	if (!(is_NanOrInf(tmp_result)))
		tmp_result = ft_add_double(mantissa, exponent, sign,  lst);
	ft_choice_options(result, tmp_result, lst);
}
