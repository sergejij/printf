
#include "ft_printf.h"

int g_sym_count = 0;


int ft_is_type(char *c, t_prinlist *lst)
{
    if (*c == 's' || *c == 'c' || *c == 'p' || *c == 'i' || *c == 'd'
    || *c == '%' || *c == 'x' || *c == 'X' || *c == 'o')
        return (1);
    else if(*c == 'h' && lst->modifier != HH)
    {
        c++;
        if(*c =='h')
            lst->modifier = HH;
        else
            lst->modifier = H;
    }
    else if(*c == 'l' && lst->modifier != LL)
    {
        c++;
        if(*c =='l')
            lst->modifier = LL;
        else
            lst->modifier = L_ONE;
    }
    return (0);
}

void ft_analise_types(char *format, char *result, va_list ap, t_prinlist *lst) //    а где инт вообще?
{

    if(*format == 'c')
        ft_add_char(&result, va_arg(ap, int), lst);
    else if (*format == 's')
        result = ft_add_string(result, va_arg(ap, char*), lst, 1);
    else if (*format == 'p')
        ft_add_pointer(&result, va_arg(ap, unsigned long), lst);
    else if (*format == 'd')
        ft_add_integer(&result, va_arg(ap, int), lst);
    else if(*format == 'x' || *format == 'X')
        ft_add_hex(&result, va_arg(ap, int), lst, *format);
    else if(*format == 'o')
        ft_add_octal(&result, va_arg(ap, int), lst);
    else if (*format == '%')
        ft_add_char(&result, '%', lst);
    if(!result)
        result = ft_strdup("(null)");
    ft_putstr(result);
    g_sym_count += ft_strlen(result);

}

int ft_analise_flags(char *format, t_prinlist *lst)
{
    int flag = 0;
    format++;
    while(*format && !(ft_is_type(format, lst)))
    {
        if (*format == '#')
            flag = (flag | HASH);
        else if (*format == '0')
            flag = flag | ZERO;
        else if (*format == '-')
            flag = flag | MINUS;
        else if (*format == '+')
            flag = flag | PLUS;
        else if (*format == ' ')
            flag = flag | SPACE;
        else if (ft_isdigit(*format))//записываем ширину
        {
            lst->width = (size_t)ft_atoi(format);
            while(ft_isdigit(*format))
                format++;
            continue ;
        }
        else if (*format == '.')//записываем точность
        {
            lst->pricision = (size_t)ft_atoi(++format);
            while(ft_isdigit(*format))
                format++;
            continue ;
        }
        format++;
    }
    lst->flag = flag;
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
    ft_analise_flags(format, new);
    return  (new);

}

int ft_printf(const char *apformat, ...)
{
    va_list ap;         //указатель va_list | poit on next unnamed argument
    va_start(ap, apformat);    // устанавливаем указатель
    const char *p_apFormat = apformat;
    t_prinlist *lst;
    char *tmp;

    char *result;
    while(*p_apFormat)
    {
        //идем про форматирующей строке
        if (*p_apFormat == '%')
        {
            result = (char *)malloc(sizeof(char) * 100);
            ft_strclr(result);
            tmp = result;
            // делаем структуру:
            lst = make_struct_for_flags((char *)p_apFormat);
            p_apFormat++;
            while(!(ft_is_type((char*)p_apFormat, lst)))
                p_apFormat++;
            ft_analise_types((char*)p_apFormat, result + ft_strlen(result), ap, lst);
            p_apFormat++; //пропускам букву (s / d/ i и тд)
            free(lst);
            ft_strdel(&tmp);
            continue ;
        }
        else
        {
            //печатаем все что есть в форматирующей строке (кроме аргументов, их мы пропустили)
            write(1, p_apFormat, 1);
            g_sym_count++;
        }
        p_apFormat++;
    }
    return (g_sym_count);
}
