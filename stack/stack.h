#ifndef NODE_H
# define NODE_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				item;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*first;
}				t_stack;

t_node				*new_node(int x);
int					append(int value, t_stack *stack);
void				destroy_list(t_stack *stack);
int					list_size(t_stack *stack);
int					contains(int x, t_stack *stack);
int					get_last(t_stack *stack);
int					insert(int x, t_stack *stack);
void				print_list(t_stack *stack);

#endif
