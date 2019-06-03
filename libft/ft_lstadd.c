/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:03:47 by ubartemi          #+#    #+#             */
/*   Updated: 2019/06/03 13:56:51 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *tmp;

	tmp = *alst;
	if (!tmp)
		tmp = new;
	else
	{
		tmp = new;
		tmp->next = *alst;
	}
	*alst = tmp;
}
