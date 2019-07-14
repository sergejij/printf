/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:01:40 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/14 15:58:43 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_change_type_oct_h(unsigned int *arg, t_prinlist *lst)
{
	unsigned short				new_arg_h;
	unsigned char				new_arg_hh;

	new_arg_h = 0;
	new_arg_hh = 0;
	if ((lst->modifier & H) == H)
	{
		new_arg_h = *arg;
		*arg = new_arg_h;
	}
	else if ((lst->modifier & HH) == HH)
	{
		new_arg_hh = *arg;
		*arg = new_arg_hh;
	}
}

void	ft_change_type_oct(unsigned int *arg, t_prinlist *lst)
{
	unsigned long				new_arg_l;
	unsigned long long			new_arg_ll;

	new_arg_l = 0;
	new_arg_ll = 0;
	if ((lst->modifier & L_ONE) == L_ONE)
	{
		new_arg_l = *arg;
		*arg = new_arg_l;
	}
	else if ((lst->modifier & LL) == LL)
	{
		new_arg_ll = *arg;
		*arg = new_arg_ll;
	}
	else
		ft_change_type_oct_h(arg, lst);
}

size_t	ft_lennum_octal(long long num)
{
	size_t						len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 8;
	}
	return (len);
}

size_t	ft_lennum_octal_u(unsigned long long num)
{
	size_t						len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 8;
	}
	return (len);
}

char		*ft_itoa_octal(unsigned long long n)
{
	long long				len;
	long long				counter;
	unsigned long long		number;
	char					*result;
	char					*a;

	a = "0123456789abcdef";
	len = ft_lennum_octal_u(n);
	counter = 0;
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	number = n;
	if (number == 0)
		result[0] = '0';
	while (number > 0)
	{
		result[len - 1] = a[number % 8];
		number /= 8;
		len--;
	}
	return (result);
}

int		ft_if_zero_o(char **result, char *str, t_prinlist *lst)
{
	if (*str == '0' && lst->len == 1 && lst->pricision == 0)
	{
		if (lst->width > 0 && (lst->flag & ZERO_PRIC) == ZERO_PRIC && ((lst->flag
			& MINUS) != MINUS) && ((lst->flag & ZERO) != ZERO) && !(lst->width))
		{
			memset(*result, ' ', lst->width);
			return (0);
		}
		else if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
		{
			if (((lst->flag & HASH) != HASH))
			{
				*str = '\0';
				if (!lst->width)
					return (0);
			}
		}
		else if (lst->width < 2)
		{
			*result = "0";
			return (0);
		}
	}
	return (1);
}

/*  не используется
	void ft_octal_zero(char **str, t_prinlist *lst, size_t len)
	{
	char *tmp;
	char *tmp2;

	tmp = (char*)malloc(sizeof(char) * (lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0)));
	tmp2 = *str;
	if (lst->width > len && (lst->flag & ZERO) == ZERO)
	{
	if ((lst->flag & MINUS) == MINUS)
	{
	ft_strcpy(tmp, *str);
	ft_memset(tmp + len, ' ', lst->width - len - ((lst->flag & HASH) == HASH ? 2 : 0));
	}
	else
	{
	if (tmp2[0] == '0')
	{
	ft_memset(tmp, '0', lst->width - len);
	ft_strcpy(tmp + (lst->width - len), *str);
	}
	else
	{
	ft_memset(tmp, '0', lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0));
	ft_strcpy(tmp + lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0), *str);
	}
	}
 *str = tmp;
 }
 else if (lst->width > len)
 {
 ft_memset(tmp, ' ', lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0));
 ft_strcpy(*str + len, tmp);
 }
 ft_strdel(&tmp2);
 } */

// без знаковый о

void	ft_add_octal_u_2(char **result, char *str, t_prinlist *lst)
{
	char						*tmp;
	char						*cpy_res;
	size_t						len_all;

	cpy_res = (char*)malloc(sizeof(char) * 100);
	tmp = str;
	ft_strcpy(cpy_res, tmp);
	if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) != ZERO && *str != '0')
	{
		if (lst->pricision > lst->len)
			ft_pricision_hex(cpy_res, lst, lst->len, str);
		len_all = ft_strlen(cpy_res);
		if (lst->pricision < len_all)
			cpy_res = ft_strjoin("0", cpy_res);
	}
	ft_transform_int_result(result, cpy_res, lst);
	if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO
			&& *str != '0' && lst->width < lst->len)
		*result = ft_strjoin("0", *result);
}

void	ft_add_octal_u(char **result, unsigned long long arg, t_prinlist *lst)
{
	char						*str;

	lst->len = ft_lennum_octal_u(arg);
	str = ft_itoa_octal(arg);
	if ((ft_if_zero_o(result, str, lst)) == 0)
		return ;
	ft_add_octal_u_2(result, str, lst);
}

// обычный о

void	ft_add_octal_2(char **result, char *str, t_prinlist *lst)
{
    char *cpy_res;
    size_t len_all;

    cpy_res = ft_strnew(100);
    if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) != ZERO && *str != '0') {
        if (lst->pricision > lst->len)
            ft_pricision_hex(*result, lst, lst->len, str);
        len_all = ft_strlen(str);
        if (lst->pricision < len_all)
            ft_strcpy(cpy_res, "0");
    }
    ft_strcat(cpy_res, str);
    ft_transform_int_result(result, cpy_res, lst);
    if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO
        && *str != '0' && lst->width < lst->len) {
        ft_strcpy(cpy_res, "0");
        cpy_res[1] = '\0';
        ft_strcat(cpy_res, *result);
        ft_strcpy(*result, cpy_res);
    }
    ft_strdel(&cpy_res);
}

void	ft_add_octal(char **result, unsigned int arg, t_prinlist *lst)
{
	char						*str;

	if (lst->modifier)
		ft_change_type_oct(&arg, lst);
	lst->len = ft_lennum_octal(arg);
	str = ft_itoa_octal(arg);
	if ((ft_if_zero_o(result, str, lst)) != 0)
	    ft_add_octal_2(result, str, lst);
	ft_strdel(&str);
}
