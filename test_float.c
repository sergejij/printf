
#include "ft_printf.h"



int is_NanOrInf(char *dbl)
{
    if(!dbl)
        return (0);
    else if((ft_strcmp(dbl, "inf")) && (ft_strcmp(dbl, "-inf")) && (ft_strcmp(dbl, "nan")))
        return (0);
    else
        return (1);
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
    if((currResult[pricision + 1] - '0') % 2 != 0 || (currResult[pricision + 2] - '0') >= 5)
        ft_plus_float(currResult, rounder, Len);
}


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

unsigned short ft_make_exponent(long double nbr)
{
    unsigned short exponent;
    unsigned char memoryPointer;

    exponent = 0;
    memoryPointer = *((unsigned char *)&nbr + 9);
    exponent |= memoryPointer;
    exponent <<= 8;
    memoryPointer = *((unsigned char *)&nbr + 8);
    exponent |= memoryPointer;
    exponent ^= 16384;
    if(exponent == 32767)
        exponent = -1;
    return (exponent);
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
    unsigned short exponent = 0;
    int sign = 0;

    memoryPointer = *((unsigned char *)&arg_double + 9);
    sign = (memoryPointer >> 7)  == 0 ? 1 : -1;
    if(sign < 0)
        arg_double = -arg_double;
    mantissa = ft_make_mantissa(arg_double);
    exponent = ft_make_exponent(arg_double);
    if(lst->pricision == 0 && (lst->flag & ZERO_PRIC) != ZERO_PRIC)
        lst->pricision = 6;
    if(exponent == 16383)
        tmp_result = ft_add_infOrNan(sign, arg_double, lst);
    if(!(is_NanOrInf(tmp_result)))
        tmp_result = ft_add_double(mantissa, exponent, sign,  lst);
    if(tmp_result && (lst->flag & ZERO_PRIC) == ZERO_PRIC && (lst->flag & HASH) != HASH && !(is_NanOrInf(tmp_result)))
            tmp_result[ft_checkLenOfInt(tmp_result)] = '\0';
    lst->pricision = 0;
    if(lst->flag || lst->width)
        ft_transform_int_result(result, tmp_result, lst);
    else
            ft_strcpy(*result, tmp_result);
}
