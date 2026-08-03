/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/02 20:35:06 by matheus          ###   ########.fr       */
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

void    append(t_stack *stack, int value)
{
    t_node  *node;

    if (!stack)
        return ;
    node = new_node(value);
    if (!node)
        return ;
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
}

void    destroy_stack(t_stack *stack)
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

int	list_size(t_node L)
{
	if (L == NULL)
		return (0);
	return (1 + list_size(L->next));
}

int	contains(int x, t_node L)
{
	if (L == NULL)
		return (0);
	if (x == L->item)
		return (1);
	return (contains(x, L->next));
}
int	get_last(t_node L)
{
	if (!L)
		return (0);
	while (L->next)
		L = L->next;
	return (L->item);
}

int	insert(int x, t_node l)
{
	t_node	temp;

	if (!l)
		return (0);
	while (l->next)
		l = l->next;
	temp = new_node(x);
	if (!temp)
		return (0);
	l->next = temp;
	return (1);
}

void	print_list(t_node list)
{
	t_node	current;

	current = list;
	while (current != NULL)
	{
		ft_printf("%d\n", current->item);
		current = current->next;
	}
}
