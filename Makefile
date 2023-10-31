NAME = libftprintf.a
CC = gcc
AR = ar -rc
RM = rm -f
SRCS = ft_printf.c
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a
CFLAGS = -Wall -Wextra -Werror
OPTION = -I ./

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH) bonus

clean:
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
