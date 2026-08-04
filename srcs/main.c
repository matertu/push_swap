/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:43:03 by matheus           #+#    #+#             */
/*   Updated: 2026/08/03 21:05:23 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    int     			start;
    t_flags 			flags;
	// t_bench_relatory	relatory;
    t_stack  			a;
    //t_stack  			b;

    if (argc < 2)
        return (0);
    // b = NULL;
    start = validate_input(argc, argv, &flags);
    if (start)
    {
		if (compile_list(&a, start, argc, argv))
		{
			//if (run_algorithm(&a, &b, flags, relatory))
			//{
				//free_list(&a);
				//free_list(&b);
				print_list(&a);
				return (0);
			//}
		}
		else
		put_error();
		return (0);
    }
    put_error();
    return (-1);
}
