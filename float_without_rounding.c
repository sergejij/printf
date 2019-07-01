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
    int *res;
    char *tmp;
    int len;
    int flag;

    len = ft_strlen(current_power);
    res = (int *)malloc(sizeof(int) * len);
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
    ft_handle_result(len, res, current_power);
    return (current_power);
}

char *findPower(int power)
{
    char posPow[] = "2";
    char negPow[] = "00000000000000000000000082718061255302767487140869206996285356581211090087890625";
    char *result;
    char *tmp;

    tmp = NULL;
    result = (char *)malloc(sizeof(char) * 81);
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
   ft_strclr(curretNum);
    while(Len->lenOfCurrentNbr--)
    {
        curretNum[Len->lenOfResult] = (char) (res[Len->lenOfCurrentNbr] + '0');
        Len->lenOfResult++;
    }
    curretNum[Len->lenOfResult] = '\0';
}

void ft_plus_float(char *curretNum, char *powerTwo, t_len *Len)
{
    char *cpy_cur = NULL;
    char *cpy_power = NULL;

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
    cpy_cur = ft_strsub(curretNum, 2, Len->lenOfCurrentNbr - 2);
    cpy_power = ft_strsub(powerTwo, 2, Len->lenOfPower - 2);
    ft_plus_int(cpy_cur, cpy_power, Len);
    if(ft_strlen(cpy_cur) > (Len->lenOfCurrentNbr > Len->lenOfPower ? Len->lenOfCurrentNbr - 2 : Len->lenOfPower - 2))
        curretNum[0] = *cpy_cur;
    ft_strcpy(&(curretNum[2]), &(cpy_cur[0]));
    Len->lenOfCurrentNbr = ft_strlen(cpy_cur) - 1;
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

char *ft_add_double(unsigned long mantissa, short exponent)
{
    unsigned long cpyMantissa = mantissa;
    unsigned long oneLeftOne = 0x8000000000000000;
    char *int_part;
    char *float_part;
    char *currNum;
    t_len *Len;

    Len = malloc(sizeof(t_len));
    int_part = ft_strnew(100);
    float_part = ft_strnew(100);
    ft_strclr(int_part);
    ft_strclr(float_part);
    Len->lenOfResult = 0;
    Len->lenOfPower = 0;
    Len->lenOfCurrentNbr = 0;
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
    if((*float_part))
    {
        currNum = ft_strsub(float_part, 0, 1);
        ft_plus_int(int_part, currNum, Len);
        int_part[Len->lenOfResult] = '.';
        ft_strcat(int_part, float_part + 2);
    }
    return (int_part);
}

unsigned long ft_make_mantissa(long double nbr)
{
    unsigned long mantissa;
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

void ft_parse_double(char **result, long double arg_double)
{
    unsigned long mantissa = 0;
    unsigned char memoryPointer;
    short exponent = 0;
    int sign = 0;

    //определяем знак
    memoryPointer = *((unsigned char *)&arg_double + 9);
    sign = (memoryPointer >> 7)  == 0 ? 1 : -1;
    if(sign < 0)
        arg_double = -arg_double;

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

    // все печатаем
   /* ft_putchar('\n');
    ft_print_bits(mantissa, 64);
    ft_putchar('\n');
    ft_print_bits(exponent, 32);
    ft_putchar('\n');
    ft_putnbr(exponent);
    ft_putchar('\n');*/
    *result = ft_add_double(mantissa, exponent);
 //   printf("my nbr is       %s\n", result);
 //   printf("nbr original is %.60Lf", arg_double);
}
