/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:46:42 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/24 19:40:02 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int counter;

	counter = 0;
	if (s)
	{
		while (s[counter] != '\0')
		{
			ft_putchar(s[counter]);
			counter++;
		}
	}
}
