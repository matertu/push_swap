/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/27 11:34:13 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

 int	shift_up(t_stack *a)
{
	if (!a || !a->first || a->first->next == a->first)
		return (1);
	a->first = a->first->next;
	return (1);
}

int	ra(t_stack *a, t_bench *bench)
{
	shift_up(a);
	if (bench)
	{
		if (bench->print)
			write(1, "ra\n", 3);
		bench->ra++;
		bench->total_ops++;
	}
	return (1);
}

int	rb(t_stack *b, t_bench *bench)
{
	shift_up(b);
	if (bench)
	{
		if (bench->print)
			write(1, "rb\n", 3);
		bench->rb++;
		bench->total_ops++;
	}
	return (1);
}

int	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	shift_up(a);
	shift_up(b);
	if (bench)
	{
		if (bench->print)
			write(1, "rr\n", 3);
		bench->rr++;
		bench->total_ops++;
	}
	return (1);
}
