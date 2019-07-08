/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:30:36 by aestella          #+#    #+#             */
/*   Updated: 2019/07/05 16:51:37 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	int		i;
	t_list	*temp;

	if (!begin_list)
		return (0);
	i = 0;
	temp = begin_list;
	while (temp != 0)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
