/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:20:57 by ubartemi          #+#    #+#             */
/*   Updated: 2019/06/03 17:43:31 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"

int main()
{
    int i = 42;
    char *tmp;
    char *s = (char*)malloc(sizeof(4));
    tmp = s;
    s = "abc";
    //float g = 123.223;
   // int *a = &i;
    long long a = 1000000000000000000;
    //printf("\n%d", ft_printf("test %s", "huest"));
  /*  printf("\n%d\n", ft_printf("%.2x", i));
    printf("\n%d\n", printf("%.2x", i));

    printf("___________________\n");*/

   // printf("___________________\n");

   // ft_printf("%-+10.5d\n", 4242);
   // printf("%-+10.5d\n", 4242);
/*
   printf("___________________\n");
   ft_printf("%f|%f|%f\n", 1.e18, 1.e57, 1.e201);
    printf("%f|%f|%f\n", 1.e18, 1.e57, 1.e201);
    printf("___________________\n");
*/
char str = 5;
    ft_printf("%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\n", 0, 0, 0, 0, 0, 0, 0);
    printf("%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\n", 0, 0, 0, 0, 0, 0, 0);
  /*  printf("~%d\n", ft_printf("%.f|%.f|%.f|%.f|%.f\n", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52));
    printf("~%d\n", printf("%.f|%.f|%.f|%.f|%.f\n", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52));
    printf("___________________\n");

*/
    /*ft_printf("%5d\n", 42);
    printf("%5d\n", 42);
    printf("___________________\n");



    ft_printf("%05d\n", -42);
    printf("%05d\n", -42);
    printf("___________________\n");

    ft_printf("%-5d\n", -42);
    printf("%-5d\n", -42);
    printf("___________________\n");

    ft_printf("%-05d\n", -42);
    printf("%-05d\n", -42);
    printf("___________________\n");*/

    free(tmp);
    return  0;
}