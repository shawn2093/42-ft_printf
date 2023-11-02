#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_flags {
    int type;
	int	left;
    int space;
    int plus;
    int zero;
    int hash;
    int dot;
    int width;
    int precision;
}   t_flags;

int ft_putchar_len(char i);
int ft_putstr_len(char *i);
int ft_putpad_len(char i, int len);
int ft_print_char(char i, t_flags flag);
int ft_print_str(char *i, t_flags flag);

int ft_print_ptr(void *i, t_flags flag);
int ft_print_hex(unsigned int i, t_flags flag);

int ft_print_int(int i, t_flags flag);
int ft_print_uint(unsigned int i, t_flags flag);

int ft_printf(const char *format, ...);

#endif