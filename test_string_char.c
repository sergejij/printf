#include "ft_printf.h"

static void	ft_putstrr(char const *s)
{
    int counter;

    counter = 0;
    if (s)
    {
        while (s[counter] != '\0')
        {
            ft_putchar(s[counter]);
            counter++;
        }
    }
}

int ft_is_type(char c)
{
    if (c == 's' || c == 'c' || c == 'p' || c == 'i' || c == 'd')
        return (1);
    return (0);
}

void ft_add_string(char **result, char *str_arg, t_prinlist *lst)
{
    /*if(lst->pricision)//обрезаем строку
    if(lst->width && ((lst->flag | 4) < 4)// сдвигаем влево
    // надо проверить побитовые операции какие нужны здесь -> из 000001000 получить 00000000
    if(lst->width) // сдвигаем вправо
     */
    *result = ft_strjoin(*result, str_arg);
}

int ft_analise_types(char *format, char *result, char *str_arg, t_prinlist *lst)
{
    if(*format == 's')
    {
        ft_add_string(&result, str_arg, lst);
        ft_putstrr(result);
    }
    return 1;
}
int ft_analise_flags(char *format, t_prinlist *lst)
{
    int flag = 0;
    while(!(ft_is_type(*format)))
    {
        if (*format == '#')
            flag = (flag | 1);
        if (*format == '0')
            flag = flag | 2;
        if (*format == '-')
            flag = flag | 4;
        if (*format == '+')
            flag = flag | 8;
        if (ft_isdigit(*format))//записываем ширину
            lst->width = ft_atoi(format);
        if (*format == '.')//записываем точность
            lst->pricision = ft_atoi(++format);
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
    char result[10];
    int flag;
    t_prinlist *lst;

    while(*p_apFormat)
    {
        //идем про форматирующей строке
        if (*p_apFormat == '%')
        {
            // если встречаем процент, идем анализировать наличие всех флагов и спецификаторов
            lst = (t_prinlist *)malloc(sizeof(t_prinlist));
            flag = ft_analise_flags((char *)p_apFormat, lst);
            //пропускаем все флаги(мы их записали в структуру) и идем работать с аргументом
            while(!(ft_is_type(*p_apFormat)))
                p_apFormat++;
            ft_analise_types((char *)p_apFormat, result, va_arg(ap, char*), lst);
            continue ;
        }
        p_apFormat++;
       // *result = *p_apFormat;  придумать как записывать текст до процента и после
       // result++;
    }
    return 1;
}

int main()
{
    ft_printf("%-6.7s", "12345");
}