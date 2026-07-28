/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:37:35 by matheus           #+#    #+#             */
/*   Updated: 2026/07/27 22:30:03 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int validate_input(int argc, char **argv, t_flags *flags)
{
    int start;

    start = check_flags(argc, argv, flags);
    if (!start || start >= argc)
        return (0);
    if (argc - start == 1)
    {
        if (!check_string_arg(argv[start]))
            return (0);
    }
    else
    {
        if (!check_matrix_arg(argc, argv, start))
            return (0);
    }
    return (start);
}
