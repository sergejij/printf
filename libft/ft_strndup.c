/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:39:29 by aestella          #+#    #+#             */
/*   Updated: 2019/06/10 14:59:17 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	int		i;
	size_t	len;
	char	*new;

	if (!src || !(n + 1))
		return (NULL);
	i = 0;
	len = ft_strlen(src);
	if (len < n)
		n = len;
	new = (char *)malloc((n + 1) * sizeof(char));
	if (new == NULL)
		return (0);
	i = 0;
	while (src[i] && n > 0)
	{
		new[i] = src[i];
		i++;
		n--;
	}
	new[i] = '\0';
	return (new);
}
