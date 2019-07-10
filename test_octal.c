/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:01:40 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/09 20:12:35 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_change_type_oct(unsigned int *arg, t_prinlist *lst) {
    unsigned short new_arg_h = 0;
    unsigned char new_arg_hh = 0;
    unsigned long new_arg_l = 0;
    unsigned long long new_arg_ll = 0;

    if((lst->modifier & H) == H)
    {
        new_arg_h = *arg;
        *arg = new_arg_h;
    }
    else if((lst->modifier & HH) == HH)
    {
        new_arg_hh = *arg;
        *arg = new_arg_hh;
    }
    else if((lst->modifier & L_ONE) == L_ONE)
    {
        new_arg_l = *arg;
        *arg = new_arg_l;
    }
    else if((lst->modifier & LL) == LL)
    {
        new_arg_ll = *arg;
        *arg = new_arg_ll;
    }
}

size_t  ft_lennum_octal(long long num)
{
    size_t len;

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

size_t  ft_lennum_octal_u(unsigned long long num)
{
    size_t len;

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
	unsigned long long	    number;
	char			        *result;
    char                    *a;

    a = "0123456789abcdef";;
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
}

void ft_add_octal_u(char **result, unsigned long long arg, t_prinlist *lst)
{
    // не заполняет нулями, не работает с отрицательными числами, не работает с #
    //size_t len;
    char *str;
    char *tmp;
    size_t len;
    size_t len_all;

    /*if (arg == 0)
    {
        if ((lst->flag & ZERO_PRIC) == ZERO_PRIC && lst->width == 0)
            return ;
        else
        {
            ft_memset(*result, ' ', lst->width);
            return ;
        }
    }*/
    /*if(lst->modifier)
        ft_change_type_oct(&arg, lst);*/
    len = ft_lennum_octal_u(arg);
    str = ft_itoa_octal(arg);
    tmp = str;
    //len = ft_lennum_hex(arg);
    /*if ((lst->flag & HASH) == HASH)
    {
        tmp = str;
        if (arg < 0)
            str = ft_strjoin("0xffff", str);
        else
        str = ft_strjoin("0x", str);
        ft_strdel(&tmp);
    }*/ // такой кастыль не подходит
  /*if(*str == '0' && len == 1)
    {
        if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
        {
            *str = '\0';
            len = 0;
        }
    }*/
    if(*str == '0' && len == 1 && lst->pricision == 0)
    {
        if (lst->width > 0 && (lst->flag & ZERO_PRIC) == ZERO_PRIC
        && !((lst->flag & MINUS) == MINUS) && !((lst->flag & ZERO) == ZERO) && !(lst->width))
        {
            memset(*result, ' ', lst->width);
            return ;
        }
        else if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
        {
            if (!((lst->flag & HASH) == HASH))
            {
                *str = '\0';
                if (!lst->width)
                    return ;
            }
        }
        else if (lst->width < 2)
        {
            *result = "0";
            return ;
        }
    }
    ft_strcpy(*result, tmp);

    if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) != ZERO && *str != '0')
    {
        if(lst->pricision > len)
            ft_pricision_hex(result, lst, len, str);
        len_all = ft_strlen(*result);
        if (lst->pricision < len_all)
            *result = ft_strjoin("0", *result);

    }
    ft_transform_int_result(result, str, lst); // ПОМЕНЯТЬ STR ЭТО ПРОСТО ЗАГЛУШКА ЧТОБЫ СКОМПИЛИЛОСЬ
    if((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO && *str != '0' && lst->width < len)
        *result = ft_strjoin("0", *result);



   /* if ((lst->flag & ZERO) == ZERO)
        ft_octal_zero(&str, lst, len);
    if ((lst->flag & HASH) == HASH && !(*str == '0' && len == 1))
        str = ft_strjoin("0", str); // тернарники огонь
    if (lst->pricision < len)
        ft_transform_int_result(result, lst);
    else
        ft_transform_int_result(result, lst);*/
        //printf("%s", str);
}

void ft_add_octal(char **result, unsigned int arg, t_prinlist *lst)
{
    // не заполняет нулями, не работает с отрицательными числами, не работает с #
    //size_t len;
    char *str;
    char *tmp;
    size_t len;
    size_t len_all;
    
    /*if (arg == 0)
    {
        if ((lst->flag & ZERO_PRIC) == ZERO_PRIC && lst->width == 0)
            return ;
        else
        {
            ft_memset(*result, ' ', lst->width);
            return ;
        }
    }*/
    if(lst->modifier)
        ft_change_type_oct(&arg, lst);
    len = ft_lennum_octal(arg);
    str = ft_itoa_octal(arg);
    tmp = str;
    //len = ft_lennum_hex(arg);
    /*if ((lst->flag & HASH) == HASH)
    {
        tmp = str;
        if (arg < 0)
            str = ft_strjoin("0xffff", str);
        else
        str = ft_strjoin("0x", str);
        ft_strdel(&tmp);
    }*/ // такой кастыль не подходит
  /*if(*str == '0' && len == 1)
    {
        if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
        {
            *str = '\0';
            len = 0;
        }
    }*/
    if(*str == '0' && len == 1 && lst->pricision == 0)
    {
        if (lst->width > 0 && (lst->flag & ZERO_PRIC) == ZERO_PRIC
        && !((lst->flag & MINUS) == MINUS) && !((lst->flag & ZERO) == ZERO) && !(lst->width))
        {
            memset(*result, ' ', lst->width);
            return ;
        }
        else if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
        {
            if (!((lst->flag & HASH) == HASH))
            {
                *str = '\0';
                if (!lst->width)
                    return ;
            }
        }
        else if (lst->width < 2)
        {
            *result = "0";
            return ;
        }
    }
    ft_strcpy(*result, tmp);

    if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) != ZERO && *str != '0')
    {
        if(lst->pricision > len)
            ft_pricision_hex(result, lst, len, str);
        len_all = ft_strlen(*result);
        if (lst->pricision < len_all)
            *result = ft_strjoin("0", *result);

    }
    ft_transform_int_result(result, str, lst); // ПОМЕНЯТЬ STR ЭТО ПРОСТО ЗАГЛУШКА ЧТОБЫ СКОМПИЛИЛОСЬ
    if((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO && *str != '0' && lst->width < len)
        *result = ft_strjoin("0", *result);
    
   
   
   /* if ((lst->flag & ZERO) == ZERO)
        ft_octal_zero(&str, lst, len);
    if ((lst->flag & HASH) == HASH && !(*str == '0' && len == 1))
        str = ft_strjoin("0", str); // тернарники огонь
    if (lst->pricision < len)
        ft_transform_int_result(result, lst);
    else
        ft_transform_int_result(result, lst);*/
        //printf("%s", str);
}