/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:00:58 by aestella          #+#    #+#             */
/*   Updated: 2019/07/14 14:49:27 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *buff;

	buff = s1;
	while (*buff)
		buff++;
	while (*s2 && n > 0)
	{
		*buff = *(char *)s2;
		buff++;
		s2++;
		n--;
	}
	*buff = '\0';
	return (s1);
}
