/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 20:05:04 by matheus           #+#    #+#             */
/*   Updated: 2026/08/19 22:24:41 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    initialize_bench_relatory(t_bench *bench_relatory)
{
    ft_memset(bench_relatory, 0, sizeof(t_bench));
}

int	run_algorithm(t_stack *a, t_stack *b, t_flags *flags, t_bench *bench_relatory)
{
	initialize_bench_relatory(bench_relatory);
	bench_relatory->disorder = calculate_disorder(a);
	if (flags->algorithm == adaptive || flags->algorithm == none)
		flags->algorithm = chose_algorithm(bench_relatory->disorder);
	bench_relatory->algorithm = flags->algorithm;
	if (flags->algorithm == simple)
	{
		if (!run_simple_algorithm(a, b, bench_relatory))
			return (0);
	}
	else if (flags->algorithm == medium)
	{
		if (!run_medium_algorithm(a, b, bench_relatory))
			return (0);
	}
	else if (flags->algorithm == complex)
	{
		if (!run_complex_algorithm(a, b, bench_relatory))
			return (0);
	}
	print_bench(bench_relatory, flags);
	return (1);
}

t_algorithm	chose_algorithm(double disorder)
{
	if (disorder < 0.2)
		return (simple);
	if (disorder < 0.5)
		return (medium);
	return (complex);
}

double	calculate_disorder(t_stack *a)
{
	t_node	*node_i;
	t_node	*node_j;
	int		mistakes;
	int		total_pairs;

	if (!a || !a->first || a->first == a->top)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	node_i = a->first;
	while (node_i != a->top)
	{
		node_j = node_i->next;
		while (node_j != a->first)
		{
			total_pairs++;
			if (node_i->item > node_j->item)
				mistakes++;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / (double)total_pairs);
}
