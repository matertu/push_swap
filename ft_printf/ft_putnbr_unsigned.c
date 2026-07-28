/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:52:31 by msouza-t          #+#    #+#             */
/*   Updated: 2026/06/15 16:44:00 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	ret;
	int	count;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putnbr_unsigned(n / 10);
		if (add_count(&count, ret) == -1)
			return (-1);
	}
	ret = ft_putchar(int_to_char(n % 10));
	if (add_count(&count, ret) == -1)
		return (-1);
	return (count);
}
