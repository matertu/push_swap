/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:59:16 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/17 02:08:39 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		push_min_to_b(t_stack *a, t_stack *b, t_bench *bench);
void	push_all_to_a(t_stack *a, t_stack *b, t_bench *bench);

int	run_simple_algorithm(t_stack *a, t_stack *b, t_bench *bench_relatory)
{
	if (!a || !a->first)
		return (0);
	rank_values(a);
	while (a->first != NULL)
		push_min_to_b(a, b, bench_relatory);
	push_all_to_a(a, b, bench_relatory);
	return (1);
}

int	get_min_index(t_stack *stack)
{
	t_node	*pivot;
	int		min_index_val;
	int		min_pos;
	int		pos;
	int		size;

	pivot = stack->first;
	min_index_val = pivot->index;
	min_pos = 0;
	pos = 0;
	size = stack_size(stack);
	while (pos < size)
	{
		if (pivot->index < min_index_val)
		{
			min_index_val = pivot->index;
			min_pos = pos;
		}
		pivot = pivot->next;
		pos++;
	}
	return (min_pos);
}

int	push_min_to_b(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;
	int	size;

	if (!a || !a->first)
		return (1);
	size = stack_size(a);
	pos = get_min_index(a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a, bench);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(a, bench);
			pos++;
		}
	}
	pb(a, b, bench);
	return (0);
}

void	push_all_to_a(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a || !b)
		return ;
	while (b->first != NULL)
		pa(a, b, bench);
}
