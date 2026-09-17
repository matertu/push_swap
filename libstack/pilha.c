/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pilha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/13 23:12:35 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pilha.h"

/* ================================================================= */
/* ESTRUTURA                                                          */
/* ================================================================= */

t_node	*new_node(int x)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->item = x;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

int	push(t_node *node, t_stack *stack)
{
	if (!stack || !node)
		return (0);
	if (!stack->first)
	{
		node->next = node;
		node->prev = node;
		stack->first = node;
	}
	else
	{
		node->prev = stack->first->prev;
		node->next = stack->first;
		stack->first->prev->next = node;
		stack->first->prev = node;
	}
	return (1);
}

int	push_first(t_node *node, t_stack *stack)
{
	if (!stack || !node)
		return (0);
	if (!stack->first)
	{
		node->next = node;
		node->prev = node;
		stack->first = node;
	}
	else
	{
		node->prev = stack->first->prev;
		node->next = stack->first;
		stack->first->prev->next = node;
		stack->first->prev = node;
		stack->first = node;
	}
	return (1);
}

int	append(int value, t_stack *stack)
{
	t_node	*node;

	node = new_node(value);
	if (!node)
	{
		free_stack(stack);
		return (0);
	}
	push(node, stack);
	return (1);
}

/* remove a0 (visual top) */
t_node	*pop_first(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->first)
		return (NULL);
	node = stack->first;
	if (node->next == node)
		stack->first = NULL;
	else
	{
		stack->first = node->next;
		stack->first->prev = node->prev;
		node->prev->next = stack->first;
	}
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	if (!stack || !stack->first)
		return ;
	stack->first->prev->next = NULL;
	current = stack->first;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack->first = NULL;
}

int	stack_size(t_stack *stack)
{
	int		count;
	t_node	*current;

	if (!stack || !stack->first)
		return (0);
	count = 1;
	current = stack->first;
	while (current->next != stack->first)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	contains(int x, t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->first)
		return (0);
	current = stack->first;
	while (1)
	{
		if (current->item == x)
			return (1);
		current = current->next;
		if (current == stack->first)
			break ;
	}
	return (0);
}

void	print_list(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->first)
		return ;
	current = stack->first;
	while (1)
	{
		printf("%d\n", current->item);
		current = current->next;
		if (current == stack->first)
			break ;
	}
}

static int	shift_up(t_stack *a)
{
	if (!a || !a->first || a->first->next == a->first)
		return (1);
	a->first = a->first->next;
	return (1);
}

static int	shift_down(t_stack *a)
{
	if (!a || !a->first || a->first->next == a->first)
		return (1);
	a->first = a->first->prev;
	return (1);
}

static int	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->first || stack->first->next == stack->first)
		return (0);
	temp = stack->first->item;
	stack->first->item = stack->first->next->item;
	stack->first->next->item = temp;
	return (1);
}

int	ra(t_stack *a, int print)
{
	shift_up(a);
	if (print)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack *b, int print)
{
	shift_up(b);
	if (print)
		write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack *a, t_stack *b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
	return (1);
}

int	rra(t_stack *a, int print)
{
	shift_down(a);
	if (print)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack *b, int print)
{
	shift_down(b);
	if (print)
		write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
	return (1);
}

int	sa(t_stack *a, int print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack *b, int print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack *a, t_stack *b, int print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
	return (1);
}

int	pa(t_stack *a, t_stack *b, int print)
{
	t_node	*node;

	if (!b || !b->first)
		return (0);
	node = pop_first(b);
	if (!node)
		return (0);
	push_first(node, a);
	if (print)
		write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack *a, t_stack *b, int print)
{
	t_node	*node;

	if (!a || !a->first)
		return (0);
	node = pop_first(a);
	if (!node)
		return (0);
	push_first(node, b);
	if (print)
		write(1, "pb\n", 3);
	return (1);
}
