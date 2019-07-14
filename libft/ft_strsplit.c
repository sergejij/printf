/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:45:38 by aestella          #+#    #+#             */
/*   Updated: 2019/07/14 14:49:27 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int	w;
	int	i;

	w = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

static int		word_size(const char *s, char c)
{
	int i;

	i = 0;
	while (*s == c && *s != '\0')
		s++;
	while (*s != c && *s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

static char		*word_allocation(char **arr, char *word, int size)
{
	int i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (!word)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
		return (NULL);
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		w_count;
	int		i;
	int		j;

	j = 0;
	if (!s || !c)
		return (NULL);
	w_count = word_count(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (w_count + 1))))
		return (NULL);
	while (j < w_count)
	{
		i = 0;
		if (!(res[j] = word_allocation(res, res[j], word_size(s, c))))
			return (NULL);
		while (*s == c && s != '\0')
			s++;
		while (*s != c && *s)
			res[j][i++] = *s++;
		res[j][i] = '\0';
		j++;
	}
	res[j] = 0;
	return (res);
}
