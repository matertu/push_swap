/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:36:20 by msouza-t          #+#    #+#             */
/*   Updated: 2026/06/15 20:17:51 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putletter(int i, int isupper)
{
	if (isupper)
		ft_putchar('A' + i - 10);
	else
		ft_putchar('a' + i - 10);
	return (1);
}

void	ft_puthex(unsigned int i, int isupper, int *count)
{
	if (i >= 16)
	{
		ft_puthex(i / 16, isupper, count);
	}
	if (i % 16 > 9)
	{
		ft_putletter(i % 16, isupper);
		*count += 1;
	}
	else
	{
		ft_putchar(int_to_char(i % 16));
		*count += 1;
	}
}

void	ft_puthex_long(unsigned long i, int *count)
{
	if (i >= 16)
	{
		ft_puthex_long(i / 16, count);
	}
	if (i % 16 > 9)
	{
		ft_putletter(i % 16, 0);
		*count += 1;
	}
	else
	{
		ft_putchar(int_to_char(i % 16));
		*count += 1;
	}
}
