/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:43:03 by matheus           #+#    #+#             */
/*   Updated: 2026/07/27 22:35:11 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    int     			start;
    t_flags 			flags;
	// t_bench_relatory	relatory;
    // t_list  			*a;
    // t_list  			*b;

    if (argc < 2)
        return (0);
    // a = NULL;
    // b = NULL;
    start = validate_input(argc, argv, &flags);
    if (start)
    {
        /*if (compile_list(&a, start, argc, argv))
        {
            if (run_algorithm(&a, &b, flags, relatory))
			{
				free_list(&a);
				free_list(&b);
				return (0);
			}
        }*/
	   ft_putstr_fd("OK\n", 1);
	   return (0);
    }
    put_error();
    return (-1);
}
