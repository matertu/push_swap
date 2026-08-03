NAME          = push_swap
CC            = cc
CFLAGS        = -Wall -Wextra -Werror

LIBFT_DIR     = ./libft
LIBFT         = $(LIBFT_DIR)/libft.a

NODE_DIR      = ./node
LIBNODE       = $(STACK_DIR)/stack.a

PRINTF_DIR    = ./ft_printf
LIBPRINTF     = $(PRINTF_DIR)/libftprintf.a

SRCS          = $(filter-out srcs/run_algorithm.c, $(wildcard srcs/*.c))
OBJS          = $(SRCS:.c=.o)

all: $(LIBFT) $(LIBNODE) $(LIBPRINTF) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(LIBNODE):
	@make -C $(NODE_DIR)

$(LIBPRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBNODE) $(LIBPRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(NODE_DIR) -lnode -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(NODE_DIR)
	@make clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(NODE_DIR)
	@make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
