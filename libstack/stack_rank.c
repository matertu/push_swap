/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/26 20:06:00 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rank_values(t_stack *stack)
{
	t_node	*pivot;
	t_node	*comp;
	int		size;
	int		i;
	int		j;

	size = stack_size(stack);
	pivot = stack->first;
	i = 0;
	while (i < size)
	{
		comp = stack->first;
		j = 0;
		while (j < size)
		{
			if (comp->item < pivot->item)
				pivot->index++;
			comp = comp->next;
			j++;
		}
		pivot = pivot->next;
		i++;
	}
}
