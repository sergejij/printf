/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:58:18 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/28 13:55:31 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t  ft_lennum_hex(int num)
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
/*
unsigned int reverse(unsigned int x){
    unsigned i,temp,bit,reversed;
	reversed =0;

// loop for each bit	
	for(i=0; i<32; i++){
		temp =0;
		bit =0;
		// shift to the least sig bit
		temp = x >> (31-i);
		// bit mask to clear the other bits
		bit = temp & 1;
		// move the bit to the reversed spot
		bit = bit << i;
		// add together to get reversed bits
		reversed += bit;
	}

	return reversed;

}
int     ft_reverse_bits(int n)
{
    unsigned int res;
    int i;

    i = 8;
    while (i > 0)
    {
        n ^= i;
        i--; 
    }
    return (n);
}*/

char		*ft_itoa_hex(int n, char sym)
{
	int				len;
	int				counter;
	unsigned int	number;
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

/*void    ft_minus_hex(char **result, int arg, t_prinlist *lst, size_t len)
{
    if (lst->pricision > len)
        ft_pricision_minus(result, arg, lst, len);
    else
    {
        if (((lst->flag & PLUS) == PLUS))
        {
            ft_strcpy(*result, "+");
            ft_strcpy(*result + 1, ft_itoa(arg));
            ft_memset(*result + len + 1, ' ', lst->width - len);
            return ;
        }
        ft_strcpy(*result, ft_itoa(arg));
        ft_memset(*result + len, ' ', lst->width - len);
    }
}*/

void ft_hex_zero(char **str, t_prinlist *lst, size_t len)
{
    char *tmp;
    
    tmp = (char*)malloc(sizeof(char) * (lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0)));
    if (lst->width > len)
    {
        ft_memset(tmp, '0', lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0));
        ft_strcpy(tmp + lst->width - len - (((lst->flag & HASH) == HASH) ? 2 : 0), *str);
        *str = tmp;
        //*str = ft_strjoin(tmp2, *str);
        //ft_strdel(&tmp);
    }
}

void    ft_pricision_hex(char **result, t_prinlist *lst, size_t len, char *str)
{
    char *tmp;

    tmp = (char*)malloc(sizeof(char) + (lst->pricision - len));
    if (lst->width > len && lst->width > lst->pricision)
        ft_memset(*result, ' ', lst->width - lst->pricision);
    else if (lst->width < lst->pricision)
    {
        ft_memset(tmp, '0', lst->pricision - len);
        *result = ft_strjoin(tmp, str);
    }
    //ft_memset(*result + (lst->width - lst->pricision), '0', lst->pricision  - len);
}

void ft_add_hex(char **result, int arg, t_prinlist *lst, char sym)
{
    // не заполняет нулями, не работает с отрицательными числами, не работает с #
    //size_t len;
    char *str;
    char *tmp;
    size_t len;
    
    if (arg == 0)
    {
        *result = "0";
        return ;
    }
    len = arg < 0 ? 8 : ft_lennum_hex(arg);
    str = ft_itoa_hex(arg, sym);
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
    if ((lst->flag & ZERO) == ZERO  && (lst->flag & MINUS) != MINUS)
        ft_hex_zero(&str, lst, len);
        //str = ft_strjoin(sym == 'x' ? "0x" : "0X", str);
    if ((lst->flag & HASH) == HASH)
        str = ft_strjoin(sym == 'x' ? "0x" : "0X", str); // тернарники огонь
    if (lst->pricision < len)
        *result = ft_add_string(*result, str, lst, 16);
    else
        ft_pricision_hex(result, lst, len, str);
        //printf("%s", str);
}