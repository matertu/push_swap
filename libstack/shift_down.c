/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 23:20:52 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/19 21:16:01 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	shift_down(t_stack *a)
{
	if (!a || !a->first || a->first == a->top)
		return (1);
	a->first = a->top;
	a->top = a->top->prev;
	return (1);
}

int	rra(t_stack *a, int print)
{
	shift_down(a);
	if (print)
		ft_putstr_fd("rra\n", 1);
	return (1);
}

int	rrb(t_stack *b, int print)
{
	shift_down(b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
	return (1);
}
