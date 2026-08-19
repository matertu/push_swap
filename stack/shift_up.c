/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:11:02 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/18 22:48:35 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	shift_up(t_stack *a)
{
	t_node	*temp;

	if (!a->first || (a->first == a->top))
		return (1);
	temp = pop(a);
	push_first(temp, a);
	return (1);
}

int	ra(t_stack *a, int print)
{
	shift_up(a);
	if (print)
		ft_putstr_fd("ra\n", 1);
	return (1);
}

int	rb(t_stack *b, int print)
{
	shift_up(b);
	if (print)
		ft_putstr_fd("rb\n", 1);
	return (1);
}

int	rr(t_stack *a, t_stack *b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
	return (1);
}
