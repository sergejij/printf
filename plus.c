#include "ft_printf.h"


void    ft_plus_neg_width_zero(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;

    tmp = NULL;
    tmp = (char*)malloc(sizeof(char) * (lst->pricision));
    if(lst->width > lst->pricision)
    {
        ft_memset(*result, ' ', lst->width - lst->pricision - 1);
        ft_strcat(*result, "-");
        ft_memset(tmp, '0', lst->pricision - len + 1);
        ft_strcat(*result, tmp);
        ft_strcat(*result, (arg) + 1);
        return;
    }
    tmp = ft_memset(tmp, '0', lst->pricision - len);
    arg = ft_strjoin(tmp, arg);
    ft_memset(*result, ' ', lst->width - (lst->pricision + 1));
    tmp = ft_strjoin("+", arg);
    ft_strcpy((*result) + lst->width - (lst->pricision + 1), tmp);
}
void    ft_plus_negative_width(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;

    tmp = NULL;
        if (lst->pricision > len && (lst->flag & ZERO) != ZERO)
            ft_plus_neg_width_zero(result, arg, lst, len);
        else if (((lst->flag & ZERO) == ZERO) && lst->width > len && lst->width > lst->pricision)
        {
            if(lst->pricision > len)
            {
                tmp = (char*)malloc(sizeof(char) * (lst->pricision));
                ft_memset(*result, ' ', lst->width - (lst->pricision + 1));
                *tmp = '-';
                ft_memset(tmp + 1, '0', lst->pricision - (len - 1));
                ft_strcat(*result, tmp);
                ft_strcat(*result, arg + 1);
            }
            else if(lst->pricision && lst->pricision < len)
            {
                ft_memset(*result, ' ', lst->width - len);
                ft_strcat(*result, arg);
            }
            else
            {
                (*result)[0] = '-';
                ft_memset(&(*result)[1], '0', lst->width - len);
                ft_strcat(*result, ++arg);
            }
        }
        else
        {
            ft_memset(*result, ' ', lst->width - lst->len);
            ft_strcpy(*result + lst->width - lst->len, arg);
        }

}
void    ft_plus_negative_l(char **result, char *arg, t_prinlist *lst, size_t len)
{
    if (lst->width > len)
        ft_plus_negative_width(result, arg, lst, len);
    else if (lst->pricision >= len )//&& (lst->flag & ZERO) != ZERO)
    {
        ft_strncpy(*result, arg, 1);
        ft_memset((*result) + 1, '0', lst->pricision - (len - 1));
        arg++;
        ft_strcat(*result, arg);
    }
    else
        *result = arg;
}

void    ft_plus_zero_pric(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;

    tmp = NULL;
    if(lst->pricision > len)
    {
        tmp = (char*)malloc(sizeof(char) * lst->pricision);
        ft_memset(tmp, '0', lst->pricision - len);
        ft_strcat(tmp, arg);
        ft_memset(*result, ' ', lst->width - (lst->pricision + 1));
        ft_strcat(*result, "+");
        ft_strcat(*result, tmp);
        ft_strdel(&tmp);
    }
    else if (lst->pricision == 0)
    {
        tmp = (char*)malloc(sizeof(char) * lst->width);
        ft_memset(tmp, '0', lst->width - (len + 1));
        ft_strcat(tmp, arg);
        **result = '+';
        ft_strcat((*result) + 1, tmp);
        ft_strdel(&tmp);
    }
    else
    {
        ft_memset(*result, ' ', lst->width - (len + 1));
        ft_strcat(*result, "+");
        ft_strcat(*result, arg);
    }
}
void    ft_plus_zero(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;

    tmp = NULL;
    if(lst->width > lst->pricision)
        ft_plus_zero_pric(result, arg, lst, len);
    else
    {
        if  (lst->width < lst->pricision)
        {
            ft_memset(*result, '0', lst->pricision - len);
            ft_strcpy((*result) + lst->pricision - len, arg);
        }
        else
        {
            ft_memset(*result, '0', lst->width - (len + 1));
            ft_strcpy((*result) + lst->width - (len + 1), arg);
        }
        tmp = *result;
        *result = ft_strjoin("+", *result);
        ft_strdel(&tmp);
    }
}

void    ft_plus_width(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;

    tmp = NULL;
    if (lst->pricision > len && (lst->flag & ZERO) != ZERO)
    {
        tmp = (char*)malloc(sizeof(char) * (lst->pricision - len));
        *tmp = '+';
        ft_memset(tmp + 1, '0', lst->pricision - len);
        ft_memset(*result, ' ', lst->width - (lst->pricision + 1));
        ft_strcpy(tmp + lst->pricision - len + 1, arg);
        ft_strcpy((*result) + lst->width - (lst->pricision + 1), tmp);
    }
    else if ((((lst->flag & ZERO) == ZERO) && lst->width > len))
        ft_plus_zero(result, arg, lst, len);
    else
    {
        ft_memset(*result, ' ', lst->width - (lst->len + 1));
        tmp = ft_strjoin("+", arg);
        ft_strcpy((*result) + lst->width - (lst->len + 1), tmp);
        ft_strdel(&tmp);
    }
}
void    ft_plus_l(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;

    if (*arg == '-')
    {
        ft_plus_negative_l(result, arg, lst, len);
        return ;
    }
    if(lst->width > len)
        ft_plus_width(result, arg, lst, len);
    else
    {
        tmp = *result;
        *tmp = '+';
        if(lst->pricision > len)
        {
            ft_memset((*result) + 1, '0', lst->pricision - len);
            ft_strcat(*result, arg);
        }
        else
            ft_strcat(*result, arg);
    }
}