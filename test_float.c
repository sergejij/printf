
#include "ft_printf.h"

void ft_roundering(char *currResult, size_t pricision, t_len *Len)
{
    char *rounder;
    char *tmp;
    int rounder_nbr;

    rounder_nbr = ft_checkLenOfInt(currResult) + pricision + 1;
    if(!(rounder = (char *)malloc(sizeof(char) * (pricision + 5))))
        return;
    tmp = rounder;
    ft_strcpy(rounder, "0.");
    ft_memset((tmp + 2), '0', pricision);
    tmp[pricision + 2] = '5';
    tmp[pricision + 3] = '\0';
    if(currResult[rounder_nbr - 1] == '.')
    {
        if((currResult[rounder_nbr - 2] - '0') % 2 != 0 || (currResult[rounder_nbr] - '0') >= 5)
            ft_plus_float(currResult, rounder, Len);
    }
    else
        if((currResult[rounder_nbr - 1] - '0') % 2 != 0 || (currResult[rounder_nbr] - '0') >= 5)
            ft_plus_float(currResult, rounder, Len);
}

void ft_print_bits(unsigned short a, int bits)
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

short ft_make_exponent(long double nbr)
{
    unsigned short exponent;
   // short exponet2;
    unsigned char memoryPointer;
    short *ptr;


    exponent = 0;
    memoryPointer = *((unsigned char *)&nbr + 9);
    exponent |= memoryPointer;
    exponent <<= 8;
    memoryPointer = *((unsigned char *)&nbr + 8);
    exponent |= memoryPointer;
    exponent = exponent - 16383;
    ptr = (short*)&exponent;
    return (*ptr);
}

char *ft_add_infOrNan(int sign, long double arg_double, t_prinlist *lst)
{
    char *res;

    if(!(res = ft_strnew(4)))
        exit(1);
    if ((arg_double != arg_double))
    {
        ft_strcpy(res, "nan");
        if((lst->flag & MINUS) == MINUS)
        {
            lst->flag = 0;
            lst->flag = lst->flag ^ MINUS;
        }
        else if(lst->flag)
            lst->flag = 0;
    }
    else
    {
        sign < 0 ? ft_strcpy(res, "-inf") : ft_strcpy(res, "inf");
        if((lst->flag & ZERO) == ZERO)
            lst->flag = lst->flag ^ ZERO;

    }
    return (res);
}
void ft_parse_double(char **result, long double arg_double, t_prinlist *lst)
{
    char *tmp_result = NULL;
    unsigned long mantissa = 0;
    unsigned char memoryPointer;
    short exponent = 0;
    int sign = 0;

    memoryPointer = *((unsigned char *)&arg_double + 9);
    sign = (memoryPointer >> 7)  == 0 ? 1 : -1;
    if(sign < 0)
        arg_double = -arg_double;
    mantissa = ft_make_mantissa(arg_double);
    exponent = ft_make_exponent(arg_double);
    if((lst->pricision == 0 || lst->pricision > 2000) && (lst->flag & ZERO_PRIC) != ZERO_PRIC)
        lst->pricision = 6;
    if(exponent == 16384)
        tmp_result = ft_add_infOrNan(sign, arg_double, lst);
    if(!(is_NanOrInf(tmp_result)))
        tmp_result = ft_add_double(mantissa, exponent, sign,  lst);
    ft_choice_options(result, tmp_result, lst);
}
