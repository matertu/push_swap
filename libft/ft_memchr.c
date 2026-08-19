/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:59:21 by msouza-t          #+#    #+#             */
/*   Updated: 2026/06/12 12:11:27 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*v;
	size_t				i;

	v = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (v[i] == (unsigned char)c)
			return ((void *)&v[i]);
		i++;
	}
	return (NULL);
}
