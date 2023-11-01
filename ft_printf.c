#include "ft_printf.h"

int ft_putchar_len(char i)
{
    ft_putchar_fd(i, 1);
    return (1);
}

int ft_putstr_len(char *i)
{
    int len;

    len = -1;
    while (i[++len])
        ft_putchar_len(i[len]);
    return ((int) ft_strlen(i));
}

int ft_putpad_len(char i, t_flags flag)
{
    int len;

    len = 0;
    while(flag.width > 0)
    {
        len += ft_putchar_len(i);
        flag.width--;
    }
    return(len);
}

int ft_print_char(char i, t_flags flag)
{
    int len;

    len = 0;
    flag.width--;
    if (!flag.left)
    {
        len += ft_putpad_len(' ', flag);
        len += ft_putchar_len(i);
    }
    else
    {
        len += ft_putchar_len(i);
        len += ft_putpad_len(' ', flag);
    }
    return (len);
}

int ft_print_str(char *i, t_flags flag)
{
    int     len;
    char    *str;

    len = 0;
    if (!flag.dot)
        flag.precision = (int) ft_strlen(i);
    str = ft_substr((char const *)i, 0, (size_t) flag.precision);
    flag.width -= flag.precision;
    if (!flag.left)
    {
        len += ft_putpad_len(' ', flag);
        len += ft_putstr_len(str);
    }
    else
    {
        len += ft_putstr_len(str);
        len += ft_putpad_len(' ', flag);
    }
    return (len);
}

int ft_print_int(int i, t_flags flag)
{
    int     len;
    char    *str;
    char    symbol;

    len = 0;
    str = ft_substr((char const *)ft_itoa(i), 0, (size_t) flag.precision);
    symbol = 0;
    if (flag.space)
        symbol = ' ';
    if (flag.plus)
        symbol = '+';
    if (i < 0)
    {
        str++;
        symbol = '-';
    }
    if (symbol)
        flag.width--;
    flag.width -= (int) ft_strlen(str);
    if (!flag.left)
    {
        if (flag.zero)
        {
            if (symbol)
                len += ft_putchar_len(symbol);
            len += ft_putpad_len('0', flag);
        }
        else
        {
            len += ft_putpad_len(' ', flag);
            if (symbol)
                len += ft_putchar_len(symbol);
        }
        len += ft_putstr_len(str);
    }
    else
    {
        len += ft_putstr_len(str);
        len += ft_putpad_len(' ', flag);
    }
    return (len);
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
    a.dot = 0;
    a.width = 0;
    a.precision = 1;
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
        if(i == flags[index])
            return (1);
    }
    return (0);
}

int ft_print_args(const char *format, int *i, t_flags flag, va_list args)
{
    int len;

    len = 0;
    flag.type = format[*i];
    if (format[*i] == '%')
        len += ft_print_char(format[*i], flag);
    else if (format[*i] == 'c')
        len += ft_print_char(va_arg(args, int), flag);
    else if (format[*i] == 's')
        len += ft_print_str(va_arg(args, char *), flag);
    else if (format[*i] == 'd' || format[*i] == 'i')
        len += ft_print_int(va_arg(args, int), flag);
    return (len);
}

t_flags ft_check_wp(const char *format, int *i, t_flags flag)
{
    flag.width = ft_atoi(&format[*i]);
    while (ft_isdigit(format[*i]))
        (*i)++;
    if (format[*i] == '.')
    {
        flag.dot = 1;
        (*i)++;
        flag.precision = ft_atoi(&format[*i]);
        while (ft_isdigit(format[*i]))
            (*i)++;
    }
    return (flag);
}

t_flags ft_check_flags(const char *format, int *i, t_flags flag)
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
            len += ft_print_args(format, &i, flag, args);
        }
        else
            len += ft_putchar_len(format[i]);
    }
    va_end(args);
    printf("%d\n", len);
    return (len);
}

int main(void)
{
    // printf("%d\n", printf("I am good with 100%-5%!!\n"));
    // ft_printf("I am good with 100%-5%!!\n");
    // printf("%d\n", printf("%5c", 'H'));
    // ft_printf("%5c", 'H');
    printf("%d\n", printf("%-6.3s\n", "Hello"));
    ft_printf("%-6.3s\n", "Hello");
    printf("%d\n", printf("01.%05.2d\n", 0));
    printf("%d\n", printf("02.%5d\n", -20));
    printf("%d\n", printf("03.%010.5d\n", -211110));
    printf("%d\n", printf("04.%.5d\n", 20));
    printf("%d\n", printf("05.%-5d\n", 20));
    printf("%d\n", printf("06.%+05d\n", 0));
    printf("%d\n", printf("07.%+010.5d\n", 20));
    printf("%d\n", printf("08.%010.5d\n", 20));
    printf("%d\n", printf("09.% d\n", -20));
    printf("%d\n", printf("10.%  d\n", 20));

    // ft_printf("01.%05d\n", -20);
    // ft_printf("02.%5d\n", -20);
    // ft_printf("03.%.5d\n", -20);
    // ft_printf("04.%.5d\n", 20);
    // ft_printf("05.%-5d\n", 20);
    // ft_printf("06.%+05d\n", 0);
    // ft_printf("07.%+010.5d\n", 20);
    // ft_printf("08.%010.5d\n", 20);
    // ft_printf("09.% d\n", -20);
    // ft_printf("10.%  d\n", 20);
    return (0);
}