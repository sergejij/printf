//
// Created by Asafoetida Estella on 2019-06-06.
//
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"


typedef struct s_len{
    size_t lenOfCurrentNbr;
    size_t lenOfResult;
    size_t lenOfPower;
    size_t lenOfIntPart;
    int flagIsFloatPart;
} t_len;


void ft_handle_result(int len, int *int_res, char *result)
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

char *ft_makePower(char *current_power)
{
    int *res = NULL;
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
    res[len] = '\0';
    ft_handle_result(len, res, current_power);
    return (current_power);
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
    result = (char *)malloc(sizeof(char) * 100);
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
        ft_strdel(&tmp);
    }
    return (result);
}

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
        if(*tmp_curr == '.' && *cpyPower == '.')
        {
            res[Len->lenOfCurrentNbr++] = '.' - '0';
            tmp_curr++;
            cpyPower++;
        }
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
        res[Len->lenOfCurrentNbr++] = flag;
    Len->lenOfResult = 0;
   // ft_strclr(curretNum);
    while(Len->lenOfCurrentNbr--)
    {
        curretNum[Len->lenOfResult] = (char) (res[Len->lenOfCurrentNbr] + '0');
        Len->lenOfResult++;
    }
    curretNum[Len->lenOfResult] = '\0';
}

size_t ft_checkLenOfInt(char *nbr)
{
    size_t i;

    i = 0;
    while(nbr[i] != '.')
        i++;
    return (i);
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
       // ft_strclr(tmp);
    }
    else if (intPowLen > intCurrLen)
    {
        ft_memset(tmp, '0', intPowLen - intCurrLen);
        ft_strcat(tmp, curretNum);
        ft_strcpy(curretNum, tmp);
       // ft_strclr(tmp);
    }
}

void ft_plus_float(char *curretNum, char *powerTwo, t_len *Len)
{
   // char *cpy_cur = NULL;
   // char *cpy_power = NULL;

    if(!(*curretNum))
    {
        ft_strcpy(curretNum, powerTwo);
        return;
    }
    ft_makeEven(curretNum, powerTwo);
    Len->lenOfCurrentNbr = ft_strlen(curretNum);
    Len->lenOfPower = ft_strlen(powerTwo);

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
    Len->flagIsFloatPart = 1;
    ft_plus_int(curretNum, powerTwo, Len);
    if(ft_strlen(curretNum) > (Len->lenOfCurrentNbr > Len->lenOfPower ? Len->lenOfCurrentNbr - 2 : Len->lenOfPower - 2))
        curretNum[0] = *curretNum;
   // curretNum = ft_floatHandleRes(curretNum, cpy_cur, Len->lenOfIntPart);

}


void ft_print_bits(unsigned long a, int bits)
{
    unsigned long i;

    i = 1;
    i <<= (bits - 1);
    while(bits-- > 0)
    {
        ft_putchar(a & i ? '1' : '0');
        a <<= 1;
        if (!(bits % 4))
            ft_putchar(' ');
    }
}
void ft_roundering(char *currResult, size_t pricision, t_len *Len)
{
    char *rounder;
    char *tmp;

    if(!(rounder = (char *)malloc(sizeof(char) * (pricision + 5))))
        return;
    tmp = rounder;
    ft_strcpy(rounder, "0.");
    ft_memset((tmp + 2), '0', pricision);
    tmp[pricision + 2] = '5';
    tmp[pricision + 3] = '\0';
 printf("%s\n", rounder);
    if((currResult[pricision + 1] - '0') % 2 != 0 || (currResult[pricision + 2] - '0') >= 5)
        ft_plus_float(currResult, rounder, Len);
}

void ft_pasteIntPlusFloat(char *int_part, char *float_part, size_t pricision, t_len *Len)
{
    char *currNum;
    int len_int_part;

    currNum = NULL;
    len_int_part = 0;
    if(!(*float_part))
    {
        ft_strcpy(float_part, "0.");
        ft_memset(float_part + 2, '0', pricision);
    }
    currNum = ft_strsub(float_part, 0, 1);
    ft_plus_int(int_part, currNum, Len);
    int_part[Len->lenOfResult] = '.';
    len_int_part = Len->lenOfResult;
    ft_strcat(int_part, float_part + ft_checkLenOfInt(float_part) + 1);
    ft_roundering(int_part, pricision, Len);
    int_part[len_int_part + pricision + 1] = '\0';
}

