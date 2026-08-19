NAME          = push_swap
CC            = cc
CFLAGS        = -Wall -Wextra -Werror

LIBFT_DIR     = ./libft
LIBFT         = $(LIBFT_DIR)/libft.a

NODE_DIR      = ./stack
LIBNODE       = $(STACK_DIR)/libstack.a

PRINTERR_DIR    = ./ft_printerr
LIBPRINTERR     = $(PRINTERR_DIR)/libftprinterr.a

SRCS          = $(filter-out srcs/run_algorithm.c, $(wildcard srcs/*.c))
OBJS          = $(SRCS:.c=.o)

all: $(LIBFT) $(LIBNODE) $(LIBPRI) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(LIBNODE):
	@make -C $(NODE_DIR)

$(LIBPRINTERR):
	@make -C $(PRINTERR_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBNODE) $(LIBPRINTERR)
	$(CC) $(CFLAGS) $(OBJS) -L$(NODE_DIR) -lstack -L$(PRINTERR_DIR) -lftprinterr -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(NODE_DIR)
	@make clean -C $(PRINTERR_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(NODE_DIR)
	@make fclean -C $(PRINTERR_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
