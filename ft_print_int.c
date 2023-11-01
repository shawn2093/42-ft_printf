int ft_print_int(int i, t_flags flag)
{
    int     len;
    char    *str;
    char    symbol;

    len = 0;
    str = ft_itoa(i);
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
        len += ft_putchar_len(str);
    }
    else
    {
        len += ft_putstr_len(str);
        len += ft_putpad_len(' ', flag);
    }
    return (len);
}