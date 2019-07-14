/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:22:05 by aestella          #+#    #+#             */
/*   Updated: 2019/07/14 14:49:27 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char new_c;
	unsigned char *new_b;

	new_c = (unsigned char)c;
	new_b = (unsigned char *)b;
	while (len > 0)
	{
		*new_b = new_c;
		new_b++;
		len--;
	}
	*new_b = '\0';
	return (b);
}
