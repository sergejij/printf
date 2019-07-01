/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:44:18 by aestella          #+#    #+#             */
/*   Updated: 2019/07/01 17:33:14 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (len != 0)
	{
		while ((*s != '\0') && (len > 0))
		{
			*d++ = *s++;
			len--;
		}
		while (len > 0)
		{
			*d++ = '\0';
			len--;
		}
	}
	return (dst);
}
