#include "ft_printf.h"

int ft_putchar_len(char i)
{
    ft_putchar_fd(i, 1);
    return (1);
}

t_flags ft_flags_init(void)
{
    t_flags a;

    a.type = 0;
    a.left = 0;
    a.space = 0;
    a.plus = 0;
    a.zero = 0;
    a.hash = 0;
    a.width = 0;
    a.precision = 0;
    return (a);
}

int ft_istype(char i)
{
    char    *type;
    int     index;

    type = "cspdiuxX";
    index = -1;
    while(type[++index])
    {
        if(i == type[index])
            return (1);
    }
    return (0);
}

int ft_isflag(char i)
{
    char    *flags;
    int     index;

    flags = "-+ #0";
    index = -1;
    while(flags[++index])
    {
        if(i == type[index])
            return (1);
    }
    return (0);
}

int ft_print_args(char *format, int *i, t_flags flag)
{
    int len;

    len = 0;
    if (format[*i] == '%')
        len += ft_putchar_len(format[*i]);
    (*i)++;
    return (len);
}

t_flags ft_check_wp(char *format, int *i, t_flags flag)
{
    flag.width = ft_atoi(&format[*i]);
    while (ft_isdigit(format[*i]))
        (*i)++;
    if (format[*i] == '.')
        (*i)++;
    flag.precision = ft_atoi(&format[*i]);
    while (ft_isdigit(format[*i]))
        (*i)++;
    return (flag);
}

t_flags ft_check_flags(char *format, int *i, t_flags flag)
{
    while(ft_isflag(format[++(*i)]))
    {
        if (format[*i] == '-')
            flag.left = 1;
        if (format[*i] == '+')
            flag.plus = 1;
        if (format[*i] == ' ')
            flag.space = 1;
        if (format[*i] == '#')
            flag.hash = 1;
        if (format[*i] == '0')
            flag.zero = 1;
    }
    flag = ft_check_wp(format, i, flag);
    return (flag);
}


int ft_printf(const char *format, ...)
{
    va_list args;
    t_flags flag;
    int     i;
    int     len;

    if (!format || *format == '\0')
        return (0);
    i = -1;
    len = 0;
    va_start(args, format);
    while (format[++i])
    {
        if (format[i] == '%')
        {
            flag = ft_flags_init();
            flag = ft_check_flags(format, &i, flag);
            len += ft_print_args(format, &i, flag);
        }
        else
            len += ft_putchar_len(format[i]);
    }
    va_end(args);
    return (i);
}

int main(void)
{
    printf("%10c\n", 'H');
    return (0);
}