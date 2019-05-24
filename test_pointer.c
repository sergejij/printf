/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:24:43 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/24 19:56:31 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lennum_base(unsigned long num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char		*ft_itoa_base_ul(unsigned long n)
{
	int				len;
	int				counter;
	char			*result;
    char            *a;
    
    a = "0123456789abcdef";
	len = ft_lennum_base(n);
	counter = 0;
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n > 0)
	{
		result[len - 1] = a[n % 16];
		n /= 16;
		len--;
	}
	return (result);
}

void ft_add_pointer(char **result, unsigned long arg, t_prinlist *lst)
{
    char *tmp;
    size_t len;
    char *new_result = ft_itoa_base_ul(arg);

    tmp = new_result;
    new_result = ft_strjoin("0x" , new_result);
    ft_strdel(&tmp);
    len = ft_strlen(new_result);
    if (lst->width > len && ((lst->flag & 4) == 4))// сдвигаем влево
    {
        *result = ft_strjoin(*result, new_result);
        tmp = *result + len;
        ft_memset(tmp, '.', lst->width - len);
    }
    else if (lst->width && lst->width > len) // сдвигаем вправо
    {
        ft_memset(*result, '.', lst->width - len);
        tmp = *result + (lst->width - len);
        tmp = ft_strcpy(tmp, new_result);
        //ft_strdel(&new_result);
    }
    else
    {
        //ft_strdel(result);
        *result = new_result; 
    }
}