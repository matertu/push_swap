/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:13:33 by msouza-t          #+#    #+#             */
/*   Updated: 2026/07/27 22:30:03 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_flags(t_flags *flag)
{	
	flag->algorithm = none;
	flag->bench = 0;
}

int is_bench_flag(char *arg)
{
    if (!ft_strcmp(arg, "--bench"))
        return (1);
    return (0);
}

t_algorithm parse_algorithm_flag(const char *arg)
{
    if (!ft_strcmp(arg, "--simple"))
        return (simple);
    if (!ft_strcmp(arg, "--medium"))
        return (medium);
    if (!ft_strcmp(arg, "--complex"))
        return (complex);
    if (!ft_strcmp(arg, "--adaptive"))
        return (adaptive);
    return (none);
}

int check_flags(int argc, char **argv, t_flags *flags)
{
    int         i;
    t_algorithm algorithm;

    i = 1;
	initialize_flags(flags);
    while (i < argc && i <= 2)
    {
        algorithm = parse_algorithm_flag(argv[i]);
        if (algorithm != none)
        {
            if (flags->algorithm != none)
                return (0);
            flags->algorithm = algorithm;
        }
        else if (is_bench_flag(argv[i]))
        {
            if (flags->bench == 1)
                return (0);
            flags->bench = 1;
        }
        else
            return (i);
        i++;
    }
    return (i);
}
