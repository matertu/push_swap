/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:43:03 by matheus           #+#    #+#             */
/*   Updated: 2026/08/19 22:27:11 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    int     			start;
    t_flags 			flags;
	t_bench				relatory;
    t_stack  			a;
    t_stack  			b;

	a.first = NULL;
	a.top = NULL;
	b.first = NULL;
	b.top = NULL;
    if (argc < 2)
        return (0);
    start = validate_input(argc, argv, &flags);
    if (start)
    {
		if (compile_list(&a, start, argc, argv))
		{
			if (run_algorithm(a, b, &flags, &relatory))
			{
				print_list(&a);
				free_stack(&a);
				return (0);
			}
		}
		else
		put_error();
		return (0);
    }
    return (-1);
}

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// #define RESET   "\033[0m"
// #define BOLD    "\033[1m"
// #define CYAN    "\033[36m"
// #define YELLOW  "\033[33m"
// #define GREEN   "\033[32m"
// #define MAGENTA "\033[35m"

// static void	print_bar(int value, char *color)
// {
// 	int	len;
// 	int	i;

// 	len = (value < 0 ? -value : value);
// 	if (len > 15)
// 		len = 15;
// 	if (len == 0)
// 		len = 1;
// 	ft_putstr_fd(color, 1);
// 	i = 0;
// 	while (i < len)
// 	{
// 		ft_putstr_fd("█", 1);
// 		i++;
// 	}
// 	ft_putstr_fd(RESET, 1);
// }

// void	print_single_stack(t_stack *s, char *name, char *color)
// {
// 	t_node	*curr;
// 	int		size;
// 	int		pos;

// 	size = stack_size(s);
// 	printf(BOLD "--- %s (Tamanho: %d) ---\n" RESET, name, size);
// 	if (!s || !s->first || size == 0)
// 	{
// 		ft_putstr_fd("  (vazia)\n\n", 1);
// 		return ;
// 	}
// 	curr = s->first;
// 	pos = 1;
// 	while (1)
// 	{
// 		// Exibe a posição, o valor numérico e a barra gráfica
// 		printf("  [%02d] %-8d ", pos, curr->item);
// 		print_bar(curr->item, color);
// 		ft_putchar_fd('\n', 1);
// 		if (curr == s->top)
// 			break ;
// 		curr = curr->next;
// 		pos++;
// 	}
// 	ft_putchar_fd('\n', 1);
// }

// void	print_cli_stacks(t_stack *a, t_stack *b, char *last_op, int ops)
// {
// 	// Limpa o terminal e joga o cursor no topo
// 	ft_putstr_fd("\033[H\033[J", 1);

// 	ft_putstr_fd(BOLD CYAN "================ PUSH_SWAP CLI INTERATIVO ================\n" RESET, 1);
// 	printf(BOLD YELLOW "Última Ação: %-12s " RESET BOLD "Total de Operações: %d\n" RESET, last_op, ops);
// 	ft_putstr_fd("==========================================================\n\n", 1);

// 	// Imprime STACK A em sequência
// 	print_single_stack(a, "STACK A", GREEN);

// 	// Imprime STACK B em sequência
// 	print_single_stack(b, "STACK B", MAGENTA);

// 	ft_putstr_fd(BOLD CYAN "==========================================================\n" RESET, 1);
// 	ft_putstr_fd(BOLD "Comandos: [sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr, exit]\n" RESET, 1);
// 	ft_putstr_fd("push_swap> ", 1);
// }

// int	execute_op(t_stack *a, t_stack *b, char *op)
// {
// 	if (!ft_strncmp(op, "sa", 3))
// 		return (sa(a, 0));
// 	if (!ft_strncmp(op, "sb", 3))
// 		return (sb(b, 0));
// 	if (!ft_strncmp(op, "ss", 3))
// 		return (ss(a, b, 0));
// 	if (!ft_strncmp(op, "pa", 3))
// 		return (pa(a, b, 0));
// 	if (!ft_strncmp(op, "pb", 3))
// 		return (pb(a, b, 0));
// 	if (!ft_strncmp(op, "ra", 3))
// 		return (ra(a, 0));
// 	if (!ft_strncmp(op, "rb", 3))
// 		return (rb(b, 0));
// 	if (!ft_strncmp(op, "rr", 3))
// 		return (rr(a, b, 0));
// 	if (!ft_strncmp(op, "rra", 4))
// 		return (rra(a, 0));
// 	if (!ft_strncmp(op, "rrb", 4))
// 		return (rrb(b, 0));
// 	if (!ft_strncmp(op, "rrr", 4))
// 		return (rrr(a, b, 0));
// 	return (-1);
// }

// void	interactive_cli(t_stack *a, t_stack *b)
// {
// 	char	buffer[32];
// 	int		ops;
// 	int		len;

// 	ops = 0;
// 	print_cli_stacks(a, b, "START", ops);
// 	while (1)
// 	{
// 		if (!fgets(buffer, sizeof(buffer), stdin))
// 			break ;
// 		len = 0;
// 		while (buffer[len] && buffer[len] != '\n')
// 			len++;
// 		buffer[len] = '\0';

// 		if (!ft_strncmp(buffer, "exit", 5) || !ft_strncmp(buffer, "q", 2))
// 			break ;

// 		if (execute_op(a, b, buffer) != -1)
// 		{
// 			ops++;
// 			print_cli_stacks(a, b, buffer, ops);
// 		}
// 		else
// 		{
// 			print_cli_stacks(a, b, "COMANDO INVÁLIDO", ops);
// 		}
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int		start;
// 	t_flags	flags;
// 	t_stack	a;
// 	t_stack	b;

// 	if (argc < 2)
// 		return (0);

// 	a.first = NULL;
// 	a.top = NULL;
// 	b.first = NULL;
// 	b.top = NULL;

// 	start = validate_input(argc, argv, &flags);
// 	if (start)
// 	{
// 		if (compile_list(&a, start, argc, argv))
// 		{
// 			interactive_cli(&a, &b);
// 			free_stack(&a);
// 			free_stack(&b);
// 			return (0);
// 		}
// 		else
// 		{
// 			put_error();
// 			return (0);
// 		}
// 	}
// 	put_error();
// 	return (0);
// }
