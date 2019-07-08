#include "ft_printf.h"

extern int g_sym_count;

char *ft_makeCpyStr(char *str_arg, t_prinlist *lst, int numSys)
{
    char *arg;
    size_t len;

    arg = NULL;
    if(!str_arg)
    {
        if(!(arg = ft_strdup("(null)")))
            exit(1);
        len = 6;
    }
    else
    {
        len = ft_strlen(str_arg);
        if(!(arg = ft_strnew(len)))
            exit(1);
        ft_strcpy(arg, str_arg);
    }
    if(lst->pricision && lst->pricision < len && numSys != 16)
    {
        arg[lst->pricision] = '\0';
        len = lst->pricision;
    }
    lst->len = len;
    return (arg);
}

char *ft_add_string(char **result, char *str_arg, t_prinlist *lst, int numSys)
{
    char *arg;

    arg = NULL;

    arg = ft_makeCpyStr(str_arg, lst, numSys);
    if(lst->width > lst->len && ((lst->flag & MINUS) == MINUS))// сдвигаем влево
    {
        ft_strcpy(*result, arg);
        ft_memset((*result) + lst->len, ' ', lst->width - lst->len);
    }
    else if(lst->width && lst->width > lst->len) // сдвигаем вправо
    {
        ft_memset(&((*result)[0]), ' ', lst->width - lst->len);
        ft_strcpy((*result) + (lst->width - lst->len), arg);
    }
    else
        ft_strcpy(*result, arg);
    ft_strdel(&arg);
    return (*result);
}
void ft_print_full_chr_width(t_prinlist *lst)
{
    char *tmp;

    tmp = NULL;
    tmp = (char*)malloc(sizeof(char) * lst->width - 1);
    ft_memset(tmp, ' ', lst->width - 1);
    write(1, tmp, lst->width - 1);
    g_sym_count += lst->width - 1;
    ft_strdel(&tmp);
}

void ft_add_zero_chr(t_prinlist *lst)
{

    if(((lst->flag & MINUS) == MINUS))
    {
        write(1, "\0", 1);
        if(lst->width > 1)
            ft_print_full_chr_width(lst);
        return;
    }
    else if(lst->width > 1)
        ft_print_full_chr_width(lst);
    write(1, "\0", 1);
    g_sym_count += 1;
}
void ft_add_char(char **result, int chr_arg_int, t_prinlist *lst)
{
    char chr_arg;

    chr_arg = (char)chr_arg_int;
    if (chr_arg == 0)
        ft_add_zero_chr(lst);
    else
    {
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
}