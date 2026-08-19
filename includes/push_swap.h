/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:13:54 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/18 17:57:37 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../ft_printerr/ft_printerr.h"
# include "../libft/libft.h"
# include "../stack/stack.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_algorithm
{
	none = 0,
	simple,
	medium,
	complex,
	adaptive,
}				t_algorithm;

typedef struct s_flags
{
	int			bench;
	t_algorithm	algorithm;
}				t_flags;

typedef struct s_bench_relatory
{
	double		disorder;
	t_algorithm	*algorithm;
	int			total_ops;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}				t_bench;

int				validate_input(int argc, char **argv, t_flags *flags);
int				isnumber(char *arg);
void			put_error(void);
int				ft_isspace(char c);
int				ft_strcmp(const char *s1, const char *s2);
int				check_flags(int argc, char **argv, t_flags *flags);
int				check_string_arg(char *arg);
int				check_matrix_arg(int argc, char **argv, int start);
long			ft_atol(const char *nptr);
int				to_long(long value);
int				compile_list(t_stack *a, int start, int argc, char **argv);
int				compile_arg_list(t_stack *a, int start, int argc, char **argv);
int				compile_string_list(t_stack *a, char *argv);
int				add_node(t_node *list, long value);

#endif
