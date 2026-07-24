/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:13:33 by msouza-t          #+#    #+#             */
/*   Updated: 2026/07/24 14:38:31 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input()
{
	
}



int check_input_bench(char *arg)
{
    if (!ft_strcmp(arg, "--bench"))
        return (1);
    return (0);
}

int check_input_algorithm(char *arg, t_algorithm *algorithm)
{
    if (!ft_strcmp(arg, "--simple"))
        *algorithm = simple;
    else if (!ft_strcmp(arg, "--medium"))
        *algorithm = medium;
    else if (!ft_strcmp(arg, "--complex"))
        *algorithm = complex;
    else if (!ft_strcmp(arg, "--adaptive"))
        *algorithm = adaptive;
    else
        return (0);
    return (1);
}

int check_flags(int argc, char **argv, t_flags flags)
{
    int     i;

    flags.bench = 0;
    flags.algorithm = none;
    i = 1;
    while (i < argc)
    {
        if (check_input_bench(argv[i]))
		{
			if (flags.bench == 1)
				return (0);
            flags.bench = 1;
		}
        else
		{
			if (flags.algorithm != none)
            	check_input_algorithm(argv[i], &flags.algorithm);
			else if (check_input_algorithm(argv[i], &flags.algorithm))
				return (0);
		}
        i++;
    }
	if (flags.algorithm == none)
		flags.algorithm = adaptive;
    return (1);
}
