/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/26 20:06:00 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*node;

	if (!b || !b->first)
		return (0);
	node = pop_first(b);
	if (!node)
		return (0);
	push_first(node, a);
	if (bench)
	{
		if (bench->print)
			write(1, "pa\n", 3);
		bench->pa++;
		bench->total_ops++;
	}
	return (1);
}

int	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*node;

	if (!a || !a->first)
		return (0);
	node = pop_first(a);
	if (!node)
		return (0);
	push_first(node, b);
	if (bench)
	{
		if (bench->print)
			write(1, "pb\n", 3);
		bench->pb++;
		bench->total_ops++;
	}
	return (1);
}
