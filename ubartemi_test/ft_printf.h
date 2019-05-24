/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:45:57 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/24 10:57:09 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_FT_PRINTF_H
#define PRINTF_FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "./libft/libft.h"
# define ZERO 2
typedef struct  s_prinlist
{
    int flag;
    int width;
    int pricision;
}               t_prinlist;

#endif //PRINTF_FT_PRINTF_H
