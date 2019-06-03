/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:55:00 by ubartemi          #+#    #+#             */
/*   Updated: 2019/06/03 15:56:27 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	size_t			counter;
	unsigned char	*arr;

	if(!(destination) || !c || n <= 0)
        return (NULL);
	arr = (unsigned char*)destination;
	counter = 0;
	while (counter < n)
	{
		arr[counter] = c;
		counter++;
	}
    return (destination);
}
