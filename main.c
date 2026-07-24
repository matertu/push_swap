/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:43:03 by matheus           #+#    #+#             */
/*   Updated: 2026/07/23 20:48:04 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (check_input(argc, argv))
	{
		if (create_stack(argc, argv))
		{
			run_algorithm(stack a, stack b, algorithm type);
		}
	}
}
