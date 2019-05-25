#include "ft_printf.h"

extern int g_sym_count;

char *ft_add_string(char *result, char *str_arg, t_prinlist *lst)
{
    char *tmp;
    size_t len;

    if(!str_arg)
        str_arg = ft_strdup("(null)");
    len = ft_strlen(str_arg);
    if(lst->pricision && lst->pricision < len)//обрезаем строку
    {
        tmp = str_arg;
        str_arg = ft_strsub(str_arg, 0, lst->pricision);
        len = ft_strlen(str_arg);
    }
    if(lst->width > len && ((lst->flag & MINUS) == MINUS))// сдвигаем влево
    {
        tmp = result;
        result = ft_strjoin(result, str_arg);
        tmp = result + len;
        ft_memset(tmp, ' ', lst->width - len);
    }
    else if(lst->width && lst->width > len) // сдвигаем вправо
    {
        ft_memset(result, ' ', lst->width - len);
        tmp = result + (lst->width - len);
        tmp = ft_strcpy(tmp, str_arg);
    }
    else
        result = ft_strjoin(result, str_arg);
    return (result);
}

void ft_add_char(char **result, char chr_arg, t_prinlist *lst)
{
    if (chr_arg == 0)
    {
        write(1, "\0", 1);
    }
    if(lst->width > 1)
    {
        *result = ft_memset(*result, ' ', lst->width);
        if((lst->flag & MINUS) == MINUS)
            (*result)[0] = chr_arg;
        else
            (*result)[lst->width - 1] = chr_arg;
    }
    else
        (*result)[lst->width] = chr_arg; // мб просто от 0 написать?
}