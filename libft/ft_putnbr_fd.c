/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:52:31 by msouza-t          #+#    #+#             */
/*   Updated: 2026/05/28 16:08:56 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	int_to_char(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return ('\0');
}

void	ft_putnbr_fd(int n, int fd)
{
	int		c;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * (-1);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		c = nb % 10;
		ft_putchar_fd(int_to_char(c), fd);
	}
	if (nb < 10)
		ft_putchar_fd(int_to_char(nb), fd);
}
