/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:33:35 by aestella          #+#    #+#             */
/*   Updated: 2019/06/10 14:59:17 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long int	res;

	i = 0;
	res = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] > '\0')
	{
		if (!(ft_isdigit(str[i])))
			break ;
		if (res * 10 / 10 != res && neg == 1)
			return (-1);
		else if (res * 10 / 10 != res && neg == -1)
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}
