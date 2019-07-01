/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:30:57 by aestella          #+#    #+#             */
/*   Updated: 2019/07/01 17:33:14 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	class(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		n = (n * -1) * 10;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return ((size_t)i);
}

char			*ft_itoa(int n)
{
	char	*res;
	char	buf;
	size_t	len;

	len = class(n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_strcpy(res, "-2147483648");
			return (res);
		}
		res[0] = '-';
		n = n * -1;
	}
	while (len > 0 && res && res[len - 1] != '-')
	{
		buf = (n % 10) + '0';
		res[len - 1] = buf;
		n = n / 10;
		len--;
	}
	return (res);
}
