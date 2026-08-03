/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:13:59 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/03 18:14:07 by msouza-t         ###   ########.fr       */
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