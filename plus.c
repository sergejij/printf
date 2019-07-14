#include "ft_printf.h"

void    ft_plus_neg_width_zero(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;

    tmp = NULL;
    if(lst->pr > len)
    {
        tmp = (char*)malloc(sizeof(char) * (lst->pr));
        ft_memset(*result, ' ', lst->w - (lst->pr + 1));
        *tmp = '-';
        ft_memset(tmp + 1, '0', lst->pr - (len - 1));
        ft_strcat(*result, tmp);
        ft_strcat(*result, arg + 1);
        ft_strdel(&tmp);
    }
    else if(lst->pr && lst->pr < len)
    {
        ft_memset(*result, ' ', lst->w - len);
        ft_strcat(*result, arg);
    }
}

void    ft_plus_neg_width_prec(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;
    char *tmp1;

    tmp = NULL;
    tmp = (char*)malloc(sizeof(char) * (lst->pr + len));
    tmp1 = tmp;
    if(lst->w > lst->pr)
    {
        ft_memset(*result, ' ', lst->w - lst->pr - 1);
        ft_strcat(*result, "-");
        ft_memset(tmp, '0', lst->pr - len + 1);
        ft_strcat(*result, tmp);
        ft_strcat(*result, (arg) + 1);
        ft_strdel(&tmp);
        return;
    }
    tmp = ft_memset(tmp, '0', lst->pr - len);
    ft_strcat(tmp, arg);
    ft_memset(*result, ' ', lst->w - (lst->pr + 1));
    tmp = ft_strjoin("+", arg);
    ft_strdel(&tmp1);
    ft_strcpy((*result) + lst->w - (lst->pr + 1), tmp);
    ft_strdel(&tmp);
}
void    ft_plus_negative_width(char **result, char *arg, t_prinlist *lst, size_t len)
{
    if (lst->pr > len && (lst->flag & ZERO) != ZERO)
        ft_plus_neg_width_prec(result, arg, lst, len);
    else if (((lst->flag & ZERO) == ZERO) && lst->w > len && lst->w > lst->pr)
    {
        if(lst->pr)
            ft_plus_neg_width_zero(result, arg, lst, len);
        else
        {
            (*result)[0] = '-';
            ft_memset(&(*result)[1], '0', lst->w - len);
            ft_strcat(*result, ++arg);
        }
    }
    else
    {
        ft_memset(*result, ' ', lst->w - lst->len);
        ft_strcpy(*result + lst->w - lst->len, arg);
    }
}
void    ft_plus_negative(char **result, char *arg, t_prinlist *lst, size_t len)
{
    if (lst->w > len)
        ft_plus_negative_width(result, arg, lst, len);
    else if (lst->pr >= len )//&& (lst->flag & ZERO) != ZERO)
    {
        ft_strncpy(*result, arg, 1);
        ft_memset((*result) + 1, '0', lst->pr - (len - 1));
        arg++;
        ft_strcat(*result, arg);
    }
    else
        *result = arg;
}

void    ft_plus_zero_pric(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;

    tmp = (char*)malloc(sizeof(char) * lst->w);
    if(lst->pr > len)
    {
        ft_memset(tmp, '0', lst->pr - len);
        ft_strcat(tmp, arg);
        ft_memset(*result, ' ', lst->w - (lst->pr + 1));
        ft_strcat(*result, "+");
        ft_strcat(*result, tmp);
    }
    else if (lst->pr == 0)
    {
        ft_memset(tmp, '0', lst->w - (len + 1));
        ft_strcat(tmp, arg);
        **result = '+';
        ft_strcat((*result) + 1, tmp);
    }
    else
    {
        ft_memset(*result, ' ', lst->w - (len + 1));
        ft_strcat(*result, "+");
        ft_strcat(*result, arg);
    }
    ft_strdel(&tmp);
}
void    ft_plus_zero(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;

    tmp = NULL;
    if(lst->w > lst->pr)
        ft_plus_zero_pric(result, arg, lst, len);
    else
    {
        if  (lst->w < lst->pr)
        {
            ft_memset(*result, '0', lst->pr - len);
            ft_strcpy((*result) + lst->pr - len, arg);
        }
        else
        {
            ft_memset(*result, '0', lst->w - (len + 1));
            ft_strcpy((*result) + lst->w - (len + 1), arg);
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
    if (lst->pr > len && (lst->flag & ZERO) != ZERO)
    {
        tmp = (char*)malloc(sizeof(char) * (lst->pr - len));
        *tmp = '+';
        ft_memset(tmp + 1, '0', lst->pr - len);
        ft_memset(*result, ' ', lst->w - (lst->pr + 1));
        ft_strcpy(tmp + lst->pr - len + 1, arg);
        ft_strcpy((*result) + lst->w - (lst->pr + 1), tmp);
    }
    else if ((((lst->flag & ZERO) == ZERO) && lst->w > len))
        ft_plus_zero(result, arg, lst, len);
    else
    {
        ft_memset(*result, ' ', lst->w - (lst->len + 1));
        tmp = ft_strjoin("+", arg);
        ft_strcpy((*result) + lst->w - (lst->len + 1), tmp);
        ft_strdel(&tmp);
    }
}
void    ft_plus(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;

    if (*arg == '-')
    {
        ft_plus_negative(result, arg, lst, len);
        return ;
    }
    if(lst->w > len)
        ft_plus_width(result, arg, lst, len);
    else
    {
        tmp = *result;
        *tmp = '+';
        if(lst->pr > len)
        {
            ft_memset((*result) + 1, '0', lst->pr - len);
            ft_strcat(*result, arg);
        }
        else
            ft_strcat(*result, arg);
    }
}