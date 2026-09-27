# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/10 14:12:19 by msouza-t          #+#    #+#              #
#    Updated: 2026/09/26 20:06:00 by msouza-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprinterr.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ft_printerr.c \
          ft_putchar.c \
          ft_putstr.c \
          ft_putptr.c \
          ft_puthex.c \
          ft_putnbr.c \
          ft_putnbr_unsigned.c \
          ft_utils.c

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