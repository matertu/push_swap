/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:57:41 by matheus           #+#    #+#             */
/*   Updated: 2026/08/01 02:59:26 by msouza-t         ###   ########.fr       */
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
	t_node	list;

	i = start;
	list = NULL;
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		if (!add_node(&list, value))
		{
			destroy_list(&list);
			return (0);
		}
		a->size++;
		i++;
	}
	a->top = &list;
	return (1);
}

int	compile_string_list(t_stack *a, char *argv)
{
	int		i;
	long	value;
	t_node	list;

	i = 0;
	list = NULL;
	while (argv[i])
	{
		while (argv[i] && ft_isspace(argv[i]))
			i++;
		if (argv[i] == '\0')
			break ;
		value = ft_atol(&argv[i]);
		if (!add_node(&list, value))
		{
			destroy_list(&list);
			return (0);
		}
		a->size++;
		i += isnumber(&argv[i]);
	}
	a->top = &list;
	return (1);
}

int	add_node(t_node *list, long value)
{
	t_node	new;

	if (to_long(value) || contains(value, *list))
		return (0);
	if (*list == NULL)
	{
		new = new_node((int)value);
		if (!new)
			return (0);
		*list = new;
	}
	else
	{
		if (!insert((int)value, *list))
			return (0);
	}
	return (1);
}
