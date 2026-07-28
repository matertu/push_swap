NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = $(filter-out srcs/run_algorithm.c, $(wildcard srcs/*.c))

OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

# Compila a Libft chamando o Makefile dela
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
