/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/01 02:08:15 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_node	new_node(t_item x)
{
	t_node	n;

	n = malloc(sizeof(struct s_node));
	if (!n)
		return (NULL);
	n->item = x;
	n->next = NULL;
	return (n);
}

void	append(t_node *A, t_node B)
{
	if (B == NULL)
		return ;
	while (*A != NULL)
		A = &(*A)->next;
	*A = B;
}

void	destroy_list(t_node *L)
{
	t_node	n;

	while (*L != NULL)
	{
		n = *L;
		*L = n->next;
		free(n);
	}
}

int	list_size(t_node L)
{
	if (L == NULL)
		return (0);
	return (1 + list_size(L->next));
}

int	contains(t_item x, t_node L)
{
	if (L == NULL)
		return (0);
	if (x == L->item)
		return (1);
	return (contains(x, L->next));
}
t_item	get_last(t_node L)
{
	if (!L)
		return (0);
	while (L->next)
		L = L->next;
	return (L->item);
}

int	insert(t_item x, t_node l)
{
	t_node	temp;

	if (!l)
		return (0);
	while (l->next)
		l = l->next;
	temp = new_node(x);
	if (!temp)
		return (0);
	l->next = temp;
	return (1);
}

void	print_list(t_node list)
{
	t_node	current;

	current = list;
	while (current != NULL)
	{
		ft_printf("%d\n", current->item);
		current = current->next;
	}
}
