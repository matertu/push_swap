#ifndef NODE_H
# define NODE_H

# include <stdio.h>
# include <stdlib.h>

typedef int	t_item;

typedef struct s_node
{
	t_item			item;
	struct s_node	*next;
} * t_node;

t_node				new_node(t_item x);
void				append(t_node *A, t_node B);
void				destroy_list(t_node *L);
int					list_size(t_node L);
int					contains(t_item x, t_node L);
t_item				get_last(t_node L);
int					insert(t_item x, t_node L);
void				print_list(t_node list);

#endif
