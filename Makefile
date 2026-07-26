NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c check_input_list.c check_input_flags.c utils.c validate_input.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re