/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/26 20:06:00 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_node *node, t_stack *stack)
{
	if (!stack || !node)
		return (0);
	if (!stack->first)
	{
		node->next = node;
		node->prev = node;
		stack->first = node;
	}
	else
	{
		node->prev = stack->first->prev;
		node->next = stack->first;
		stack->first->prev->next = node;
		stack->first->prev = node;
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
	}
	else
	{
		node->prev = stack->first->prev;
		node->next = stack->first;
		stack->first->prev->next = node;
		stack->first->prev = node;
		stack->first = node;
	}
	return (1);
}

t_node	*pop_first(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->first)
		return (NULL);
	node = stack->first;
	if (node->next == node)
		stack->first = NULL;
	else
	{
		stack->first = node->next;
		stack->first->prev = node->prev;
		node->prev->next = stack->first;
	}
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
