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
    t_len *Len;

    Len = malloc(sizeof(t_len));
    Len->lenOfResult = 0;
    Len->lenOfPower = 0;
    Len->lenOfCurrentNbr = 0;
    Len->lenOfIntPart = 0;
    Len->flagIsFloatPart = 0;
    return (Len);
}

void ft_plus_float(char *curretNum, char *powerTwo, t_len *Len)
{
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
}