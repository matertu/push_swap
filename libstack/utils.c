/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:13:59 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/19 21:16:56 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_size(t_stack *stack)
{
	int		count;
	t_node	*current;

	if (!stack || !stack->first)
		return (0);
	count = 1;
	current = stack->first;
	while (current != stack->top)
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
		if (current == stack->top)
			break ;
		current = current->next;
	}
	return (0);
}

t_node	*pop(t_stack *a)
{
	t_node	*temp;

	if (!a || !a->first || !a->top)
		return (NULL);
	temp = a->top;
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

t_node	*pop_first(t_stack *a)
{
	t_node	*first;

	if (!a || !a->first)
		return (NULL);
	first = a->first;
	if (a->first == a->top)
	{
		a->first = NULL;
		a->top = NULL;
	}
	else
	{
		a->first = first->next;
		a->first->prev = a->top;
		a->top->next = a->first;
	}
	first->next = NULL;
	first->prev = NULL;
	return (first);
}

void	print_list(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->first)
		return ;
	current = stack->first;
	while (1)
	{
		ft_putnbr_fd(current->item, 1);
		ft_putchar_fd('\n', 1);
		if (current == stack->top || current->next == stack->first)
			break ;
		current = current->next;
	}
}
