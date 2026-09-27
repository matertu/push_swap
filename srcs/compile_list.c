/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:57:41 by matheus           #+#    #+#             */
/*   Updated: 2026/09/27 11:15:00 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compile_list(t_stack *a, int start, int argc, char **argv)
{
	int	status;

	if (argc - start == 1)
		status = compile_string_list(a, argv[start]);
	else
		status = compile_matrix_list(a, start, argc, argv);
	if (!status)
	{
		free_stack(a);
		return (0);
	}
	return (1);
}

int	compile_matrix_list(t_stack *a, int start, int argc, char **argv)
{
	int		i;
	long	value;

	i = start;
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		if (to_long(value) || contains((int)value, a))
			return (0);
		if (!append((int)value, a))
			return (0);
		i++;
	}
	return (1);
}

int	compile_string_list(t_stack *a, char *argv)
{
	int		i;
	int		count;
	long	value;

	i = 0;
	count = 0;
	while (argv[i])
	{
		while (argv[i] && ft_isspace(argv[i]))
			i++;
		if (argv[i] == '\0')
			break ;
		value = ft_atol(&argv[i]);
		if (to_long(value) || contains((int)value, a))
			return (0);
		if (!append((int)value, a))
			return (0);
		count++;
		if (argv[i] == '+' || argv[i] == '-')
			i++;
		while (ft_isdigit(argv[i]))
			i++;
	}
	return (count > 0);
}
