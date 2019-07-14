#include "ft_printf.h"

size_t ft_checkLenOfInt(char *nbr)
{
    size_t i;

    i = 0;
    if(nbr && !(is_NanOrInf(nbr)))
        while(nbr[i] != '.')
            i++;
    return (i);
}

void ft_make_even(char *cur_num,char *pow_two)
{
    size_t i_cur_len;
    size_t i_pow_len;
    char *tmp;

    i_cur_len = 0;
    i_pow_len = 0;
    tmp = (char *)malloc(sizeof(char) * (ft_strlen(cur_num) + ft_strlen(pow_two)));
    while(cur_num[i_cur_len] != '.')
        i_cur_len++;
    while(pow_two[i_pow_len] != '.')
        i_pow_len++;
    if(i_cur_len > i_pow_len)
    {
        ft_memset(tmp, '0', i_cur_len - i_pow_len);
        ft_strcat(tmp, pow_two);
        ft_strcpy(pow_two, tmp);
    }
    else if (i_pow_len > i_cur_len)
    {
        ft_memset(tmp, '0', i_pow_len - i_cur_len);
        ft_strcat(tmp, cur_num);
        ft_strcpy(cur_num, tmp);
    }
}

void ft_handle_result_f(int len, int *int_res, char *result)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(int_res[i] == 0)
        i++;
    while(len-- > i)
        result[j++] = int_res[len] + '0';
    result[j] = '\0';
}

void ft_make_power(char *current_power)
{
    int *res;
    char *tmp;
    int len;
    int flag;

    len = ft_strlen(current_power);
    res = (int *)malloc(sizeof(int) * (len + 1));
    tmp = current_power;
    ft_strrev(current_power);
    len = 0;
    flag = 0;
    while(*tmp)
    {
        res[len] = (*tmp++ - '0') * 2 + flag;
        flag = 0;
        if(res[len] > 9)
        {
            flag = res[len] / 10;
            res[len] %= 10;
        }
        len++;
    }
    if(flag)
        res[len++] = flag;
    ft_handle_result_f(len, res, current_power);
}

char *ft_find_power(int power)
{
    char *pos_pow= NULL;
    char *neg_pow = NULL;
    char *result = NULL;
    char *tmp;

    pos_pow = ft_strdup("2");
    neg_pow = ft_strdup("00000000000000000000000082718061255302767487140869206996285356581211090087890625");
    tmp = NULL;
    result = (char *)malloc(sizeof(char) * 310);
    if(power == 0)
        ft_strcpy(result, "1");
    else if(power > 0)
    {
        ft_strcpy(result, pos_pow);
        while(power-- > 1)
            ft_make_power(result);
    }
    else if (power < 0)
    {
        ft_strcpy(result, neg_pow);
        while(power-- > -80)
            ft_make_power(result);
        tmp = result;
        result = ft_strjoin("0.", tmp);
    }
    return (result);
}