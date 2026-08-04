/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:57:41 by matheus           #+#    #+#             */
/*   Updated: 2026/08/03 20:59:25 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compile_list(t_stack *a, int start, int argc, char **argv)
{
	if (argc - start > 1)
	{
		if (!compile_arg_list(a, start, argc, argv))
			return (0);
		return (1);
	}
	else
	{
		if (!compile_string_list(a, argv[start]))
			return (0);
		return (1);
	}
	return (0);
}

int	compile_arg_list(t_stack *a, int start, int argc, char **argv)
{
	int		i;
	long	value;
	t_node	*node;

	i = start;
	node = NULL;
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		if (!add_node(&node, value))
		{
			destroy_list(a);
			return (0);
		}
		i++;
	}
	return (1);
}

int	compile_string_list(t_stack *a, char *argv)
{
	int		i;
	long	value;

	i = 0;
	while (argv[i])
	{
		while (argv[i] && ft_isspace(argv[i]))
			i++;
		if (argv[i] == '\0')
			return (0);
		value = ft_atol(&argv[i]);
		if (to_long(value) || contains(value, a))
		{
			destroy_list(a);
			return (0);
		}
		if (!append((int)value, a))
			return (0);
		i += isnumber(&argv[i]);
	}
	return (1);
}
