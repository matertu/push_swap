# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matheus <matheus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/21 21:13:54 by msouza-t          #+#    #+#              #
#    Updated: 2026/09/27 11:45:14 by matheus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME          = push_swap
CC            = cc
CFLAGS        = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(STACK_DIR) -I$(PRINTERR_DIR)

LIBFT_DIR     = ./libft
LIBFT         = $(LIBFT_DIR)/libft.a

STACK_DIR     = ./libstack
LIBSTACK      = $(STACK_DIR)/libstack.a

PRINTERR_DIR  = ./ft_printerr
LIBPRINTERR   = $(PRINTERR_DIR)/libftprinterr.a

SRCS          = srcs/main.c \
                srcs/validate_input.c \
                srcs/check_input_flags.c \
                srcs/check_input_list.c \
                srcs/compile_list.c \
                srcs/run_algorithm.c \
                srcs/simple_algorithm.c \
                srcs/medium_algorithm.c \
                srcs/complex_algorithm.c \
                srcs/utils.c \
                srcs/print_bench.c

OBJS          = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(LIBSTACK):
	@make -C $(STACK_DIR)

$(LIBPRINTERR):
	@make -C $(PRINTERR_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBSTACK) $(LIBPRINTERR)
	$(CC) $(CFLAGS) $(OBJS) -L$(STACK_DIR) -lstack -L$(PRINTERR_DIR) -lftprinterr -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(STACK_DIR)
	@make clean -C $(PRINTERR_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(STACK_DIR)
	@make fclean -C $(PRINTERR_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
