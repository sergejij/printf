#include "ft_printf.h"
void ft_addSpaceWithPlus(char **result, char *arg, t_prinlist *lst, size_t len)
{
    **result = ' ';
    ft_memset(*result + 1, '0', lst->pricision  - len);
    ft_strcpy(*result + 1 + lst->pricision  - len, arg);
    ft_memset((*result) + 1 + lst->pricision, ' ', lst->width - lst->pricision - 1);
}

void    ft_minus_neg_prec(char **result, char *arg, t_prinlist *lst, size_t len)
{
    if ((lst->flag & PLUS) == PLUS)
        (*result)[0] = '+';
    ft_memset((*result)[0] == '+' ? *result + 1 : *result, '0', lst->pricision  - len);
    ft_strcpy(((*result)[0] == '+' ? *result + 1 : *result) + lst->pricision  - len, arg);
    if (lst->width > lst->pricision)
    {
        if((lst->flag & SPACE) == SPACE)
        {
            ft_addSpaceWithPlus(result, arg, lst, len);
            return;
        }
        if((*result)[0] == '+')
            ft_memset((*result) + 1 + lst->pricision, ' ', lst->width - lst->pricision - 1);
        else
            ft_memset(*result + lst->pricision, ' ', lst->width - lst->pricision);
    }
}

void    ft_minus_negative(char **result, char *arg, t_prinlist *lst, size_t len)
{
    if (lst->pricision++ > len--)
    {
        (*result)[0] = '-';
        ft_memset((*result) + 1, '0', lst->pricision  - len);
        ft_strcpy((*result) + (lst->pricision  - len), ++arg);
        if (lst->width > lst->pricision)
        {
            ft_memset((*result) + lst->pricision, ' ', lst->width - lst->pricision);
            (*result)[lst->width] = '\0';
        }
        else
            (*result)[lst->pricision] = '\0';
    }
    else
    {
        ft_strcpy(*result, arg);
        if(lst->width > len)
            ft_memset((*result) + lst->len, ' ', lst->width - len - 1);
    }
}

void    ft_minus_hash_or_zero_or_space(char **result, char *arg, t_prinlist *lst, size_t len)
{
    if (lst->width > len)
    {

        if((lst->flag & SPACE) == SPACE)
        {
            **result = ' ';
            ft_strcpy((*result) + 1, arg);
            ft_memset(*result + len + 1, ' ', lst->width - (len + 1));
        }
        else
        {
            ft_strcpy(*result, arg);
            ft_memset(*result + len, ' ', lst->width - len);
        }
    }
    else
        ft_strcpy(*result, arg);
}

void    ft_minus(char **result, char *arg, t_prinlist *lst, size_t len)
{
    if(*arg == '-')
        ft_minus_negative(result, arg, lst, lst->len);
    else if (lst->pricision > len)
        ft_minus_neg_prec(result, arg, lst, lst->len);
    else
    {
        if (((lst->flag & PLUS) == PLUS))
        {
            ft_strcpy(*result, "+");
            ft_strcpy(*result + 1, arg);
            if (lst->width > len)
                ft_memset(*result + len + 1, ' ', lst->width - len - 1);
        }
        else
            ft_minus_hash_or_zero_or_space(result, arg, lst, lst->len);
    }
}
