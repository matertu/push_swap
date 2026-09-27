/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:43:03 by matheus           #+#    #+#             */
/*   Updated: 2026/09/27 11:02:00 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		start;
	t_flags	flags;
	t_bench	bench;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	start = validate_input(argc, argv, &flags);
	if (!start || !compile_list(&a, start, argc, argv))
	{
		free_stack(&a);
		put_error();
		return (0);
	}
	run_algorithm(&a, &b, &flags, &bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
