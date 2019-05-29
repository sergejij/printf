/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:20:57 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/29 17:59:38 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    int i = 4242;
    char *tmp;
    char *s = (char*)malloc(sizeof(4));
    tmp = s;
    s = "abc";
    //float g = 123.223;
   // int *a = &i;
    long long a = -10;
    //printf("\n%d", ft_printf("test %s", "huest"));
  /*  printf("\n%d\n", ft_printf("%.2x", i));
    printf("\n%d\n", printf("%.2x", i));

    printf("___________________\n");*/

   // printf("___________________\n");

   // ft_printf("%-+10.5d\n", 4242);
   // printf("%-+10.5d\n", 4242);

    //printf("___________________\n");
    ft_printf("%5.o\n",  0);
    printf("%5.o\n", 0);
    //printf("___________________\n");

   // ft_printf("%03.2d\n", -1);
    //printf("%03.2d\n", -1);
   //printf("___________________\n");


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