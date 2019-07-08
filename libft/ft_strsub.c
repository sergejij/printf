/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:03:10 by aestella          #+#    #+#             */
/*   Updated: 2019/07/05 16:51:37 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i;

	i = 0;
	new_string = NULL;
	if (!s)
		return (NULL);
	if (!(new_string = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memset(new_string, '1', len);
	while (i < len && s[start])
	{
		new_string[i] = s[start];
		i++;
		start++;
	}
	new_string[i] = '\0';
	return (new_string);
}

