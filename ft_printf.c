#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int     count;
    char    *str = 0;

    if (!format || *format == '\0')
        return (0);
    // str = ft_strdup(format);
    if (!str || *str == '\0')
        return (0);
    count = 0;
    va_start(args, format);
    //count = ft_parse(str, args);
    va_end(args);
    free(str);
    return (count);
}

int main(void)
{
    printf("Formal: %15f", 3.1435345);
    return (0);
}