/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:13:33 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/27 11:15:00 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_number(char *arg)
{
	int	i;

	if (!arg || arg[0] == '\0')
		return (0);
	i = 0;
	while (ft_isspace(arg[i]))
		i++;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (!ft_isdigit(arg[i]))
		return (0);
	while (ft_isdigit(arg[i]))
		i++;
	while (ft_isspace(arg[i]))
		i++;
	if (arg[i] != '\0')
		return (0);
	return (i);
}

int	check_matrix_arg(int argc, char **argv, int start)
{
	int	idx;

	idx = start;
	while (idx < argc)
	{
		if (!is_number(argv[idx]))
			return (0);
		idx++;
	}
	return (start);
}

int	check_string_arg(char *arg)
{
	int	i;
	int	count;

	if (!arg || arg[0] == '\0')
		return (0);
	i = 0;
	count = 0;
	while (arg[i])
	{
		while (arg[i] && ft_isspace(arg[i]))
			i++;
		if (arg[i] == '\0')
			break ;
		if (arg[i] == '+' || arg[i] == '-')
			i++;
		if (!ft_isdigit(arg[i]))
			return (0);
		while (ft_isdigit(arg[i]))
			i++;
		if (arg[i] != '\0' && !ft_isspace(arg[i]))
			return (0);
		count++;
	}
	return (count > 0);
}

