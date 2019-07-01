/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:47:42 by aestella          #+#    #+#             */
/*   Updated: 2019/06/10 14:59:17 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int t)
{
	int flag;

	flag = 0;
	while (*s != '\0')
	{
		if (*s == t)
		{
			flag = 1;
			break ;
		}
		s++;
	}
	if (t == '\0')
		return ((char *)s++);
	if (flag == 1)
		return ((char *)s);
	else
		return (NULL);
}
