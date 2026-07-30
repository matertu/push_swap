/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:57:41 by matheus           #+#    #+#             */
/*   Updated: 2026/07/28 20:59:17 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compile_list(t_stack *a, int start, int argc, char **argv)
{
    int i;
    int *value;
    t_list *new_node;

    i = start;

    while (i < argc)
    {
        value = malloc(sizeof(int));
        if (!value)
            return (0);
        *value = ft_atoi(argv[i]);         
        new_node = ft_lstnew(value);
        if (!new_node)
        {
            free(value);
            return (0);
        }
        ft_lstadd_back(&(a->top), new_node);
        a->size++;
        i++;
    }
    return (1);
}

int isvalid(t_list *list)
{
    if (!list)
        return (0);
    return (1);
}