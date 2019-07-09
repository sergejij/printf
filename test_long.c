#include "ft_printf.h"

void    ft_pricision(char **result, t_prinlist *lst, size_t len, char *arg)
{
    char *tmp;
    if (lst->width > len && lst->width > lst->pricision)
        ft_memset(*result, ' ', arg[0] == '-' ? lst->width - (lst->pricision + 1) : lst->width - lst->pricision);
    else if (lst->width < lst->pricision && lst->pricision >= len)
    {
        ft_memset(*result, '0', arg[0] == '-' ? lst->pricision - (len - 1) : lst->pricision - len);
        (*result)[arg[0] == '-' ? lst->pricision - (len - 1) : lst->pricision - len] = '\0';
        return;
    }
    if ((lst->flag & PLUS) == PLUS)
    {
        tmp = ft_strjoin("+", arg);
        *result = ft_strjoin(tmp, *result);
        return;
    }
    if(ft_strncmp(arg, "-", 1) == 0)
    {
        ft_strcat(*result, "-");
        ft_memset(*result + (lst->width - lst->pricision), '0', lst->pricision  - (len - 1));
    }
    else
        ft_memset(*result + (lst->width - lst->pricision), '0', lst->pricision  - len);
    if(lst->width > lst->len)
        ft_strcat(*result, arg + 1);
}



void ft_transform_int_result(char **result, t_prinlist *lst)
{
    char *cpy_num;

    lst->len = ft_strlen(*result);
    cpy_num = strdup(*result);
    ft_strclr(*result);
    if ((lst->flag & MINUS) == MINUS)
        ft_minus(result, cpy_num, lst, lst->len);
    else if (((lst->flag & PLUS) == PLUS)) // +
        ft_plus(result, cpy_num, lst, lst->len); // + 1 так как + это тоже часть числа cpy_num[0] == '-' ? 0 : 1
    else if (((lst->flag & ZERO) == ZERO)) // zero
        ft_recording(result, cpy_num, lst, '0');
    else
        ft_recording(result, cpy_num, lst, ' ');
    if ((lst->flag & SPACE) == SPACE && (lst->flag & PLUS) != PLUS &&  **result != '-' && lst->width < lst->len)
        *result = ft_strjoin(" ", *result);
    ft_strdel(&cpy_num);
}

void ft_ltoa(char **result, long long arg)
{
    int piece;
    int del;
    char **new_res;
    int i;
    char *tmp = *result;

    del = 100000;
    i = 0;
    if(!(new_res = (char **)malloc(sizeof(char*) * 5)))
        return;
    if(arg < 0)
    {
        if(-9223372036854775807 > arg)
        {
            ft_strcpy(*result, "-9223372036854775808");
            return;
        }
        **result = '-';
        arg *= -1;
    }
    while(arg > del)
    {
        piece = (int)(arg % del);
        arg /= del;
        new_res[i] = ft_strdup(ft_itoa(piece));
        i++;
    }
    new_res[i] = ft_strdup(ft_itoa((int)arg));
    new_res[++i] = NULL;
    while(i-- > 0)
    {
        ft_strcat(*result, new_res[i]);
        tmp = *result + 5; //без тмп не компилилось(
    }
}

void ft_long_to_str(char **result, long long int arg, t_prinlist *lst)
{
    ft_ltoa(result, arg);
    if(lst->flag || lst->width || lst->pricision)
        ft_transform_int_result(result, lst);
}
