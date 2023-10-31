#include "ft_printf.h"

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

int ft_putchar_len(char i)
{
    ft_putchar_fd(i, 1);
    return (1);
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
            flag = 
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