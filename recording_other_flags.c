#include "ft_printf.h"

void    ft_recording_neg_width(char **result, char *arg, t_prinlist *lst, char fill)
{
    if (lst->width > lst->len && fill == ' ')
    {
        ft_memset(*result, fill, lst->width - lst->len);
        (*result)[lst->width - lst->len] = '-';
        *result = ft_strjoin(*result, ++arg);
    }
    else if (lst->width > lst->len && (lst->flag & ZERO) == ZERO && lst->pricision)
    {
        ft_memset(*result, ' ', lst->width - lst->len);
        (*result)[lst->width - lst->len] = '-';
        *result = ft_strjoin(*result, ++arg);
    }
}

void    ft_recording_negative(char **result, char *arg, t_prinlist *lst, char fill)
{
    char *tmp;

    if(!(tmp = ft_strnew(lst->pricision + lst->width + lst->len + 1)))
        exit(1);
    if (lst->pricision > lst->len)
    {
        ft_pricision(result, lst, lst->len, arg);
        if(lst->width > lst->len)
        {
            ft_strcat(*result, arg + 1);
            return;
        }
    }
    else if (lst->width > lst->len && (fill == ' ' || ((lst->flag & ZERO) == ZERO && lst->pricision)))
    {
        ft_recording_neg_width(result, arg, lst, fill);
        return;
    }
    *tmp = '-';
    if (lst->width > lst->len)
        ft_memset((*result), fill, lst->width - lst->len);
    ft_strcat(tmp, *result);
    ft_strcpy(*result, tmp);
    ft_strcat(*result, ++arg);
}

void    ft_recording_width(char **result, t_prinlist *lst, char fill)
{
    if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO)
        ft_memset(*result, '0',lst->width - lst->len);
    else if ((lst->flag & SPACE) == SPACE && (lst->flag & ZERO_PRIC) != ZERO_PRIC)
    {
        if(lst->width > lst->pricision && lst->pricision)
            fill = ' ';
        **result = ' ';
        lst->width--;
        ft_memset((*result) + 1, fill, lst->width - lst->len);
    }
    else
    {
        if(lst->width > lst->len && (lst->flag & ZERO) == ZERO && lst->pricision)
            ft_memset(*result, ' ', lst->width - lst->len);
        else
            ft_memset(*result, fill, lst->width - lst->len);
    }
}

void    ft_recording(char **result, char *arg, t_prinlist *lst, char fill)
{
    if(*arg == '-')
    {
        ft_recording_negative(result, arg, lst, fill);
        return;
    }
    else if (lst->pricision > lst->len)
        ft_pricision(result, lst, lst->len, arg);
    else if (lst->width > lst->len)
        ft_recording_width(result, lst, fill);
    ft_strcat(*result, arg);
}
