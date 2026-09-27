# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#              #
#    Updated: 2026/09/26 20:06:00 by msouza-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libstack.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = stack_init.c \
          stack_push.c \
          stack_ops_swap.c \
          stack_ops_rotate.c \
          stack_ops_rev_rotate.c \
          stack_ops_push.c \
          stack_rank.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re