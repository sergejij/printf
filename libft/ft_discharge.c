/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discharge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:16:11 by ubartemi          #+#    #+#             */
/*   Updated: 2019/06/03 13:56:51 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_discharge(int n)
{
	long int	res;

	res = 1;
	while (n / 10)
	{
		res *= 10;
		n /= 10;
	}
	return (res);
}
