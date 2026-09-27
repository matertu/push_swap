/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/26 20:06:00 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(int x)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->item = x;
	n->index = 0;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

int	append(int value, t_stack *stack)
{
	t_node	*node;

	node = new_node(value);
	if (!node)
	{
		free_stack(stack);
		return (0);
	}
	push(node, stack);
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	if (!stack || !stack->first)
		return ;
	stack->first->prev->next = NULL;
	current = stack->first;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack->first = NULL;
}

int	stack_size(t_stack *stack)
{
	int		count;
	t_node	*current;

	if (!stack || !stack->first)
		return (0);
	count = 1;
	current = stack->first;
	while (current->next != stack->first)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	contains(int x, t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->first)
		return (0);
	current = stack->first;
	while (1)
	{
		if (current->item == x)
			return (1);
		current = current->next;
		if (current == stack->first)
			break ;
	}
	return (0);
}
