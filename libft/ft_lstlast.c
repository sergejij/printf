/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:16:33 by aestella          #+#    #+#             */
/*   Updated: 2019/04/22 21:30:13 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *last_list, t_list *new)
{
	if (last_list && new)
	{
		new = last_list->next;
		return (new);
	}
	else
		return (NULL);
}
