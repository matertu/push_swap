/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:59:16 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/27 14:47:42 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_max_bits(t_stack *a)
{
    int max_num;
    int max_bits;

    max_num = stack_size(a) - 1;
    max_bits = 0;
    while ((max_num >> max_bits) > 0)
        max_bits++;
    return (max_bits);
}

void    radix_sort(t_stack *a, t_stack *b, t_bench *bench)
{
    int size;
    int max_bits;
    int i;
    int j;

    size = stack_size(a);
    max_bits = get_max_bits(a);
    i = -1;
    while (++i < max_bits)
    {
        j = -1;
        while (++j < size)
        {
            if (((a->first->index >> i) & 1) == 0)
                pb(a, b, bench);
            else
                ra(a, bench);
        }
        while (b->first != NULL)
            pa(a, b, bench);
    }
}

int run_complex_algorithm(t_stack *a, t_stack *b, t_bench *bench)
{
    if (!a || !a->first)
        return (0);
    rank_values(a);
    if (stack_size(a) > 5)
        radix_sort(a, b, bench);
    else
        return (run_simple_algorithm(a, b, bench));
    return (1);
}
