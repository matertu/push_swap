/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 20:05:04 by matheus           #+#    #+#             */
/*   Updated: 2026/07/27 22:40:43 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    initialize_bench_relatory(t_bench_relatory *bench_relatory)
{
    ft_memset(bench_relatory, 0, sizeof(t_bench_relatory));
}

void	print_relatory(t_bench_relatory, t_flags *flags)
{
	if (!flags->bench)
		return ;
	
}
int	run_algorithm(t_list a, t_list b, t_flags *flags, t_bench_relatory *bench_relatory)
{
	initialize_bench_relatory(bench_relatory);
	bench_relatory->disorder = calulate_disorder(a);
	if (bench_relatory->disorder == 0)
	{
		
		return (1);
	}
	if (flags->algorithm == adaptive || flags->algorithm == none)
		flags->algorithm = choice_best_algorithm(a, bench_relatory->disorder);
	if (flags->algorithm == simple)
	{
		if (!run_simple_algorithm(&a, &b, bench_relatory));
			return (0);
	}
	else if (flags->algorithm == medium)
	{
		if (!run_medium_algorithm(&a, &b, bench_relatory));
			return (0);
	}
	else if (flags->algorithm == complex)
	{
		if (!run_complex_algorithm(&a, &b, bench_relatory));
			return (0);
	}
	if (flags->bench)
		put_bench(bench_relatory);
	return (1);
}
