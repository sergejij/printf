
#include "ft_printf.h"

void    ft_calculate(int *res, char *cur_num, char *cpy_pow, t_len *len_l)
{
    while(*cur_num || *cpy_pow)
    {
        if(*cur_num == '.' && *cpy_pow == '.')
        {
            res[len_l->lenOfCurrentNbr++] = '.' - '0';
            cur_num++;
            cpy_pow++;
        }
        if(*cur_num && *cpy_pow)
            res[len_l->lenOfCurrentNbr] = (((*cpy_pow++ - '0') + (*cur_num++ - '0')) + len_l->flagIsFloatPart);
        else if(!(*cur_num) && *cpy_pow)
            res[len_l->lenOfCurrentNbr] = *cpy_pow++ - '0' + len_l->flagIsFloatPart;
        else
            res[len_l->lenOfCurrentNbr] = *cur_num++ -'0' + len_l->flagIsFloatPart;
        len_l->flagIsFloatPart = 0;
        if(res[len_l->lenOfCurrentNbr] > 9)
        {
            len_l->flagIsFloatPart = res[len_l->lenOfCurrentNbr] / 10;
            res[len_l->lenOfCurrentNbr] %= 10;
        }
        len_l->lenOfCurrentNbr++;
    }
    if (len_l->flagIsFloatPart)
        res[len_l->lenOfCurrentNbr++] = len_l->flagIsFloatPart;
    len_l->flagIsFloatPart = 0;
}

void ft_plus_int(char *cur_num, char *cpy_pow, t_len *len_l)
{
    int *res;
    char *tmp_curr;
    char *tmp_power;

    len_l->lenOfCurrentNbr = ft_strlen(cur_num) > ft_strlen(cpy_pow) ? ft_strlen(cur_num) : ft_strlen(cpy_pow);
    res = malloc(sizeof(int) * (len_l->lenOfCurrentNbr + 1));
    tmp_curr = cur_num;
    tmp_power = cpy_pow;
    len_l->lenOfCurrentNbr = 0;
    ft_strrev(cur_num);
    ft_strrev(tmp_power);
    len_l->flagIsFloatPart = 0;
    ft_calculate(res, tmp_curr, tmp_power, len_l);
    len_l->lenOfResult = 0;
    while(len_l->lenOfCurrentNbr--)
    {
        cur_num[len_l->lenOfResult] = (char) (res[len_l->lenOfCurrentNbr] + '0');
        len_l->lenOfResult++;
    }
    cur_num[len_l->lenOfResult] = '\0';
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
    int_part[ft_checkLenOfInt(int_part) + pricision + 1] = '\0';
}



void ft_binary_to_decimal(unsigned long mantissa, short exponent, char *int_part, char *float_part, t_len *len_l)
{
    unsigned long oneLeftOne;
    char *currNum;

    oneLeftOne = 0x8000000000000000;
    while(mantissa && exponent >= 0)
    {
        if((mantissa & oneLeftOne) == oneLeftOne)
        {
            currNum = findPower(exponent);
            ft_plus_int(int_part, currNum, len_l);
        }
        exponent--;
        mantissa <<= 1;
    }
    while (mantissa)
    {
        if((mantissa & oneLeftOne) == oneLeftOne)
        {
            currNum = findPower(exponent);
            ft_plus_float(float_part, currNum, len_l);
        }
        mantissa <<= 1;
        exponent--;
    }
}

char *ft_add_double(unsigned long mantissa, short exponent, int sign, t_prinlist *lst)
{

    char *int_part;
    char *float_part;
    t_len *Len;

    Len = ft_make_len_struct();
    int_part = ft_strnew(2000);
    float_part = ft_strnew(2000);

    ft_binary_to_decimal(mantissa, exponent, int_part, float_part, Len);
    ft_pasteIntPlusFloat(int_part, float_part, lst->pr, Len);
    if(sign < 0)
        ft_add_neg_sign(&int_part, &float_part);
    return (int_part);
}