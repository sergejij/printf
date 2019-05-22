/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:52:47 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/22 13:13:10 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "./libft/libft.h"

void	ft_putnbr(int n)
{
	int size;
	int tmp_n;

	tmp_n = n;
	size = 1;
	if (n < 0)
		ft_putchar('-');
	while (tmp_n / 10 != 0)
	{
		size *= 10;
		tmp_n /= 10;
	}
	while (size > 0)
	{
		if (n < 0)
			ft_putchar((n / size * -1) + 48);
		else
			ft_putchar((n / size) + 48);
		n %= size;
		size /= 10;
	}
}

int		ft_lennum_base(int num, int base)
{
	int len;

	len = 0;
	if (num < 0 && base == 10)
		len++;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(int n, int base)
{
	int				len;
	int				counter;
	unsigned int	number;
	char			*result;
    char *a = "0123456789abcdef";

	len = ft_lennum_base(n, base);
	counter = 0;
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	if (n < 0 && base == 10)
	{
		result[counter] = '-';
		number = n * (-1);
		counter++;
	}
	else
		number = n;
	if (number == 0)
		result[0] = '0';
	while (number > 0)
	{
		result[len - 1] = a[number % base];
		number /= base;
		len--;
	}
	return (result);
}

char *do_if_d(int d, char *str)
{
    int len;
    char *s_num;
    int size;
    int i;
    
    i = 0;
    size = ft_discharge(d);
    len = ft_lennum(d);
    s_num = (char*)malloc(sizeof(char) * (len + 1));
    while (size > 0)
    {
        if (d < 0)
            s_num[i] = (d / size * -1) + 48;
        else
            s_num[i] = (d / size) + 48;
        d %= size;
        size /= 10;
        i++;
    }
    s_num[i] = '\0';
    str = ft_strjoin(str, s_num);
    return (str);
}

unsigned int	ft_discharge_u(unsigned int n)
{
	unsigned int	res;

	res = 1;
	while (n / 10)
	{
		res *= 10;
		n /= 10;
	}
	return (res);
}

int		ft_lennum_u(unsigned int num)
{
	int len;

	len = 0;

	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char    *do_if_u(unsigned u, char *str)
{
    int len;
    char *s_num;
    int size;
    int i;
    
    i = 0;
    size =  ft_discharge_u(u);
    len = ft_lennum_u(u);
    s_num = (char*)malloc(sizeof(char) * (len + 1));
    while (size > 0)
    {
        s_num[i] = (u / size) + 48;
        u %= size;
        size /= 10;
        i++;
    }
    s_num[i] = '\0';
    str = ft_strjoin(str, s_num);
    return (str);
}

char *do_if_X(int x, char *str)
{
    char *s_num;

    s_num = ft_itoa_base(x, 16);
    str = ft_strjoin(str, s_num);
    return (str);
}

char *do_if_O(int o, char *str)
{
    char *s_num;

    s_num = ft_itoa_base(o, 8);
    str = ft_strjoin(str, s_num);
    return (str);
}

int *ft_printf(char *apFormat, ...)
{
    va_list ap;         //указатель va_list | poit on next unnamed argument
    va_start(ap, apFormat);    // устанавливаем указатель
    char *p = apFormat;
    char *result;

    result = (char*)malloc(sizeof(char));    
    int ival = 0;
    double dval = 0;
    char *sval;
    char cval;
    int pval;
    unsigned int uval;
    char *flags;

    while (*(++p))
    {
        if (*p == '%' && *(p - 1) != '%')
            continue;
        if (*p == 'p')
        {
            pval = va_arg(ap, int);
            char *s = ft_itoa_base(pval, 16);
            if (ft_strlen(s) == 7)
                s = ft_strjoin("0x10" , s);
            else
                s = ft_strjoin("0x7fff" , s);
            printf("%s", s);
           // printf("%s", s);
            continue;
        }
        if (*p == 'u')
        {
             uval = va_arg(ap, unsigned int);
             result = do_if_u(uval, result);
             continue;   
        }
     if (*p == 'd' || *p == 'i')
        {
            ival = va_arg(ap, int);
            result = do_if_d(ival, result);
            continue;
        }
        else if (*p == 'x')
        {
            ival = va_arg(ap, int);
            result = do_if_X(ival, result);
            continue;
        }
        else if (*p == 'o')
        {
            ival = va_arg(ap, int);
            result = do_if_O(ival, result);
            continue;
        }
        else  if (*p == 'f')
        {
            dval = va_arg(ap, double);
            printf("%f", dval);
            continue;
        }
        else  if (*p == 'c')
        {
            cval = va_arg(ap, int); // int и он будет переводить его по ascii
            ft_strncat(result, &cval, 1);
            continue;
        }
        else  if (*p == 's')
        {
            sval = va_arg(ap, char*);
            ft_strncat(result, sval, ft_strlen(sval));
            continue;
        }
        if (*p == '#')
            ft_strncat(flags, '#', 1);
        else if (*p == '#')
            ft_strncat(flags, '#', 1);
        else if (*p == '#')
            ft_strncat(flags, '#', 1);
        else if (*p == '#')
            ft_strncat(flags, '#', 1);
        /*else
        {
            ft_strncat(result, p, 1);
            continue;
        }*/
    }
    ft_putstr(result);
    va_end(ap);
    return (0);
}

int main(void)
{
    int a = -4;
    char str[10] = "abcdefg";
   // unsigned int d1 = 4294967295;
   // char sym = 'G';
    
    //ft_printf("%x", 42);
   // printf("\n");
    printf("%p\n%p", &a, &str);
   // printf("\n%% %d", a);
    //printf("%s", y);
    //printf("\n%p", &a);
    return 0;
}