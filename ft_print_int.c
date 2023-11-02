#include "ft_printf.h"

int ft_print_int(int i, t_flags flag)
{
    int     len;
    char    *ptr;
    char    *str;
    char    symbol;

    len = 0;
    symbol = 0;
    if (i == 0 && flag.precision == 0)
        ptr = ft_strdup("");
    else
        ptr = ft_itoa(i);
    str = ptr;
    if (flag.space)
        symbol = ' ';
    if (flag.plus)
        symbol = '+';
    if (i < 0)
    {
        str++;
        symbol = '-';
    }
    if (!flag.dot || flag.precision < (int) ft_strlen(str))
        flag.precision = (int) ft_strlen(str);
    flag.width -= flag.precision;
    flag.precision -= (int) ft_strlen(str);
    if (symbol)
        flag.width--;
    if (!flag.left)
    {
        if (flag.zero)
        {
            if (flag.dot)
                len += ft_putpad_len(' ', flag.width);
            if (symbol)
                len += ft_putchar_len(symbol);
            if (!flag.dot)
                len += ft_putpad_len('0', flag.width);
        }
        else
        {
            len += ft_putpad_len(' ', flag.width);
            if (symbol)
                len += ft_putchar_len(symbol);
        }
    }
    else
    {
        if (symbol)
            len += ft_putchar_len(symbol);
    }
    if (flag.dot)
        len += ft_putpad_len('0', flag.precision);
    if (!flag.left)
		len += ft_putstr_len(str);
    else
        len += (ft_putstr_len(str) + ft_putpad_len(' ', flag.width));
    free(ptr);
    return (len);
}

int ft_print_uint(unsigned int i, t_flags flag)
{
    int     len;
    char    *str;

    len = 0;
    if (i == 0 && flag.precision == 0)
        str = ft_strdup("");
    else
        str = ft_utoa(i);
    if (!flag.dot || flag.precision < (int) ft_strlen(str))
        flag.precision = (int) ft_strlen(str);
    flag.width -= flag.precision;
    flag.precision -= (int) ft_strlen(str);
    if (!flag.left)
    {
        if (flag.zero)
        {
            if (flag.dot)
                len += ft_putpad_len(' ', flag.width);
            if (!flag.dot)
                len += ft_putpad_len('0', flag.width);
        }
        else
            len += ft_putpad_len(' ', flag.width);
    }
    if (flag.dot)
        len += ft_putpad_len('0', flag.precision);
    if (!flag.left)
		len += ft_putstr_len(str);
    else
        len += (ft_putstr_len(str) + ft_putpad_len(' ', flag.width));
    free(str);
    return (len);
}