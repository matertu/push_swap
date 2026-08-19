/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 23:20:52 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/18 21:34:02 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	shift_down(t_stack *a)
{
	t_node	*temp;

	if (!a->first || (a->first == a->top))
		return (1);
	temp = pop_first(a);
	return (push(temp, a));
}

int	rra(t_stack *a, int print)
{
	shift_down(a);
	if (print)
		ft_putstr_fd(1, "rra\n");
	return (1);
}

int	rrb(t_stack *b, int print)
{
	shift_down(b);
	if (print)
		ft_putstr_fd(1, "rrb\n");
	return (1);
}

int	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_putstr_fd(1, "rrr\n");
	return (1);
}
