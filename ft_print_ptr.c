#include "ft_printf.h"

static int	numlen(unsigned long long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

char	*ft_htoa(unsigned long long n, int i)
{
	int		len;
	char	*str;
	int		start;
    char    *hex;

    if (n == 0)
		return (ft_strdup("0"));
	len = numlen(n);
    hex = "0123456789abcdef";
    if (i == 'X')
        hex = "0123456789ABCDEF";
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	start = 0;
	while (--len >= start)
	{
		str[len] = hex[(int) (n % 16)];
		n = n / 16;
	}
	return (str);
}

int ft_print_ptr(void *i, t_flags flag)
{
    int     len;
    char    *str;

    len = 0;
    str = ft_htoa((unsigned long long) i, flag.type);
    flag.width -= ((int) ft_strlen(str) + 2);
    if (!flag.left)
    {
        len += ft_putpad_len(' ', flag.width);
        len += ft_putstr_len("0x");
        len += ft_putstr_len(str);
    }
    else
    {
        len += ft_putstr_len("0x");
        len += ft_putstr_len(str);
        len += ft_putpad_len(' ', flag.width);
    }
    free(str);
    return (len);
}

int ft_print_hex(unsigned int i, t_flags flag)
{
    int     len;
    char    *str;
    char    *hash;

    len = 0;
    hash = "";
    if (i == 0 && flag.precision == 0)
        str = ft_strdup("");
    else
        str = ft_htoa((unsigned long long) i, flag.type);
    if (flag.hash && i != 0)
    {
        flag.width -= 2;
        if (flag.type == 'X')
            hash = "0X";
        else
            hash = "0x";
    }
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
                len += ft_putstr_len(hash);
            if (flag.dot)
                len += ft_putpad_len('0', flag.precision);
            else
                len += ft_putpad_len('0', flag.width);
        }
        else
        {
            len += ft_putpad_len(' ', flag.width);
                len += ft_putstr_len(hash);
            if (flag.dot)
                len += ft_putpad_len('0', flag.precision);
        }
        len += ft_putstr_len(str);
    }
    else
    {
        if (flag.dot)
            len += ft_putpad_len('0', flag.precision);
        len += ft_putstr_len(str);
        len += ft_putpad_len(' ', flag.width);
    }
    free(str);
    return (len);
}