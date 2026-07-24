/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core_operations                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:58:47 by matheus           #+#    #+#             */
/*   Updated: 2026/07/24 00:33:38 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

t_node	*node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int	empty_list(t_list *list)
{
	if (!list || list->top == NULL)
		return (1);
	return (0);
}

int	append(t_list *list, int value)
{
	t_node	*new_node;
	t_node	*current;

	if (!list)
		return (0);
	new_node = node(value);
	if (!new_node)
		return (0);
	if (empty_list(list))
		list->top = new_node;
	else
	{
		current = list->top;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	list->size++;
	return (1);
}
void	free_list(t_list *list)
{
	t_node	*current;
	t_node	*next_node;

	if (empty_list(list))
		return ;
	current = list->top;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	list->top = NULL;
	list->size = 0;
}
