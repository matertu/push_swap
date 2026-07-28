/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:08:52 by msouza-t          #+#    #+#             */
/*   Updated: 2026/06/11 15:26:13 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_count(int *count, int ret)
{
	if (ret == -1)
		return (-1);
	*count += ret;
	return (0);
}

char	int_to_char(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return ('\0');
}
