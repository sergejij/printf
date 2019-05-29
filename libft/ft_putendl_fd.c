/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:23:23 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/29 16:52:00 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		counter;

	counter = 0;
	if (s)
	{
		while (s[counter] != '\0')
		{
			ft_putchar_fd(s[counter], fd);
			counter++;
		}
		ft_putchar_fd('\n', fd);
	}
}
