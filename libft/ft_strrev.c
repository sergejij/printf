/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:43:33 by aestella          #+#    #+#             */
/*   Updated: 2019/07/05 16:51:37 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
    char	buff;
    size_t	len;
    size_t	i;
    size_t  len_inf;

    if (!*s)
        return (NULL);
    len_inf = ft_strlen(s);
    len = len_inf - 1;
    i = 0;
    while (i < len)
    {
        buff = s[i];
        s[i] = s[len];
        s[len] = buff;
        i++;
        len--;
    }
    s[len_inf] = '\0';
    return (s);
}