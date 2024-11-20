NAME = libftprintf.a

CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC = ft_convert_To_Hex.c \
		ft_printf.c \
		ft_put_arg.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putunsigned_fd.c

OBJ = $(SRC:.c=.o)

ALL: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: