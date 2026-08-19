/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:57:41 by matheus           #+#    #+#             */
/*   Updated: 2026/08/19 19:10:56 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compile_list(t_stack *a, int start, int argc, char **argv)
{
	int	status;

	if (argc - start > 1)
		status = compile_arg_list(a, start, argc, argv);
	else
		status = compile_string_list(a, argv[start]);
	if (!status)
	{
		free_stack(a);
		return (0);
	}
	return (1);
}

int	compile_arg_list(t_stack *a, int start, int argc, char **argv)
{
	long	value;

	while (start < argc)
	{
		if (!isnumber(argv[start]))
			return (0);
		value = ft_atol(argv[start]);
		if (to_long(value) || contains(value, a))
			return (0);
		if (!append((int)value, a))
			return (0);
		start++;
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
		value = ft_atol(&argv[i]);
		if (to_long(value) || contains(value, a))
		{
			free_stack(a);
			return (0);
		}
		if (!append((int)value, a))
			return (0);
		i += isnumber(&argv[i]);
	}
	return (1);
}
