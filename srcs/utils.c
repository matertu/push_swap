/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:27:30 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/19 22:10:22 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

void	put_error()
{
	ft_putstr_fd("Error\n", 2);
}

int	empty_list(t_stack *stack)
{
	if (!stack || stack->top == NULL)
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	cont;
	int		sign;
	int		i;

	cont = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		cont = (cont * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * cont);
}

int	to_long(long value)
{
	if (value > 2147483647 || value < -2147483648)
		return (1);
	return (0);
}

char	*get_strategy(t_algorithm algo)
{
	if (algo == simple)
		return ("Simple / O(n^2)");
	if (algo == medium)
		return ("Medium / O(n*sqrt(n))");
	if (algo == complex)
		return ("Complex / O(n*log(n))");
	if (algo == adaptive)
		return ("Adaptive / O(n*sqrt(n))");
	return ("None / O(1)");
}

void	print_bench(t_bench *bench_relatory, t_flags *flags)
{
	int	int_part;
	int	dec_part;

	if (!flags || !flags->bench || !bench_relatory)
		return ;
	int_part = (int)(bench_relatory->disorder * 100);
	dec_part = (int)(bench_relatory->disorder * 10000) % 100;
	if (dec_part < 0)
		dec_part = -dec_part;
	ft_printerr("[bench] disorder:\t%d.%02d%%\n", int_part, dec_part);
	ft_printerr("[bench] strategy:\t%s\n",
		 get_strategy(bench_relatory->algorithm));
	ft_printerr("[bench] total_ops:\t%d\n", bench_relatory->total_ops);
	ft_printerr("[bench] sa:\t%d\tsb:\t%d\tss:\t%d\tpa:\t%d\tpb:\t%d\n",
		bench_relatory->sa, bench_relatory->sb, bench_relatory->ss,
		bench_relatory->pa, bench_relatory->pb);
	ft_printerr("[bench] ra:\t%d\trb:\t%d\trr:\t%d\trra:\t%d\trrb:\t%d\trrr:\t%d\n",
		bench_relatory->ra, bench_relatory->rb, bench_relatory->rr,
		bench_relatory->rra, bench_relatory->rrb, bench_relatory->rrr);
}
