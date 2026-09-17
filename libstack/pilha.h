/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pilha.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/13 23:12:51 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILHA_H
# define PILHA_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	int				item;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*first;
}	t_stack;

t_node	*new_node(int x);
int		append(int value, t_stack *stack);
int		push(t_node *node, t_stack *stack);
int		push_first(t_node *node, t_stack *stack);
t_node	*pop_first(t_stack *stack);
void	free_stack(t_stack *stack);
int		stack_size(t_stack *stack);
int		contains(int x, t_stack *stack);
void	print_list(t_stack *stack);
int		ra(t_stack *a, int print);
int		rb(t_stack *b, int print);
int		rr(t_stack *a, t_stack *b, int print);
int		rra(t_stack *a, int print);
int		rrb(t_stack *b, int print);
int		rrr(t_stack *a, t_stack *b, int print);
int		sa(t_stack *a, int print);
int		sb(t_stack *b, int print);
int		ss(t_stack *a, t_stack *b, int print);
int		pa(t_stack *a, t_stack *b, int print);
int		pb(t_stack *a, t_stack *b, int print);

#endif
