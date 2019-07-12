
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
void	*ft_memset1(void *b, int c, size_t len)
{
    unsigned char new_c;
    unsigned char *new_b;

    new_c = (unsigned char)c;
    new_b = (unsigned char *)b;
    while (len > 0)
    {
        *new_b = new_c;
        new_b++;
        len--;
    }
    *new_b = '\0';
    return (b);
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
        ft_memset1(tmp, '0', intCurrLen - intPowLen);
        ft_strcat(tmp, powerTwo);
        ft_strcpy(powerTwo, tmp);
         ft_strclr(tmp);
    }
    else if (intPowLen > intCurrLen)
    {
        ft_memset(tmp, '0', intPowLen - intCurrLen);
        ft_strcat(tmp, curretNum);
        ft_strcpy(curretNum, tmp);
         ft_strclr(tmp);
    }
}

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

void ft_plus_int(char *curretNum, char *cpyPower, t_len *Len)
{
    char *tmp_curr = NULL;
    int flag;
    int *res = NULL;

    tmp_curr = curretNum;
    Len->lenOfCurrentNbr = ft_strlen(curretNum) > ft_strlen(cpyPower) ? ft_strlen(curretNum) : ft_strlen(cpyPower);
    flag = 0;

    res = malloc(sizeof(int) * (Len->lenOfCurrentNbr + 1));
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
  //  free(res);
    res = NULL;
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
  //  free(res);
    res = NULL;
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
//        while(power++ < 0)
//            ft_makePower(result);
            while(power-- > -80)
                ft_makePower(result);
        tmp = result;
        result = ft_strjoin("0.", tmp);
//        if (tmp)
//            ft_strdel(&tmp);
    }
//    ft_strdel(&posPow);
//    ft_strdel(&negPow);
    return (result);
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

char *ft_add_double(unsigned long mantissa, short exponent, int sign, t_prinlist *lst)
{
    unsigned long cpyMantissa = mantissa;
    unsigned long oneLeftOne = 0x8000000000000000;
    char *int_part;
    char *float_part;
    char *currNum;

    t_len *Len;
    Len = malloc(sizeof(t_len));
    int_part = ft_strnew(2000);
    float_part = ft_strnew(2000);
    //ft_strclr(int_part);
    //ft_strclr(float_part);
    Len->lenOfResult = 0;
    Len->lenOfPower = 0;
    Len->lenOfCurrentNbr = 0;
    Len->lenOfIntPart = 0;
    Len->flagIsFloatPart = 0;
    exponent++;
    // ft_print_bits(cpyMantissa, 64);
    while(cpyMantissa && exponent >= 0)
    {
//             ft_print_bits(cpyMantissa, 64);
//             write(1, "\n", 1);
        if((cpyMantissa & oneLeftOne) == oneLeftOne)
        {
            currNum = findPower(exponent);
            ft_plus_int(int_part, currNum, Len);
//            if(currNum)
//                ft_strdel(&currNum);
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
//            if(currNum)
//                ft_strdel(&currNum);
        }
        cpyMantissa <<= 1;
        exponent--;
    }
    //if(lst->pricision != 0 || (lst->flag & HASH) == HASH)

    ft_pasteIntPlusFloat(int_part, float_part, lst->pricision, Len);
    if(sign < 0)
        ft_add_neg_sign(&int_part, &float_part);
//    if(currNum)
//        ft_strdel(&currNum);
//    if(float_part)
//        ft_strdel(&float_part);
    return (int_part);
}