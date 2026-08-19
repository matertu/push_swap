/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:27:59 by msouza-t          #+#    #+#             */
/*   Updated: 2026/06/12 12:32:46 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	count_list_size(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count + 1);
}

static int	create_list(char const *s, char c, char **list)
{
	int	i;
	int	len;
	int	start;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			list[len] = ft_substr(s, start, i - start);
			if (!list[len])
				return (-1);
			len++;
		}
	}
	list[len] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	int		i;

	if (!s)
		return (NULL);
	list = malloc(count_list_size(s, c) * sizeof(char *));
	if (!list)
		return (NULL);
	if (create_list(s, c, list) == -1)
	{
		i = 0;
		while (list[i])
			free(list[i++]);
		free(list);
		return (NULL);
	}
	return (list);
}
