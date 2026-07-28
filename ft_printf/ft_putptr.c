/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:28:24 by msouza-t          #+#    #+#             */
/*   Updated: 2026/06/15 20:19:42 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long int	p;
	int					count;
	int					return_value;

	count = 0;
	p = (unsigned long int)ptr;
	if (!p)
	{
		return_value = ft_putstr("(nil)");
		if (add_count(&count, return_value) == -1)
			return (-1);
		return (count);
	}
	return_value = ft_putstr("0x");
	if (add_count(&count, return_value) == -1)
		return (-1);
	ft_puthex_long(p, &count);
	return (count);
}
