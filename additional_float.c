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

void ft_makeEven(char *curretNum, char *powerTwo)
{
    size_t intCurrLen;
    size_t intPowLen;
    char *tmp;

    intCurrLen = 0;
    intPowLen = 0;
    tmp = (char *)malloc(sizeof(char) * (ft_strlen(curretNum) + ft_strlen(powerTwo)));
    while(curretNum[intCurrLen] != '.')
        intCurrLen++;
    while(powerTwo[intPowLen] != '.')
        intPowLen++;
    if(intCurrLen > intPowLen)
    {
        ft_memset(tmp, '0', intCurrLen - intPowLen);
        ft_strcat(tmp, powerTwo);
        ft_strcpy(powerTwo, tmp);
    }
    else if (intPowLen > intCurrLen)
    {
        ft_memset(tmp, '0', intPowLen - intCurrLen);
        ft_strcat(tmp, curretNum);
        ft_strcpy(curretNum, tmp);
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

void ft_makePower(char *current_power)
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

char *findPower(int power)
{
    char *posPow = NULL;
    char *negPow = NULL;
    char *result = NULL;
    char *tmp;

    posPow = ft_strdup("2");
    negPow = ft_strdup("00000000000000000000000082718061255302767487140869206996285356581211090087890625");
    tmp = NULL;
    result = (char *)malloc(sizeof(char) * 310);
    if(power == 0)
        ft_strcpy(result, "1");
    else if(power > 0)
    {
        ft_strcpy(result, posPow);
        while(power-- > 1)
            ft_makePower(result);
    }
    else if (power < 0)
    {
        ft_strcpy(result, negPow);
        while(power-- > -80)
            ft_makePower(result);
        tmp = result;
        result = ft_strjoin("0.", tmp);
    }
    return (result);
}