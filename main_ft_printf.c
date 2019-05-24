
#include "ft_printf.h"

int g_sym_count = 0;

int ft_is_type(char c)
{
    if (c == 's' || c == 'c' || c == 'p' || c == 'i' || c == 'd')
        return (1);
    return (0);
}

void ft_analise_types(char *format, char *result, va_list ap, t_prinlist *lst)
{
    if (*format == 's')
        result = ft_add_string(result, va_arg(ap, char*), lst);
    else if (*format == 'd')
        ft_add_integer(&result, va_arg(ap, int), lst);
    else if (*format == 'p')
        ft_add_pointer(&result, va_arg(ap, unsigned long), lst);
    ft_putstr(result);
}

int ft_analise_flags(char *format, t_prinlist *lst)
{
    int flag = 0;
    format++;
    while(*format && !(ft_is_type(*format)))
    {
        if (*format == '#')
            flag = (flag | HASH);
        else if (*format == '0')
            flag = flag | ZERO;
        else if (*format == '-')
            flag = flag | MINUS;
        else if (*format == '+')
            flag = flag | PLUS;
        else if (ft_isdigit(*format))//записываем ширину
        {
            lst->width = ft_atoi(format);
            while(ft_isdigit(*format))
                format++;
            continue ;
        }
        else if (*format == '.')//записываем точность
        {
            lst->pricision = ft_atoi(++format);
            while(ft_isdigit(*format))
                format++;
            continue ;
        }
        format++;
    }
    lst->flag = flag;
    return (flag);
}

int ft_printf(const char *apformat, ...)
{
    va_list ap;         //указатель va_list | poit on next unnamed argument
    va_start(ap, apformat);    // устанавливаем указатель
    const char *p_apFormat = apformat;
    int flag;
    t_prinlist *lst;

    char *result = (char *)malloc(sizeof(char) * 100);
    while(*p_apFormat)
    {
        //идем про форматирующей строке
        if (*p_apFormat == '%')
        {

            // делаем структуру:
            lst = (t_prinlist *)malloc(sizeof(t_prinlist));
            lst->pricision = 0;
            lst->width = 0;

            //идем анализировать наличие всех флагов и спецификаторов
            flag = ft_analise_flags((char *)p_apFormat, lst);

            //пропускаем все флаги(мы их записали в структуру) и идем работать с аргументом
            while(!(ft_is_type(*p_apFormat)))
                p_apFormat++;
            ft_analise_types((char *)p_apFormat, result + ft_strlen(result), ap, lst);
            p_apFormat++; //пропускам букву (s / d/ i и тд)
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
    return g_sym_count;
}

int main()
{
    int i = 5;
    char *s = (char*)malloc(sizeof(4));
    s = "abc";
    float g = 123.223;
   // int *a = &i;
    unsigned long a = 9223372036854775807;
    //printf("\n%d", ft_printf("test %s", "huest"));
    ft_printf("%s%d%40p", s, i, &s);
    printf("\n%s%d%40p", s, i, &s);
    return  0;
}