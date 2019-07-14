
#include "ft_printf.h"

int g_sym_count = 0;

int ft_is_type(char *c, t_prinlist *lst)
{
    if (*c == 'x')
        lst->h = x;
    if (*c == 's' || *c == 'c' || *c == 'p' || *c == 'i' || *c == 'd' || *c == 'i'
    || *c == '%' || *c == 'x' || *c == 'X' || *c == 'o' || *c == 'u' || *c == 'f')
        return (1);
    else if (*c == 'h' && lst->modifier != HH)
    {
        c++;
        if (*c =='h')
            lst->modifier = HH;
        else
            lst->modifier = H;
    }
    else if (*c == 'l' && lst->modifier != LL)
    {
        c++;
        if (*c =='l')
            lst->modifier = LL;
        else
            lst->modifier = L_ONE;
    }
    return (0);
}

void    ft_digit_type(char **result, va_list ap, t_prinlist *lst)
{
    if (lst->modifier == L_ONE || lst->modifier == LL)
        ft_long_to_str(result, va_arg(ap, long long int), lst);
    else
        ft_add_integer(result, va_arg(ap, int), lst);
}

void    ft_hex_type(char *format, char **result, va_list ap, t_prinlist *lst)
{
    if (lst->modifier == L_ONE)//позже убрать второй Л мы используем только 1
        ft_add_uhex_str(result, va_arg(ap, unsigned long int), lst, *format);
    else if (lst->modifier == LL)
        ft_add_uhex_str(result, va_arg(ap, unsigned long long int), lst, *format);
    else
        ft_add_hex_str(result, va_arg(ap, int), lst, *format);
}

void    ft_octal_type(char **result, va_list ap, t_prinlist *lst)
{
    if (lst->modifier == L_ONE || lst->modifier == LL)
        ft_add_octal_u(result, va_arg(ap, unsigned long long), lst);
    else
        ft_add_octal(result, va_arg(ap, unsigned int), lst);
}

void    ft_unsigned_type(char **result, va_list ap, t_prinlist *lst)
{
    if (lst->modifier == L_ONE)
        ft_add_unsigned(result, va_arg(ap, unsigned long int), lst);
    else if (lst->modifier == LL)
        ft_add_unsigned(result, va_arg(ap, unsigned long long int), lst);
    else
        ft_add_unsigned(result, va_arg(ap, unsigned int), lst);
}

void ft_analise_types(char *format, char *result, va_list ap, t_prinlist *lst)
{
    if(*format == 'c')
        ft_add_char(&result, va_arg(ap, int), lst);
    else if (*format == 's')
        result = ft_add_string(&result, va_arg(ap, char*), lst, 1);
    else if (*format == 'p')
        ft_add_pointer(&result, va_arg(ap, unsigned long), lst);
    else if (*format == 'd' || *format == 'i')
        ft_digit_type(&result, ap, lst);
    else if(*format == 'x' || *format == 'X')
        ft_hex_type(format, &result, ap, lst);
    else if(*format == 'o')
        ft_octal_type(&result, ap, lst);
    else if(*format == 'u')
        ft_unsigned_type(&result, ap, lst);
    else if(*format == 'f')
        ft_parse_double(&result, va_arg(ap, double), lst);
    else if (*format == '%')
        ft_add_char(&result, '%', lst);
    if(!result)
        result = ft_strdup("(null)");
    ft_putstr(result);
    g_sym_count += ft_strlen(result);
}

void ft_delete_excess_flags(t_prinlist *lst)
{
    if ((lst->flag & ZERO_PRIC) == ZERO_PRIC && (lst->flag & ZERO) == ZERO)
        lst->flag = lst->flag ^ ZERO;
    if ((lst->flag & PLUS) == PLUS && (lst->flag & SPACE) == SPACE)
        lst->flag = lst->flag ^ SPACE;
    if ((lst->flag & MINUS) == MINUS && (lst->flag & ZERO) == ZERO)
        lst->flag = lst->flag ^ ZERO;
    if ((lst->flag & HASH) == HASH && (lst->flag & ZERO) == ZERO && lst->pricision)
        lst->flag = lst->flag ^ ZERO;
}

void    ft_analise_flags3(char **format, t_prinlist *lst, unsigned int *flag)
{
    if (ft_isdigit(**format))
    {
        lst->width = (size_t)ft_atoi(*format);
        while(ft_isdigit(**format))
            (*format)++;
    }
    else if (**format == '.')
    {
        lst->pricision = (size_t)ft_atoi(++(*format));
        if (lst->pricision == 0)
            *flag = *flag | ZERO_PRIC;
        while(ft_isdigit(**format))
            (*format)++;
    }
}

int ft_analise_flags2(char *format, unsigned int *flag)
{
    if (*format == '#')
        *flag = (*flag | HASH);
    else if (*format == '0')
        *flag = *flag | ZERO;
    else if (*format == '-')
        *flag = *flag | MINUS;
    else if (*format == '+')
        *flag = *flag | PLUS;
    else if (*format == ' ')
        *flag = *flag | SPACE;
    else
        return (0);
    return (1);
    
}

int ft_analise_flags(char *format, t_prinlist *lst)
{
    unsigned int flag;
    
    flag = 0;
    format++;
    while(*format && !(ft_is_type(format, lst)))
    {
        if (ft_analise_flags2(format, &flag))
            ;
        else if (ft_isdigit(*format) || *format == '.')
        {
            ft_analise_flags3(&format, lst, &flag);
            continue ;
        }        
        format++;
    }
    lst->flag = flag;
    ft_delete_excess_flags(lst);
    return (flag);
}

t_prinlist *make_struct_for_flags(char *format)
{
    t_prinlist *new;

    new = NULL;
    if(!(new = (t_prinlist *)malloc(sizeof(t_prinlist))))
        return  (NULL);
    new->pricision = 0;
    new->width = 0;
    new->modifier = 0;
    new->flag = 0;
    new->len = 0;
    ft_analise_flags(format, new);
    return  (new);

}

void ft_free_result_and_lst(char **result, t_prinlist **lst)
{
    if(*result)
        ft_strdel(&(*result));
    free(*lst);
    *lst = NULL;
}

int ft_printf(const char *apformat, ...)
{
    va_list ap;         //указатель va_list
    va_start(ap, apformat);    // устанавливаем указатель
    const char *p_apFormat = apformat;
    t_prinlist *lst;
    char *tmp;
    char *result;

    result = NULL;
    tmp = NULL;
    lst = NULL;
    while(*p_apFormat)
    {
        //идем про форматирующей строке
        if (*p_apFormat == '%')
        {
            result = (char *)malloc(sizeof(char) * 10000);
            ft_strclr(result);
            tmp = result;
            // делаем структуру:
            lst = make_struct_for_flags((char *)p_apFormat);
            p_apFormat++;
            while(!(ft_is_type((char*)p_apFormat, lst)))
                p_apFormat++;
            ft_analise_types((char*)p_apFormat, result, ap, lst);
            p_apFormat++; //пропускам букву (s / d/ i и тд)
            ft_free_result_and_lst(&result, &lst);
            continue ;
        }
        else
        {
            //печатаем все что есть в форматирующей строке (кроме аргументов, их мы пропустили)
            //надо считывать в буфер и печатать сразу блоками
            write(1, p_apFormat, 1);
            g_sym_count++;
        }
        p_apFormat++;
    }
    return (g_sym_count);
}
