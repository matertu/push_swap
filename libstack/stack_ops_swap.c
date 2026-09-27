/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/27 11:34:13 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

 int	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->first || stack->first->next == stack->first)
		return (0);
	temp = stack->first->item;
	stack->first->item = stack->first->next->item;
	stack->first->next->item = temp;
	return (1);
}

int	sa(t_stack *a, t_bench *bench)
{
	swap(a);
	if (bench)
	{
		if (bench->print)
			write(1, "sa\n", 3);
		bench->sa++;
		bench->total_ops++;
	}
	return (1);
}

int	sb(t_stack *b, t_bench *bench)
{
	swap(b);
	if (bench)
	{
		if (bench->print)
			write(1, "sb\n", 3);
		bench->sb++;
		bench->total_ops++;
	}
	return (1);
}

int	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	swap(a);
	swap(b);
	if (bench)
	{
		if (bench->print)
			write(1, "ss\n", 3);
		bench->ss++;
		bench->total_ops++;
	}
	return (1);
}
