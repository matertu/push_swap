NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

NODE_DIR    = ./node
LIBNODE     = $(NODE_DIR)/libnode.a

SRCS        = $(filter-out srcs/run_algorithm.c, $(wildcard srcs/*.c))

OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(LIBNODE) $(NAME)

# Compila a Libft chamando o Makefile dela
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compila a libnode chamando o Makefile dela
$(LIBNODE):
	@make -C $(NODE_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBNODE)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(NODE_DIR) -lnode -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(NODE_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(NODE_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
