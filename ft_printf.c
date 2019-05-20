/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:52:47 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/20 16:12:09 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/*#include <stdio.h>

int main(void)
{
    printf("%0d\n%d", 5);
    return (0);
}*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_putstr(char const *s)
{
	int counter;

	counter = 0;
	if (s)
	{
		while (s[counter] != '\0')
		{
			ft_putchar(s[counter]);
			counter++;
		}
	}
}

void	ft_putnbr_base(int n, int base, char reg)
{
    char *a;
    int size;
	int tmp_n;

    if (reg == 's')
        a = "0123456789abcdef";
    else
        a = "0123456789ABCDEF";
	tmp_n = n;
	size = 1;
	if (n < 0)
		ft_putchar('-');
	while (tmp_n / base != 0)
	{
		size *= base;
		tmp_n /= base;
	}
	while (size > 0)
	{
		if (n < 0)
			ft_putchar(a[(n / size * -1)]);
		else
			ft_putchar(a[(n / size)]);
		n %= size;
		size /= base;
	}
}


int ft_printf(char *apFormat, ...)
{
    va_list ap;         //указатель va_list | poit on next unnamed argument
    va_start(ap, apFormat);    // устанавливаем указатель
    char *p = apFormat;
    
    int ival = 0;
    double dval = 0;
    char *sval;
    char cval;
    while (*(++p))
    {
        if (*p == '%')
            continue;
        if (*p == 'd')
        {
            ival = va_arg(ap, int);
            ft_putnbr(ival);
            continue;
        }
        else if (*p == 'x')
        {
            ival = va_arg(ap, int);
            ft_putnbr_base(ival, 16, 's');
            continue;
        }
        else if (*p == 'X')
        {
            ival = va_arg(ap, int);
            ft_putnbr_base(ival, 16, 'b');
            continue;
        }
        else if (*p == 'o')
        {
            ival = va_arg(ap, int);
            ft_putnbr_base(ival, 8, 's');
            continue;
        }
        else  if (*p == 'f')
        {
            dval = va_arg(ap, double);
            printf("%f", dval);
            continue;
        }
        else  if (*p == 's')
        {
            sval = va_arg(ap, char*);
            ft_putstr(sval);
            continue;
        }
        else
        {
            ft_putchar(*p);
            continue;
        }
    }
    va_end(ap);
    return (0);
}
 
int main(void)
{
    int a = 4;
    double b = 4.222;
    char *str = "abcdefg";
    unsigned int d1 = 123;
    ft_printf("%X - %d\n\n", d1, a);
    printf("%X - %d", d1, a);
    return 0;
}