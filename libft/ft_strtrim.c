/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:57:22 by aestella          #+#    #+#             */
/*   Updated: 2019/06/10 14:59:17 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*new_str;
	unsigned int	b;
	size_t			end;

	if (!s)
		return (NULL);
	b = 0;
	end = ft_strlen(s);
	while (s[b] == ' ' || s[b] == ',' || s[b] == '\n' || s[b] == '\t')
		b++;
	if (s[b] == '\0')
	{
		new_str = ft_strnew(0);
		return (new_str);
	}
	while (s[end] == ' ' || s[end] == ',' || s[end] == '\n'
			|| s[end] == '\t' || s[end] == '\0')
		end--;
	new_str = ft_strnew(end - b + 1);
	if (!new_str)
		return (NULL);
	new_str = ft_strsub(s, b, end - b + 1);
	return (new_str);
}
