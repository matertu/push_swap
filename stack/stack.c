/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/18 22:17:51 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*new_node(int x)
{
	t_node	*n;

	n = malloc(sizeof(struct s_node));
	if (!n)
		return (NULL);
	n->item = x;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

int    append(int value, t_stack *stack)
{
    t_node  *node;

    node = new_node(value);
    if (!node)
	{
		destroy_stack(stack);
        return (0);
	}
    push(node, stack);
	return (1);
}

void    free_stack(t_stack *stack)
{
    t_node  *current;
    t_node  *next_node;

    if (!stack || !stack->first)
        return ;
    if (stack->top)
        stack->top->next = NULL;
    current = stack->first;
    while (current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    stack->first = NULL;
    stack->top = NULL;
}
