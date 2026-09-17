/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pilha.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/17 02:18:32 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILHA_H
# define PILHA_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
typedef struct s_bench_relatory	t_bench;

typedef struct s_node
{
	int				item;
	int				index;
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
void	rank_values(t_stack *stack);
int		ra(t_stack *a, t_bench *bench);
int		rb(t_stack *b, t_bench *bench);
int		rr(t_stack *a, t_stack *b, t_bench *bench);
int		rra(t_stack *a, t_bench *bench);
int		rrb(t_stack *b, t_bench *bench);
int		rrr(t_stack *a, t_stack *b, t_bench *bench);
int		sa(t_stack *a, t_bench *bench);
int		sb(t_stack *b, t_bench *bench);
int		ss(t_stack *a, t_stack *b, t_bench *bench);
int		pa(t_stack *a, t_stack *b, t_bench *bench);
int		pb(t_stack *a, t_stack *b, t_bench *bench);

#endif
