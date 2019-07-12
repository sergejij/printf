/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:02:53 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/12 13:56:20 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_change_type_hex(long long int *arg, t_prinlist *lst) {
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

void    ft_pricision_hex(char *result, t_prinlist *lst, size_t len, char *str)
{
    char *tmp;
    char *tmp1;


    tmp = (char*)malloc(sizeof(char) * (lst->pricision - len));
    tmp1 = result;
    if (lst->width > lst->pricision + len)
    {
        ft_memset(tmp, ' ', lst->width - lst->pricision);
        if ((lst->flag & MINUS) == MINUS)
        {
            ft_strcpy(result, "0");
            ft_strcat(result, str);
            ft_strcat(result, tmp);
            //result = ft_strjoin(ft_strjoin("0", str), tmp);
        }
        else
        {
            ft_memset(tmp + lst->width - lst->pricision, '0', lst->pricision - len);

            ft_strcpy(result, tmp);
            ft_strcat(result, str);
        }
    }
    else
    {
        ft_memset(tmp, '0', lst->pricision - len);
        ft_strcpy(result, tmp);
        ft_strcat(result, str);
    }
}

size_t  ft_lennum_uhex(unsigned long long int num)
{
    size_t len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

size_t  ft_lennum_hex(long long int num)
{
    size_t len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

char		*ft_itoa_hex(long long int n, char sym)
{
	int				len;
	int				counter;
	unsigned long long int	number;
	char			*result;
    char *a;

    if (sym == 'x')
        a = "0123456789abcdef";
    else 
        a = "0123456789ABCDEF";
	len = n < 0 ? 8 : ft_lennum_hex(n);
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
		result[len - 1] = a[number % 16];
		number /= 16;
		len--;
	}
	return (result);
}

char		*ft_itoa_uhex(unsigned long long int n, char sym)
{
	int				len;
	int				counter;
	unsigned long long int	number;
	char			*result;
    char *a;

    if (sym == 'x')
        a = "0123456789abcdef";
    else
        a = "0123456789ABCDEF";
	len = ft_lennum_uhex(n);
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
		result[len - 1] = a[number % 16];
		number /= 16;
		len--;
	}
	return (result);
}

void ft_add_uhex_str(char **result, unsigned long long arg, t_prinlist *lst, char sym)
{
    // не заполняет нулями, не работает с отрицательными числами, не работает с #
    //size_t len;
    char *str;
    char *tmp;
    size_t len;
    char *cpy_res;

    //if(lst->modifier)
     //   ft_change_type_hex(&arg, lst);
    cpy_res = (char*)malloc(sizeof(char) * 100);
    len = ft_lennum_uhex(arg);
    str = ft_itoa_uhex(arg, sym);
    tmp = str;
    if(*str == '0' && len == 1 && lst->pricision == 0)
    {
        if (lst->width > 0 && (lst->flag & ZERO_PRIC) == ZERO_PRIC)
        {
            memset(*result, ' ', lst->width);
            return ;
        }
        else if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
        {
            *str = '\0';
            len = 0;
            if (!lst->width)
                return ;
        }
        else if (!(lst->width))
        {
            *result = "0";
            return ;
        }
    }
    ft_strcpy(cpy_res, str);
    if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) != ZERO && *str != '0')
    {
        if(lst->pricision > len)
            ft_pricision_hex(cpy_res, lst, len, str);
        cpy_res = ft_strjoin(sym == 'x' ? "0x" : "0X", cpy_res);
    }
    ft_transform_int_result(result, cpy_res, lst); // ПОМЕНЯТЬ STR ЭТО ПРОСТО ЗАГЛУШКА ЧТОБЫ СКОМПИЛИЛОСЬ
    if((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO && *str != '0')
    {
        if(lst->width > len)
            *result = ft_strjoin(sym == 'x' ? "0x" : "0X", (*result) + 2);
        else
            *result = ft_strjoin(sym == 'x' ? "0x" : "0X", *result);
    }




    //if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO)
    //    *result = ft_strjoin(sym == 'x' ? "0x" : "0X", *result);

    // тернарники огонь
    /*if ((lst->flag & ZERO) == ZERO  && (lst->flag & MINUS) != MINUS)
        ft_hex_zero(&str, lst, len);
    if ((lst->flag & HASH) == HASH)
        str = ft_strjoin(sym == 'x' ? "0x" : "0X", str); // тернарники огонь
    if (lst->pricision < len)
        *result = ft_add_string(*result, str, lst, 16);
    else
        ft_pricision_hex(result, lst, len, str);*/

}

void ft_add_hex_str(char **result, long long int arg, t_prinlist *lst, char sym)
{
    // не заполняет нулями, не работает с отрицательными числами, не работает с #
    //size_t len;
    char *str;
    char *tmp;
    size_t len;
    char *cpy_res;

    cpy_res = (char*)malloc(sizeof(char) * 100);
    if(lst->modifier)
        ft_change_type_hex(&arg, lst);
    len = arg < 0 ? 8 : ft_lennum_hex(arg);
    str = ft_itoa_hex(arg, sym);
    tmp = str;
    if(*str == '0' && len == 1 && lst->pricision == 0)
    {
        if (lst->width > 0 && (lst->flag & ZERO_PRIC) == ZERO_PRIC)
        {
            memset(*result, ' ', lst->width);
            return ;
        }
        else if ((lst->flag & ZERO_PRIC) == ZERO_PRIC)
        {
            *str = '\0';
            len = 0;
            if (!lst->width)
                return ;  
        }
        else if (!(lst->width))
        {   
            *result = "0";
            return ;
        }
    }
    ft_strcpy(cpy_res, str);
    if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) != ZERO && *str != '0')
    {
        if(lst->pricision > len)
            ft_pricision_hex(cpy_res, lst, len, str);
        if(lst->width > len && lst->pricision > len && (lst->flag & MINUS) != MINUS)
        {
            ft_strdel(&tmp);
            tmp = ft_strsub(cpy_res, lst->width - lst->pricision, lst->pricision);
            cpy_res[lst->width - lst->pricision - 2] = '\0';
            ft_strcat(cpy_res, sym == 'x' ? "0x" : "0X");
            ft_strcat(cpy_res, tmp);
        }
        else
            cpy_res = ft_strjoin(sym == 'x' ? "0x" : "0X", cpy_res);
    }
    ft_transform_int_result(result, cpy_res, lst); // ПОМЕНЯТЬ STR ЭТО ПРОСТО ЗАГЛУШКА ЧТОБЫ СКОМПИЛИЛОСЬ
    if((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO && *str != '0')
    {
        if(lst->width > len)
            *result = ft_strjoin(sym == 'x' ? "0x" : "0X", (*result) + 2);
        else
            *result = ft_strjoin(sym == 'x' ? "0x" : "0X", *result);
    }




    //if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO)
    //    *result = ft_strjoin(sym == 'x' ? "0x" : "0X", *result);
    
    // тернарники огонь
    /*if ((lst->flag & ZERO) == ZERO  && (lst->flag & MINUS) != MINUS)
        ft_hex_zero(&str, lst, len);
    if ((lst->flag & HASH) == HASH)
        str = ft_strjoin(sym == 'x' ? "0x" : "0X", str); // тернарники огонь
    if (lst->pricision < len)
        *result = ft_add_string(*result, str, lst, 16);
    else
        ft_pricision_hex(result, lst, len, str);*/

}
