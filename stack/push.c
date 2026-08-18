/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 20:13:08 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/17 21:25:18 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int push(t_stack *a, t_stack *b)
{
    t_node *temp;

    temp = pop(b);
    if (!temp)
        return (0);
    if (!a->first)
    {
        temp->next = temp;
        temp->prev = temp;
        a->first = temp;
        a->top = temp;
    }
    else
    {
        temp->prev = a->top;
        temp->next = a->first;
        a->top->next = temp;
        a->first->prev = temp;
        a->top = temp;
    }
    return (1);
}

t_node	*pop(t_stack *a)
{
	t_node	*temp;

	if (!a->first || !a->top)
		return (NULL);
	if (a->top == a->first)
    {
        a->top = NULL;
        a->first = NULL;
    }
    else
    {
        a->top = a->top->prev;
        a->top->next = a->first;
        a->first->prev = a->top;
    }
    temp->next = NULL;
    temp->prev = NULL;
    return (temp);
}

int	swap(t_stack *a)
{
	t_node	*temp;

	if (a->top == a->first)
		return (0);
	temp = a->top->prev;
	temp->prev = a->top;
	a->top->prev = 
	temp->next = a->first;
	a->top->prev = 
	
	a->top = temp;
}

x  y