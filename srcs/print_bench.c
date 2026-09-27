/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:27:30 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/27 15:33:42 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*get_name_algorithm(t_algorithm algo)
{
	if (algo == simple)
		return ("Simple");
	if (algo == medium)
		return ("Medium");
	if (algo == complex)
		return ("Complex");
	return ("Adaptive");
}

char	*get_notation_algorithm(t_algorithm algo)
{
	if (algo == simple)
		return ("O(n^2)");
	if (algo == medium)
		return ("O(n*sqrt(n))");
	if (algo == complex)
		return ("O(n*log(n))");
	return ("O(n*log(n))");
}

char	*get_strategy(t_algorithm algo)
{
	return (get_name_algorithm(algo));
}

void	print_bench(t_bench *bench, t_flags *flags)
{
	int	int_part;
	int	dec_part;

	if (!flags || !flags->bench || !bench)
		return ;
	int_part = (int)(bench->disorder * 100);
	dec_part = (int)(bench->disorder * 10000) % 100;
	if (dec_part < 0)
		dec_part = -dec_part;
	ft_printerr("[bench] disorder:\t%d.%d%%\n", int_part, dec_part);
	ft_printerr("[bench] strategy:\t%s / %s\n",
		get_name_algorithm(flags->algorithm),
		get_notation_algorithm(bench->algorithm));
	ft_printerr("[bench] total_ops:\t%d\n", bench->total_ops);
	ft_printerr("[bench] sa:\t%d\tsb:\t%d\tss:\t%d\tpa:\t%d\tpb:\t%d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printerr("[bench] ra:\t%d\trb:\t%d\trr:\t%d\trra:\t%d\trrb:\t%d\t",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb);
	ft_printerr("rrr:\t%d\n", bench->rrr);
}
