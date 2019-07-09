//
// Created by Asafoetida Estella on 2019-07-02.
//

#include <stdio.h>
#include "libft/libft.h"
#include <math.h>
#include <limits.h>

typedef struct s_len{
    size_t lenOfCurrentNbr;
    size_t lenOfResult;
    size_t lenOfIntPart;
    size_t lenOfPower;
} t_len;


void ft_plus_int(char *curretNum, char *cpyPower, t_len *Len)
{
    char *tmp_curr = NULL;

    int flag;
    int *res = NULL;
    tmp_curr = curretNum;
    Len->lenOfCurrentNbr = ft_strlen(curretNum) > ft_strlen(cpyPower) ? ft_strlen(curretNum) : ft_strlen(cpyPower);
    flag = 0;

    res = malloc(sizeof(int) * Len->lenOfCurrentNbr);
    Len->lenOfCurrentNbr = 0;
    ft_strrev(curretNum);
    ft_strrev(cpyPower);
    while(*tmp_curr || *cpyPower)
    {
        if(*tmp_curr && *cpyPower)
            res[Len->lenOfCurrentNbr] = (((*cpyPower++ - '0') + (*tmp_curr++ - '0')) + flag);
        else if(!(*tmp_curr) && *cpyPower)
            res[Len->lenOfCurrentNbr] = *cpyPower++ - '0' + flag;
        else
            res[Len->lenOfCurrentNbr] = *tmp_curr++ -'0' + flag;
        flag = 0;
        if(res[Len->lenOfCurrentNbr] > 9)
        {
            flag = res[Len->lenOfCurrentNbr] / 10;
            res[Len->lenOfCurrentNbr] %= 10;
        }
        Len->lenOfCurrentNbr++;
    }
    if (flag)
    {
        res[Len->lenOfCurrentNbr++] = -2;
        res[Len->lenOfCurrentNbr++] = flag;
    }
    Len->lenOfResult = 0;
    ft_strclr(curretNum);
    while(Len->lenOfCurrentNbr--)
    {
        curretNum[Len->lenOfResult] = (char) (res[Len->lenOfCurrentNbr] + '0');
        Len->lenOfResult++;
    }
    curretNum[Len->lenOfResult] = '\0';
}

char *ft_floatCpy(char *float_str, size_t len, t_len *Len)
{
    char *cpy_curr;
    int i;
    int j;

    i = 0;
    j = 0;
    Len->lenOfIntPart = 0;
    cpy_curr = (char *)malloc(sizeof(char) * (len + 1));
    while(float_str[i] != '.' && float_str[i])
    {
        cpy_curr[i] = float_str[i];
        Len->lenOfIntPart++;
        i++;
    }
    j = i;
    while (float_str[i++])
    {
        cpy_curr[j++] = float_str[i];
        //i++;
    }
    return (cpy_curr);
}

char *ft_floatHandleRes(char *dest, char* src, size_t intLen)
{
    char *cpy_dest;

    cpy_dest = dest;
    while(intLen--)
        *cpy_dest++ = *src++;
    *cpy_dest++ = '.';
    while(*src)
        *cpy_dest++ = *src++;
    return (dest);
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
        ft_strclr(tmp);
    }
    else
    {
        ft_memset(tmp, '0', intPowLen - intCurrLen);
        ft_strcat(tmp, curretNum);
        ft_strcpy(curretNum, tmp);
        ft_strclr(tmp);
    }
}

void ft_plus_float(char *curretNum, char *powerTwo, t_len *Len)
{
    char *cpy_cur = NULL;
    char *cpy_power = NULL;

    ft_makeEven(curretNum, powerTwo);
    Len->lenOfCurrentNbr = ft_strlen(curretNum);
    Len->lenOfPower = ft_strlen(powerTwo);
    if(!(*curretNum))
    {
        ft_strcpy(curretNum, powerTwo);
        return;
    }
    if(Len->lenOfCurrentNbr < Len->lenOfPower)
    {
        ft_memset((curretNum) + (Len->lenOfCurrentNbr),'0', (Len->lenOfPower - Len->lenOfCurrentNbr));
        Len->lenOfCurrentNbr += Len->lenOfPower - Len->lenOfCurrentNbr;
    }
    if(Len->lenOfCurrentNbr > Len->lenOfPower)
    {
        ft_memset((powerTwo) + (Len->lenOfPower),'0', (Len->lenOfCurrentNbr - Len->lenOfPower));
        Len->lenOfPower += Len->lenOfCurrentNbr - Len->lenOfPower;
    }
    cpy_cur = ft_floatCpy(curretNum, Len->lenOfCurrentNbr, Len);
    cpy_power = ft_floatCpy(powerTwo, Len->lenOfPower, Len);
    ft_plus_int(cpy_cur, cpy_power, Len);
    if(ft_strlen(cpy_cur) > (Len->lenOfCurrentNbr > Len->lenOfPower ? Len->lenOfCurrentNbr - 2 : Len->lenOfPower - 2))
        curretNum[0] = *cpy_cur;
    curretNum = ft_floatHandleRes(curretNum, cpy_cur, Len->lenOfIntPart);
    printf("%s\n", curretNum);
}


int    ft_ltoa_set_piace(long long arg, char **new_res)
{
    int piece;
    int del;
    int i;

    del = 100000;
    i = 0;
    while(arg > del)
    {
        piece = (int)(arg % del);
        arg /= del;
        new_res[i] = ft_itoa(piece);
        i++;
    }
    new_res[i] = ft_itoa((int)arg);
    new_res[++i] = NULL;
    return (i);
}

void ft_ltoa(char **result, long long arg)
{
    char **new_res;
    int i;
    char *tmp = *result;

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
    i = ft_ltoa_set_piace(arg, new_res);
    while(i-- > 0)
    {
        ft_strcat(*result, new_res[i]);
        tmp = *result + 5; //без тмп не компилилось(
        ft_strdel(&(new_res[i]));
    }
    free(new_res);
}

int main()
{

    long int a = LONG_MAX;
    char *res;

    res = ft_strnew(22);
    ft_ltoa(&res, a);
    printf("%s\n", res);
    ft_strdel(&res);
//    char *curr;
//    char *float_part;
//    t_len *Len;
//
//    Len = malloc(sizeof(t_len));
//    curr = ft_strnew(100);
//    float_part = ft_strnew(100);
//    ft_strclr(curr);
//    ft_strclr(float_part);
//    Len->lenOfResult = 0;
//    Len->lenOfPower = 0;
//    Len->lenOfIntPart = 0;
//    Len->lenOfCurrentNbr = 0;
//    ft_strcpy(curr, "55555.5");
//    ft_strcpy(float_part, "100000.5");
//    ft_plus_float(curr, float_part, Len);


    return 0;
}