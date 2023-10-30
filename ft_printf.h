#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_types {
    int type;
    int width;
    int space;
    int plus;
    int zero;
    int hash;
    int decimal;
    int star;
    int front;
}   t_types;

#endif