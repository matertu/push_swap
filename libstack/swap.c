/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 22:52:42 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/19 21:15:32 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->first || stack->first == stack->top)
		return (0);
	temp = stack->first->item;
	stack->first->item = stack->first->next->item;
	stack->first->next->item = temp;
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