char *ft_add_double(unsigned long mantissa, short exponent, t_prinlist *lst)
{
    unsigned long cpyMantissa = mantissa;
    unsigned long oneLeftOne = 0x8000000000000000;
    char *int_part;
    char *float_part;
    char *currNum;
    t_len *Len;
    Len = malloc(sizeof(t_len));
    int_part = ft_strnew(300);
    float_part = ft_strnew(300);
    //ft_strclr(int_part);
    //ft_strclr(float_part);
    Len->lenOfResult = 0;
    Len->lenOfPower = 0;
    Len->lenOfCurrentNbr = 0;
    Len->lenOfIntPart = 0;
    Len->flagIsFloatPart = 0;
    exponent++;
    while(cpyMantissa && exponent >= 0)
    {
        if((cpyMantissa & oneLeftOne) == oneLeftOne)
        {
            currNum = findPower(exponent);
            ft_plus_int(int_part, currNum, Len);
            ft_strdel(&currNum);
        }
        exponent--;
        cpyMantissa <<= 1;
    }
    while (cpyMantissa)
    {
        if((cpyMantissa & oneLeftOne) == oneLeftOne)
        {
            currNum = findPower(exponent);
            ft_plus_float(float_part, currNum, Len);
          //  printf("exp = %d\n  power = %s\n float = %s\n", exponent, cpy_of_power, float_part);
            ft_strdel(&currNum);
        }
        cpyMantissa <<= 1;
        exponent--;
    }
    //if(lst->pricision != 0 || (lst->flag & HASH) == HASH)
    ft_pasteIntPlusFloat(int_part, float_part, lst->pricision, Len);
    return (int_part);
}

unsigned long ft_make_mantissa(long double nbr)
{
    unsigned long  mantissa;
    unsigned char memoryPointer;
    int bits;
    int byte;
    unsigned long g;

    mantissa = 0;
    memoryPointer = 0;
    bits = 0;
    byte = 0;
    g = 1;
    while(byte < 8)
    {
        bits = 0;
        memoryPointer = *((unsigned char *)&nbr + byte);
        while(bits++ < 8)
        {
            if (memoryPointer & 1 && byte * 8 + bits <= 64)
                mantissa |= g;
            memoryPointer >>= 1;
            if (byte * 8 + bits <= 64)
                g <<= 1;
        }
        byte++;
    }
    return (mantissa);
}

void ft_parse_double(char **result, long double arg_double, t_prinlist *lst)
{
    char *tmp_result;
    unsigned long mantissa = 0;
    unsigned char memoryPointer;
    unsigned short exponent = 0;
    int sign = 0;

    //определяем знак
    memoryPointer = *((unsigned char *)&arg_double + 9);
    sign = (memoryPointer >> 7)  == 0 ? 1 : -1;
    if(sign < 0)
    {
        arg_double = -arg_double;
        **result = '-';
    }
    //выделяем мантиссу
    mantissa = ft_make_mantissa(arg_double);

    //выделяем экпаненту
    memoryPointer = *((unsigned char *)&arg_double + 9);
    exponent |= memoryPointer;
    exponent <<= 8;
    memoryPointer = *((unsigned char *)&arg_double + 8);
    exponent |= memoryPointer;
    exponent ^= 16384;
    if(exponent == 32767)
        exponent = -1;

    if(exponent == 16383)
    {
       /* if (mantissa > 9223372036854775807) {
            ft_strcpy(*result, "inf");
        }
        else*/
            ft_strcpy(*result, "nan");
        return;
    }
    if(lst->pricision == 0 && (lst->flag & ZERO_PRIC) != ZERO_PRIC)
        lst->pricision = 6;
    tmp_result = ft_add_double(mantissa, exponent, lst);
    if (sign < 0)
        ft_strcpy((*result) + 1, tmp_result);
    else
        ft_strcpy(*result, tmp_result);
   // ft_strdel(&tmp_result);

    lst->pricision = 0;
    if(lst->flag || lst->width)
        ft_transform_int_result(result, lst);
    if ((lst->flag & SPACE) == SPACE && (lst->flag & PLUS) != PLUS && arg_double >=0 && lst->width <= lst->len)
        *result = ft_strjoin(" ", *result);
   // if ((lst->flag & HASH) == HASH)

}
