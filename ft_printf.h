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

#endif