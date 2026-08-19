/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 20:13:08 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/18 21:37:50 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	push(t_node *node, t_stack *stack)
{
	if (!stack || !node)
		return (0);
	if (!stack->first)
	{
		node->next = node;
		node->prev = node;
		stack->first = node;
		stack->top = node;
	}
	else
	{
		node->prev = stack->top;
		node->next = stack->first;
		stack->top->next = node;
		stack->first->prev = node;
		stack->top = node;
	}
	return (1);
}

int	push_first(t_node *node, t_stack *stack)
{
	if (!stack || !node)
		return (0);
	if (!stack->first)
	{
		node->next = node;
		node->prev = node;
		stack->first = node;
		stack->top = node;
	}
	else
	{
		node->prev = stack->top;
		node->next = stack->first;
		stack->top->next = node;
		stack->first->prev = node;
		stack->first = node;
	}
	return (1);
}

int	pa(t_stack *a, t_stack *b, int print)
{
	push(pop(b), a);
	if (print)
		ft_putstr_fd("pa\n", 1);
	return (1);
}

int	pb(t_stack *a, t_stack *b, int print)
{
	push(pop(a), b);
	if (print)
		ft_putstr_fd("pb\n", 1);
	return (1);
}
