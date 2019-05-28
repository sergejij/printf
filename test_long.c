#include "ft_printf.h"

void    ft_plus_negative_l(char **result, char *arg, t_prinlist *lst, size_t len)
{
   // char *tmp;

    if (lst->width > len)
    {
        if (((lst->flag & ZERO) == ZERO) && lst->width > len)
        {
            (*result)[0] = '-';
            ft_memset(&(*result)[1], '0', lst->width - len);
            ft_strcat(*result, ++arg);
            //*result = ft_strjoin("+", *result);
            return;
        }
        ft_memset(*result, ' ', lst->width - len);
       // tmp = ft_strjoin("+", arg);
        // тут надо править! при  printf("\n%d\n", ft_printf("%+10.5d",  i)); не заполняет нуляями
        ft_strcpy(*result + lst->width - len, arg);
    }
    else
        *result = arg;
}

void    ft_plus_l(char **result, char *arg, t_prinlist *lst, size_t len)
{
    char *tmp;

    if (*arg == '-')
    {
        ft_plus_negative_l(result, arg, lst, len - 1);
        return ;
    }
    if(lst->width > len)
    { //ft_strcpy(*result + lst->pricision  - len, ft_itoa(arg));

        if ((((lst->flag & ZERO) == ZERO) && lst->width > len))
        {
            ft_memset(*result, '0', lst->width - len);
            ft_strcpy((*result) + lst->width - len, arg);
            *result = ft_strjoin("+", *result);
            return;
        }
        ft_memset(*result, ' ', lst->width - len);
        tmp = ft_strjoin("+", arg);
        // тут надо править! при  printf("\n%d\n", ft_printf("%+10.5d",  i)); не заполняет нуляями
        ft_strcpy((*result) + lst->width - len, tmp);
        return;
    }
     if (*arg != '-')
    {
        tmp = *result;
        *result = ft_strjoin("+", arg);
        //ft_strdel(&tmp);
    }
  //  *result = arg;
}

void    ft_pricision_l(char **result, t_prinlist *lst, size_t len)
{
    if (lst->width > len && lst->width > lst->pricision)
        ft_memset(*result, ' ', lst->width - lst->pricision);
    else if (lst->width < lst->pricision)
        ft_memset(*result, '0', lst->pricision - len);
    ft_memset(*result + (lst->width - lst->pricision), '0', lst->pricision  - len);
}

void    ft_recording_negative_l(char **result, char *arg, t_prinlist *lst, char fill)
{
    lst->pricision += 1;
    lst->len -=1;
    if (lst->pricision > lst->len)
        ft_pricision_l(result, lst, lst->len);
    if (lst->width > lst->len && fill == ' ')
    {
      //  ft_memset(*result, fill, lst->width - lst->len);
        (*result)[lst->width - lst->pricision] = '-';
        *result = ft_strjoin(*result, ++arg);
        return ;
    }
    (*result)[0] = '-';
    if (lst->width > lst->len)
        ft_memset((*result) + 1, fill, lst->width - (lst->len + 1));
    *result = ft_strjoin(*result, ++arg);
}

void    ft_recording_l(char **result, char *arg, t_prinlist *lst, char fill)
{
    if(*arg == '-')
    {
        ft_recording_negative_l(result, arg, lst, fill);
        return;
    }
    else if (lst->pricision > lst->len)
        ft_pricision_l(result, lst, lst->len);
    else if (lst->width > lst->len)
        ft_memset(*result, fill, lst->width - lst->len);
    *result = ft_strjoin(*result, arg);
}

void    ft_minus_negative_l(char **result, char *arg, t_prinlist *lst, size_t len)
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
        if (((lst->flag & PLUS) == PLUS) && (*arg != '-'))
        {
            ft_strcpy(*result, "+");
            ft_strcpy((*result) + 1, arg);
            ft_memset((*result) + len + 1, ' ', lst->width - len);
            (*result)[lst->width] = '\0';
            return ;
        }
        ft_strcpy(*result, arg);
        if(lst->width > len)
        {
            ft_memset((*result) + lst->len, ' ', lst->width - len);
            (*result)[lst->width] = '\0';
        }
    }
}


void    ft_minus_l(char **result, char *arg, t_prinlist *lst, size_t len)
{
    if(*arg == '-')
    {
        ft_minus_negative_l(result, arg, lst, lst->len);
        return;
    }
    if (lst->pricision > len)
    {
        ft_memset(*result, '0', lst->pricision  - len);
        ft_strcpy(*result + lst->pricision  - len, arg);
        if (lst->width > lst->pricision)
        {    ft_memset(*result + lst->pricision, ' ', lst->width - lst->pricision);
            (*result)[lst->width] = '\0';
        }
        else
            (*result)[lst->pricision] = '\0';
    }
    else
    {
        if (((lst->flag & PLUS) == PLUS))
        {
            ft_strcpy(*result, "+");
            ft_strcpy(*result + 1, arg);
            ft_memset(*result + len + 1, ' ', lst->width - len);
            (*result)[lst->width] = '\0';
            return ;
        }
        ft_strcpy(*result, arg);
        ft_memset(*result + len, ' ', lst->width - len);
        (*result)[lst->width] = '\0';
    }
}
void ft_transform_int_result(char **result, t_prinlist *lst)
{
    char *cpy_num;

    lst->len = ft_strlen(*result);
    cpy_num = ft_strdup(*result);
    ft_strclr(*result);
    if ((lst->flag & MINUS) == MINUS)
        ft_minus_l(result, cpy_num, lst, lst->len);
    else if (((lst->flag & PLUS) == PLUS)) // +
        ft_plus_l(result, cpy_num, lst, lst->len + 1); // + 1 так как + это тоже часть числа
    else if (((lst->flag & ZERO) == ZERO)) // zero
        ft_recording_l(result, cpy_num, lst, '0');
    else
        ft_recording_l(result, cpy_num, lst, ' ');
}


void ft_long_to_str(char **result, long long int arg, t_prinlist *lst)
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
    if(lst->flag || lst->width || lst->pricision)
        ft_transform_int_result(result, lst);
}



