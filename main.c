/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:20:57 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/25 19:46:07 by ubartemi         ###   ########.fr       */
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
    float g = 123.223;
   // int *a = &i;
    unsigned long a = 9223372036854775807;
    //printf("\n%d", ft_printf("test %s", "huest"));
    printf("\n%d\n", ft_printf("%+10.5d",  i));
    printf("\n%d\n", printf("%+10.5d", i));
    free(tmp);
    return  0;
}