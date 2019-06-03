/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:48:03 by ubartemi          #+#    #+#             */
/*   Updated: 2019/06/03 13:56:51 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *destination, const char *source)
{
	int counter;

	counter = 0;
	while (source[counter] != '\0')
	{
		destination[counter] = source[counter];
		counter++;
	}
	destination[counter] = '\0';
	return (destination);
}
