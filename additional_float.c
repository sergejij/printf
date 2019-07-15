/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:39:28 by aestella          #+#    #+#             */
/*   Updated: 2019/07/15 15:42:51 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_make_even(char *cur_num, char *pow_two)
{
	size_t	i_cur_len;
	size_t	i_pow_len;
	char	*tmp;

	i_cur_len = 0;
	i_pow_len = 0;
	tmp = ft_strnew(ft_strlen(cur_num) + ft_strlen(pow_two));
	while (cur_num[i_cur_len] != '.')
		i_cur_len++;
	while (pow_two[i_pow_len] != '.')
		i_pow_len++;
	if (i_cur_len > i_pow_len)
	{
		ft_memset(tmp, '0', i_cur_len - i_pow_len);
		ft_strcat(tmp, pow_two);
		ft_strcpy(pow_two, tmp);
	}
	else if (i_pow_len > i_cur_len)
	{
		ft_memset(tmp, '0', i_pow_len - i_cur_len);
		ft_strcat(tmp, cur_num);
		ft_strcpy(cur_num, tmp);
	}
}

void	ft_handle_result_f(int len, int *int_res, char *result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (int_res[i] == 0)
		i++;
	while (len-- > i)
		result[j++] = int_res[len] + '0';
	result[j] = '\0';
}

void	ft_make_power(char *current_power)
{
	int		*res;
	char	*tmp;
	int		len;
	int		flag;

	len = ft_strlen(current_power);
	res = (int *)malloc(sizeof(int) * (len + 1));
	tmp = current_power;
	ft_strrev(current_power);
	len = 0;
	flag = 0;
	while (*tmp)
	{
		res[len] = (*tmp++ - '0') * 2 + flag;
		flag = 0;
		if (res[len] > 9)
		{
			flag = res[len] / 10;
			res[len] %= 10;
		}
		len++;
	}
	if (flag)
		res[len++] = flag;
	ft_handle_result_f(len, res, current_power);
}

char	*ft_prop(int power)
{
	char	*res;
	char	*tmp;

	res = ft_strnew(311);
	tmp = NULL;
	if (power == 0)
		ft_strcpy(res, "1");
	else if (power > 0)
		ft_strcpy(res, "2");
	else if (power < 0)
	{
		ft_strcpy(res, "0000000000000000000000008271806125530276");
		tmp = ft_strdup("7487140869206996285356581211090087890625");
		ft_strcat(res, tmp);
	}
	return (res);
}

char	*ft_find_power(int power)
{
	char	*result;
	char	*tmp;

	tmp = NULL;
	result = NULL;
	result = ft_prop(power);
	if (power > 0)
	{
		while (power-- > 1)
			ft_make_power(result);
	}
	else if (power < 0)
	{
		while (power-- > -80)
			ft_make_power(result);
		tmp = result;
		result = ft_strjoin("0.", tmp);
	}
	return (result);
}
