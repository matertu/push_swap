#ifndef NODE_H
# define NODE_H

# include <stdio.h>
# include <stdlib.h>

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

t_node				new_node(int x);
void				append(int value, t_stack *stack);
void				destroy_list(t_node *L);
int					list_size(t_node L);
int					contains(int x, t_node L);
int					get_last(t_node L);
int					insert(int x, t_node L);
void				print_list(t_node list);

#endif
