#include "ft_printf.h"

extern int g_sym_count;

char *ft_add_string(char *result, char *str_arg, t_prinlist *lst)
{
    char *tmp;
    size_t len;
    char *arg_cpy = ft_strdup(str_arg);

    len = ft_strlen(arg_cpy);
    if(lst->pricision && lst->pricision < len)//обрезаем строку
    {
        ft_memset(arg_cpy + lst->pricision, '\0', len - lst->pricision);
        len = ft_strlen(arg_cpy);
    }
    if(lst->width > len && ((lst->flag & 4) == 4))// сдвигаем влево
    {
        result = ft_strjoin(result, arg_cpy);
        tmp = result + len;
        ft_memset(tmp, '.', lst->width - len);
    }
    else if(lst->width && lst->width > len) // сдвигаем вправо
    {
        ft_memset(result, '.', lst->width - len);
        tmp = result + len;
        tmp = ft_strcpy(tmp, arg_cpy);
    }
    else
        result = ft_strjoin(result, arg_cpy);
    g_sym_count += ft_strlen(result);
    return (result);
}

