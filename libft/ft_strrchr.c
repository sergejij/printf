/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:27:46 by aestella          #+#    #+#             */
/*   Updated: 2019/07/05 16:51:37 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (s[i])
		i++;
	if (c == '\0')
		return ((char *)&s[i]);
	i--;
	while (i >= 0)
	{
		if (s[i] == c)
		{
			flag = 1;
			break ;
		}
		i--;
	}
	if (flag == 1)
		return ((char *)&s[i]);
	else
		return (NULL);
}
