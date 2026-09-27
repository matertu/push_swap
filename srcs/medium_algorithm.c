/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:59:16 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/27 14:32:18 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int ft_sqrt(int number)
{
    int i;

    if (number <= 0)
        return (0);
    i = 1;
    while (i * i <= number)
        i++;
    return (i - 1);
}

static int get_chunk_size(int size)
{
    int base_sqrt;
    int chunk;

    base_sqrt = ft_sqrt(size);
    chunk = base_sqrt + (base_sqrt * 4) / 10;
    if (chunk < 1)
        chunk = 1;
    return (chunk);
}

void push_chunks(t_stack *a, t_stack *b, t_bench *bench, int size)
{
    int chunk;
    int i;

    chunk = get_chunk_size(size);
    i = 0;
    while (a->first != NULL)
    {
        if (a->first->index <= i)
        {
            pb(a, b, bench);
            rb(b, bench);
            i++;
        }
        else if (a->first->index <= i + chunk)
        {
            pb(a, b, bench);
            i++;
        }
        else
            ra(a, bench);
    }
}

int find_max_pos(t_stack *b)
{
    t_node  *curr;
    int     max_val;
    int     max_pos;
    int     pos;
    int     size;

    curr = b->first;
    max_val = curr->index;
    max_pos = 0;
    pos = 0;
    size = stack_size(b);
    while (pos < size)
    {
        if (curr->index > max_val)
        {
            max_val = curr->index;
            max_pos = pos;
        }
        curr = curr->next;
        pos++;
    }
    return (max_pos);
}

void push_back_max(t_stack *a, t_stack *b, t_bench *bench)
{
    int max_pos;
    int size;

    while (b->first != NULL)
    {
        size = stack_size(b);
        max_pos = find_max_pos(b);
        if (max_pos <= size / 2)
        {
            while (max_pos-- > 0)
                rb(b, bench);
        }
        else
        {
            while (max_pos++ < size)
                rrb(b, bench);
        }
        pa(a, b, bench);
    }
}

int run_medium_algorithm(t_stack *a, t_stack *b, t_bench *bench)
{
    if (!a || !a->first)
        return (0);
    rank_values(a);
    if (stack_size(a) <= 5)
        return (run_simple_algorithm(a, b, bench));
    push_chunks(a, b, bench, stack_size(a));
    push_back_max(a, b, bench);
    return (1);
}
