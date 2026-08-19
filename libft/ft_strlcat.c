/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:52:34 by msouza-t          #+#    #+#             */
/*   Updated: 2026/06/12 13:06:00 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dst_size;
	size_t	copied_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dst_size >= size)
		return (size + src_size);
	copied_size = dst_size;
	i = 0;
	while (src[i] && copied_size + 1 < size)
	{
		dst[copied_size] = src[i];
		i++;
		copied_size++;
	}
	dst[copied_size] = '\0';
	return (dst_size + src_size);
}
