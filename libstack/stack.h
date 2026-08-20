#ifndef NODE_H
# define NODE_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				item;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*first;
}					t_stack;

int					push(t_node *node, t_stack *stack);
int					push_first(t_node *node, t_stack *stack);
int					pa(t_stack *a, t_stack *b, int print);
int					pb(t_stack *a, t_stack *b, int print);
int					swap(t_stack *stack);
int					sa(t_stack *a, int print);
int					sb(t_stack *b, int print);
int					ss(t_stack *a, t_stack *b, int print);
int					shift_down(t_stack *a);
int					rra(t_stack *a, int print);
int					rrb(t_stack *b, int print);
int					rrr(t_stack *a, t_stack *b, int print);
int					shift_up(t_stack *a);
int					ra(t_stack *a, int print);
int					rb(t_stack *b, int print);
int					rr(t_stack *a, t_stack *b, int print);
t_node				*new_node(int x);
int					append(int value, t_stack *stack);
void				free_stack(t_stack *stack);
int 				contains(int x, t_stack *stack);
void    			print_list(t_stack *stack);
t_node				*pop(t_stack *a);
t_node				*pop_first(t_stack *a);
int					stack_size(t_stack *stack);

#endif
