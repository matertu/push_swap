/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:52:31 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/18 17:57:37 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printerr.h"

int	ft_putnbr(int n)
{
	int		ret;
	int		count;
	long	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		ret = ft_putchar('-');
		if (add_count(&count, ret) == -1)
			return (-1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ret = ft_putnbr(nb / 10);
		if (add_count(&count, ret) == -1)
			return (-1);
	}
	ret = ft_putchar(int_to_char(nb % 10));
	if (add_count(&count, ret) == -1)
		return (-1);
	return (count);
}
