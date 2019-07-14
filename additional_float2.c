#include "ft_printf.h"

void    ft_add_neg_sign(char **float_nbr, char **buff)
{
    char *tmp;

    tmp = NULL;
    **buff = '-';
    (*buff)[1] = '\0';
    tmp = *float_nbr;
    ft_strcat(*buff, *float_nbr);
    *float_nbr = *buff;
    *buff = tmp;
}

int is_NanOrInf(char *dbl)
{
    if(!dbl)
        return (0);
    else if((ft_strcmp(dbl, "inf")) && (ft_strcmp(dbl, "-inf")) && (ft_strcmp(dbl, "nan")))
        return (0);
    else
        return (1);
}

t_len *ft_make_len_struct(void)
{
    t_len *len_l;

    len_l = malloc(sizeof(t_len));
    len_l->lenOfResult = 0;
    len_l->lenOfPower = 0;
    len_l->lenOfCurrentNbr = 0;
    len_l->lenOfIntPart = 0;
    len_l->flagIsFloatPart = 0;
    return (len_l);
}

void ft_plus_float(char *curret_num, char *power_two,t_len *len_l)
{
    if(!(*curret_num))
    {
        ft_strcpy(curret_num, power_two);
        return;
    }
    ft_make_even(curret_num, power_two);
    len_l->lenOfCurrentNbr = ft_strlen(curret_num);
    len_l->lenOfPower = ft_strlen(power_two);
    if(len_l->lenOfCurrentNbr < len_l->lenOfPower)
    {
        ft_memset((curret_num) + (len_l->lenOfCurrentNbr),'0', (len_l->lenOfPower - len_l->lenOfCurrentNbr));
        len_l->lenOfCurrentNbr += len_l->lenOfPower - len_l->lenOfCurrentNbr;
    }
    if(len_l->lenOfCurrentNbr > len_l->lenOfPower)
    {
        ft_memset((power_two) + (len_l->lenOfPower),'0', (len_l->lenOfCurrentNbr - len_l->lenOfPower));
        len_l->lenOfPower += len_l->lenOfCurrentNbr - len_l->lenOfPower;
    }
    len_l->flagIsFloatPart = 1;
    ft_plus_int(curret_num, power_two, len_l);
    if(ft_strlen(curret_num) > (len_l->lenOfCurrentNbr > len_l->lenOfPower ? len_l->lenOfCurrentNbr - 2 : len_l->lenOfPower - 2))
        curret_num[0] = *curret_num;
}

void ft_choice_options(char **result, char *tmp_result, t_prinlist *lst)
{
    if(tmp_result && (lst->flag & ZERO_PRIC) == ZERO_PRIC && (lst->flag & HASH) != HASH
        && !(is_NanOrInf(tmp_result)))
        tmp_result[ft_checkLenOfInt(tmp_result)] = '\0';
    lst->pr = 0;
    if(lst->flag || lst->w)
    {
        if(lst->w > 2000)
            lst->w = 0;
        ft_transform_int_result(result, tmp_result, lst);
    }
    else
        ft_strcpy(*result, tmp_result);
}