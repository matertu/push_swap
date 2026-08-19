/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:45:44 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/18 18:54:36 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printerr.h"

int	ft_putfloat(float num)
{
	long	integer_part;
	long	dec;
	int		count;

	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	integer_part = (long)num;
	dec = (long)((num - (float)integer_part) * 100.0f + 0.5f);
	if (dec >= 100)
	{
		integer_part++;
		dec = 0;
	}
	count += ft_putnbr(integer_part);
	count += ft_putchar('.');
	if (dec < 10)
		count += ft_putchar('0');
	count += ft_putnbr(dec);
	return (count);
}