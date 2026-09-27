/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/27 11:34:13 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

 int	shift_down(t_stack *a)
{
	if (!a || !a->first || a->first->next == a->first)
		return (1);
	a->first = a->first->prev;
	return (1);
}

int	rra(t_stack *a, t_bench *bench)
{
	shift_down(a);
	if (bench)
	{
		if (bench->print)
			write(1, "rra\n", 4);
		bench->rra++;
		bench->total_ops++;
	}
	return (1);
}

int	rrb(t_stack *b, t_bench *bench)
{
	shift_down(b);
	if (bench)
	{
		if (bench->print)
			write(1, "rrb\n", 4);
		bench->rrb++;
		bench->total_ops++;
	}
	return (1);
}

int	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	shift_down(a);
	shift_down(b);
	if (bench)
	{
		if (bench->print)
			write(1, "rrr\n", 4);
		bench->rrr++;
		bench->total_ops++;
	}
	return (1);
}
