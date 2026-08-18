/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 22:52:42 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/17 23:26:56 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	swap(t_stack *stack)
{
	t_node	*old_top;
	t_node	*new_top;

	if (!stack || !stack->top || stack->top == stack->first)
		return (0);
	old_top = pop(stack);
	new_top = pop(stack);
	push(old_top, stack);
	push(new_top, stack);
	return (1);
}

int	sa(t_stack *a, int print)
{
	swap(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
	return (1);
}

int	sb(t_stack *b, int print)
{
	swap(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
	return (1);
}

int	ss(t_stack *a, t_stack *b, int print)
{
	swap(a);
	swap(b);
	if (print)
		ft_putstr_fd("ss\n", 1);
	return (1);
}
