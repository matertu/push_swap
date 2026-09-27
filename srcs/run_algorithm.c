/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 20:05:04 by matheus           #+#    #+#             */
/*   Updated: 2026/09/27 15:30:36 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_bench(t_bench *bench)
{
	ft_memset(bench, 0, sizeof(t_bench));
	bench->print = 1;
}

t_algorithm	choose_algorithm(double disorder)
{
	if (disorder < 0.2)
		return (simple);
	if (disorder < 0.5)
		return (medium);
	return (complex);
}

int	run_algorithm(t_stack *a, t_stack *b, t_flags *flags, t_bench *bench)
{
	int	res;

	initialize_bench(bench);
	bench->disorder = calculate_disorder(a);
	if (flags->algorithm == adaptive || flags->algorithm == none)
		bench->algorithm = choose_algorithm(bench->disorder);
	else
		bench->algorithm = flags->algorithm;
	res = 1;
	if (bench->algorithm == simple)
		res = run_simple_algorithm(a, b, bench);
	else if (bench->algorithm == medium)
		res = run_medium_algorithm(a, b, bench);
	else if (bench->algorithm == complex)
		res = run_complex_algorithm(a, b, bench);
	print_bench(bench, flags);
	return (res);
}

double	calculate_disorder(t_stack *a)
{
	t_node	*node_i;
	t_node	*node_j;
	int		mistakes;
	int		total_pairs;

	if (!a || !a->first || a->first->next == a->first)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	node_i = a->first;
	while (node_i != a->first->prev)
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
