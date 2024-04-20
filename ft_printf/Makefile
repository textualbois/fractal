NAME = libftprintf.a

SRCS = ft_format_char.c ft_format_str.c ft_format_hex.c ft_format_nums.c\
		ft_input_parser.c \
		ft_route.c ft_validators.c ft_printf.c\
		ft_rebase_int.c ft_helpers_hex.c ft_helpers_nums.c ft_helpers_str.c

BONUS_SRCS = ft_format_char.c ft_format_str.c ft_format_hex.c ft_format_nums.c\
		ft_input_parser.c \
		ft_route.c ft_validators.c ft_printf.c\
		ft_rebase_int.c ft_helpers_hex.c ft_helpers_nums.c ft_helpers_str.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@./

libft:
	make -C ./libft/

bonus: all

#clean $(BONUS_OBJS)
#	make all bonus -C ./libft/
#	cp ./libft/libft.a ./libftprintf.a
#	ar rcs $(NAME) $(OBJS)
#	ar rcs $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
