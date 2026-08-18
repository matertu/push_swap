/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:13:59 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/17 22:52:53 by msouza-t         ###   ########.fr       */
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

int contains(int x, t_stack *stack)
{
    t_node  *current;

    if (!stack || !stack->first)
        return (0);
    if (stack->first->item == x)
        return (1);
    current = stack->first->next;
    while (current != stack->first)
    {
        if (current->item == x)
            return (1);
        current = current->next;
    }
    return (0);
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

void    print_list(t_stack *stack)
{
    t_node  *current;

    if (!stack || !stack->first)
        return ;
    ft_putnbr_fd(stack->first->item, 1);
    ft_putchar_fd('\n', 1);
    current = stack->first->next;
    while (current != stack->first)
    {
        ft_putnbr_fd(current->item, 1);
        ft_putchar_fd('\n', 1);
        current = current->next;
    }
}
