#include "ft_printf.h"

extern int g_sym_count;

char *ft_add_string(char *result, char *str_arg, t_prinlist *lst, int numSys)
{
    char *tmp;
    size_t len;

    if(!str_arg)
        str_arg = ft_strdup("(null)");
    len = ft_strlen(str_arg);
    if(lst->pricision && lst->pricision < len && numSys != 16)//обрезаем строку
    {
        tmp = str_arg;
        str_arg = ft_strsub(str_arg, 0, lst->pricision);
        len = ft_strlen(str_arg);
    }
    if(lst->width > len && ((lst->flag & MINUS) == MINUS))// сдвигаем влево
    {
        ft_strcpy(result, str_arg);
        //result = ft_strjoin(result, str_arg);
        ft_memset(result + len, ' ', lst->width - len);
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

void ft_add_char(char **result, int chr_arg_int, t_prinlist *lst)
{
    char chr_arg;
    char *tmp;

    tmp = (char*)malloc(sizeof(char) + lst->width - 1);
    chr_arg = (char)chr_arg_int;
    if (chr_arg == 0)
    {
        if(((lst->flag & MINUS) == MINUS))
        {
            write(1, "\0", 1);
            if(lst->width > 1)
            {
                ft_memset(tmp, ' ', lst->width - 1);
                write(1, tmp, lst->width - 1);
                g_sym_count += lst->width - 1;
            }
            return;
        }
        else if(lst->width > 1)
        {
            ft_memset(tmp, ' ', lst->width - 1);
            write(1, tmp, lst->width - 1);
            g_sym_count += lst->width - 1;
        }
        write(1, "\0", 1);
        g_sym_count += 1;
        return;
    }
    if(lst->width > 1)
    {
        ft_memset(*result, ' ', lst->width);
        if((lst->flag & MINUS) == MINUS)
            (*result)[0] = chr_arg;
        else
            (*result)[lst->width - 1] = chr_arg;
    }
    else
        (*result)[lst->width] = chr_arg; // мб просто от 0 написать?
}