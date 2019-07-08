/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:43:36 by aestella          #+#    #+#             */
/*   Updated: 2019/07/05 16:51:37 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *new_dst;
	unsigned char *new_src;

	if (dst == src)
		return (dst);
	new_dst = (unsigned char*)dst;
	new_src = (unsigned char*)src;
	while (n > 0)
	{
		*new_dst = *new_src;
		new_dst++;
		new_src++;
		n--;
	}
	*new_dst = '\0';
	return (dst);
}
