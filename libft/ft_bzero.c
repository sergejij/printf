/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:22:05 by aestella          #+#    #+#             */
/*   Updated: 2019/06/10 14:59:17 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char c;
	unsigned char *new_s;

	c = '\0';
	new_s = (unsigned char *)s;
	while (n > 0)
	{
		*new_s = c;
		new_s++;
		n--;
	}
}
