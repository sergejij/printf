/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:20:57 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/29 17:39:49 by aestella         ###   ########.fr       */
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


    ft_printf("%u", 42);

    ft_printf("%5u\n", 4294967295);                // -> "4294967295"
    ft_printf("%15u\n", 4294967295);               // -> "     4294967295"
    ft_printf("%-15u\n", 4294967295);              // -> "4294967295     "
    ft_printf("%015u\n", 4294967295);              // -> "000004294967295"
    ft_printf("% u\n", 4294967295);                // -> "4294967295"
    ft_printf("%+u\n", 4294967295);                // -> "4294967295"
    ft_printf("%lu\n", 4294967295);                // -> "4294967295"
    ft_printf("%lu\n", 4294967296);                // -> "4294967296"
    ft_printf("%lu\n", -42);                       // -> "18446744073709551574"
    ft_printf("%llu\n", 4999999999);               // -> "4999999999"

    /*  printf("\n%d\n", ft_printf("%.2x", i));
      printf("\n%d\n", printf("%.2x", i));

      printf("___________________\n");

     // printf("___________________\n");

     // ft_printf("%-+10.5d\n", 4242);
     // printf("%-+10.5d\n", 4242);

      printf("___________________\n");
      ft_printf("%.o\n", 0);
      printf("%.o\n",  0);
      printf("___________________\n");

      ft_printf("%03.2d\n", -1);
      printf("%03.2d\n", -1);
      printf("___________________\n");


      ft_printf("%5d\n", 42);
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