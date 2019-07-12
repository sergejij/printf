
#include "ft_printf.h"

void    ft_calculate(int *res, char *curretNum, char *cpyPower, t_len *Len)
{
    while(*curretNum || *cpyPower)
    {
        if(*curretNum == '.' && *cpyPower == '.')
        {
            res[Len->lenOfCurrentNbr++] = '.' - '0';
            curretNum++;
            cpyPower++;
        }
        if(*curretNum && *cpyPower)
            res[Len->lenOfCurrentNbr] = (((*cpyPower++ - '0') + (*curretNum++ - '0')) + Len->flagIsFloatPart);
        else if(!(*curretNum) && *cpyPower)
            res[Len->lenOfCurrentNbr] = *cpyPower++ - '0' + Len->flagIsFloatPart;
        else
            res[Len->lenOfCurrentNbr] = *curretNum++ -'0' + Len->flagIsFloatPart;
        Len->flagIsFloatPart = 0;
        if(res[Len->lenOfCurrentNbr] > 9)
        {
            Len->flagIsFloatPart = res[Len->lenOfCurrentNbr] / 10;
            res[Len->lenOfCurrentNbr] %= 10;
        }
        Len->lenOfCurrentNbr++;
    }
    if (Len->flagIsFloatPart)
        res[Len->lenOfCurrentNbr++] = Len->flagIsFloatPart;
    Len->flagIsFloatPart = 0;
}

void ft_plus_int(char *curretNum, char *cpyPower, t_len *Len)
{
    int *res;
    char *tmp_curr;

    Len->lenOfCurrentNbr = ft_strlen(curretNum) > ft_strlen(cpyPower) ? ft_strlen(curretNum) : ft_strlen(cpyPower);
    res = malloc(sizeof(int) * (Len->lenOfCurrentNbr + 1));
    tmp_curr = curretNum;
    Len->lenOfCurrentNbr = 0;
    ft_strrev(curretNum);
    ft_strrev(cpyPower);
    Len->flagIsFloatPart = 0;
    ft_calculate(res, tmp_curr, cpyPower, Len);
    Len->lenOfResult = 0;
    while(Len->lenOfCurrentNbr--)
    {
        curretNum[Len->lenOfResult] = (char) (res[Len->lenOfCurrentNbr] + '0');
        Len->lenOfResult++;
    }
    curretNum[Len->lenOfResult] = '\0';
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



void ft_binary_to_decimal(unsigned long mantissa, short exponent, char *int_part, char *float_part, t_len *Len)
{
    unsigned long oneLeftOne;
    char *currNum;

    oneLeftOne = 0x8000000000000000;
    while(mantissa && exponent >= 0)
    {
        if((mantissa & oneLeftOne) == oneLeftOne)
        {
            currNum = findPower(exponent);
            ft_plus_int(int_part, currNum, Len);
        }
        exponent--;
        mantissa <<= 1;
    }
    while (mantissa)
    {
        if((mantissa & oneLeftOne) == oneLeftOne)
        {
            currNum = findPower(exponent);
            ft_plus_float(float_part, currNum, Len);
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
    exponent++;
    ft_binary_to_decimal(mantissa, exponent, int_part, float_part, Len);
    ft_pasteIntPlusFloat(int_part, float_part, lst->pricision, Len);
    if(sign < 0)
        ft_add_neg_sign(&int_part, &float_part);
    return (int_part);
}