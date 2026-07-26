/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:13:33 by msouza-t          #+#    #+#             */
/*   Updated: 2026/07/26 16:31:33 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isnumber(char *arg)
{
    int i;

    if (!arg || arg[0] == '\0')
        return (0);
    i = 0;
    if (arg[i] == '+' || arg[i] == '-')
        i++;
    if (!ft_isdigit(arg[i]))
        return (0);
    while (arg[i] && ft_isdigit(arg[i]))
        i++;
    return (i);
}

int	check_matrix_arg(int argc, char **argv, int start)
{
	while (start < argc)
	{
		if (isnumber(argv[start]) != ft_strlen(argv[start]))
			return (0);
		start++;
	}
	return (start);
}

int check_string_arg(char *arg)
{
    int i;
    int len;

    if (!arg || arg[0] == '\0')
        return (0);
    if (ft_isspace(arg[0]) || ft_isspace(arg[ft_strlen(arg) - 1]))
        return (0);
    i = 0;
    while (arg[i])
    {
        len = isnumber(&arg[i]);
        if (len == 0)
            return (0);
        i += len;
        if (arg[i] == '\0')
            return (1);
        if (!ft_isspace(arg[i]))
            return (0);
		i++;
    }
    return (1);
}
