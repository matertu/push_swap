/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pilha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 21:01:48 by msouza-t          #+#    #+#             */
/*   Updated: 2026/09/17 01:37:55 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(int x)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->item = x;
	n->index = 0;
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

void	rank_values(t_stack *stack)
{
	t_node	*pívot;
	t_node	*comp;
	int		size;
	int		i;
	int		j;

	size = stack_size(stack);
	pívot = stack->first;
	i = 0;
	while (i < size)
	{
		comp = stack->first;
		j = 0;
		while (j < size)
		{
			if (comp->item < pívot->item)
				pívot->index++;
			comp = comp->next;
			j++;
		}
		pívot = pívot->next;
		i++;
	}
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

int	ra(t_stack *a, t_bench *bench)
{
	shift_up(a);
	if (bench)
	{
		if (bench->print)
			write(1, "ra\n", 3);
		bench->ra++;
		bench->total_ops++;
	}
	return (1);
}

int	rb(t_stack *b, t_bench *bench)
{
	shift_up(b);
	if (bench)
	{
		if (bench->print)
			write(1, "rb\n", 3);
		bench->rb++;
		bench->total_ops++;
	}
	return (1);
}

int	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	shift_up(a);
	shift_up(b);
	if (bench)
	{
		if (bench->print)
			write(1, "rr\n", 3);
		bench->rr++;
		bench->total_ops++;
	}
	return (1);
}

int	rra(t_stack *a, t_bench *bench)
{
	shift_down(a);
	if (bench)
	{
		if (bench->print)
			write(1, "rra\n", 4);
		bench->rra++;
		bench->total_ops++;
	}
	return (1);
}

int	rrb(t_stack *b, t_bench *bench)
{
	shift_down(b);
	if (bench)
	{
		if (bench->print)
			write(1, "rrb\n", 4);
		bench->rrb++;
		bench->total_ops++;
	}
	return (1);
}

int	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	shift_down(a);
	shift_down(b);
	if (bench)
	{
		if (bench->print)
			write(1, "rrr\n", 4);
		bench->rrr++;
		bench->total_ops++;
	}
	return (1);
}

int	sa(t_stack *a, t_bench *bench)
{
	swap(a);
	if (bench)
	{
		if (bench->print)
			write(1, "sa\n", 3);
		bench->sa++;
		bench->total_ops++;
	}
	return (1);
}

int	sb(t_stack *b, t_bench *bench)
{
	swap(b);
	if (bench)
	{
		if (bench->print)
			write(1, "sb\n", 3);
		bench->sb++;
		bench->total_ops++;
	}
	return (1);
}

int	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	swap(a);
	swap(b);
	if (bench)
	{
		if (bench->print)
			write(1, "ss\n", 3);
		bench->ss++;
		bench->total_ops++;
	}
	return (1);
}

int	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*node;

	if (!b || !b->first)
		return (0);
	node = pop_first(b);
	if (!node)
		return (0);
	push_first(node, a);
	if (bench)
	{
		if (bench->print)
			write(1, "pa\n", 3);
		bench->pa++;
		bench->total_ops++;
	}
	return (1);
}

int	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*node;

	if (!a || !a->first)
		return (0);
	node = pop_first(a);
	if (!node)
		return (0);
	push_first(node, b);
	if (bench)
	{
		if (bench->print)
			write(1, "pb\n", 3);
		bench->pb++;
		bench->total_ops++;
	}
	return (1);
}
