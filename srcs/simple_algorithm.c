/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:59:16 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/27 14:41:16 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_index(t_stack *stack)
{
	t_node	*curr;
	int		min_val;
	int		min_pos;
	int		pos;
	int		size;

	curr = stack->first;
	min_val = curr->index;
	min_pos = 0;
	pos = 0;
	size = stack_size(stack);
	while (pos < size)
	{
		if (curr->index < min_val)
		{
			min_val = curr->index;
			min_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (min_pos);
}

void	push_min_to_b(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;
	int	size;

	size = stack_size(a);
	pos = get_min_index(a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, bench);
	}
	else
	{
		while (pos++ < size)
			rra(a, bench);
	}
	pb(a, b, bench);
}

int	run_simple_algorithm(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a || !a->first)
		return (0);
	rank_values(a);
	while (stack_size(a) > 2)
		push_min_to_b(a, b, bench);
	if (stack_size(a) == 2 && a->first->index > a->first->next->index)
		sa(a, bench);
	while (b->first != NULL)
		pa(a, b, bench);
	return (1);
}
