/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:01:40 by ubartemi          #+#    #+#             */
/*   Updated: 2019/05/27 18:02:29 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_add_octal(char **result, int arg, t_prinlist *lst, char sym)
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
    len = arg < 0 ? 8 : ft_lennum(arg);
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
    if ((lst->flag & ZERO) == ZERO)
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