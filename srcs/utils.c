/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:27:30 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/26 20:06:00 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

void	put_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

long	ft_atol(const char *nptr)
{
	long	cont;
	int		sign;
	int		i;

	cont = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		cont = (cont * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * cont);
}

int	to_long(long value)
{
	if (value > 2147483647 || value < -2147483648)
		return (1);
	return (0);
}
