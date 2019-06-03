/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:14:34 by ubartemi          #+#    #+#             */
/*   Updated: 2019/06/03 13:56:51 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int counter;

	counter = 0;
	if (s && f)
	{
		while (s[counter] != '\0')
		{
			f(&s[counter]);
			counter++;
		}
	}
}
