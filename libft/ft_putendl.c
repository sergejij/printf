/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:23:48 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/29 16:52:00 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
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
		ft_putchar('\n');
	}
}
