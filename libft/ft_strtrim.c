/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:09:43 by msouza-t          #+#    #+#             */
/*   Updated: 2026/06/12 13:47:08 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_points(char const *s1, char const *set, char where)
{
	int	start;

	if (where == 's')
	{
		start = 0;
		while (s1[start] != '\0' && ft_strchr(set, s1[start]))
			start++;
		return ((char *)&s1[start]);
	}
	else if (where == 'e')
	{
		start = ft_strlen(s1) - 1;
		while (start >= 0 && ft_strchr(set, s1[start]))
			start--;
		return ((char *)&s1[start]);
	}
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	char	*s_start;
	char	*s_end;

	if (!s1 || !set)
		return (NULL);
	s_start = find_points(s1, set, 's');
	s_end = find_points(s1, set, 'e');
	if (s_start > s_end)
		dest = ft_substr(s_start, 0, 0);
	else
		dest = ft_substr(s_start, 0, (s_end - s_start) + 1);
	return (dest);
}
