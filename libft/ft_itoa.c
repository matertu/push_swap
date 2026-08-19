/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:12:11 by msouza-t          #+#    #+#             */
/*   Updated: 2026/06/12 11:45:43 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		count += 1;
	while (n != 0)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	long	nb;
	char	*str;

	len = count_digit(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	nb = n;
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
		str[0] = '0';
	i = len - 1;
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
