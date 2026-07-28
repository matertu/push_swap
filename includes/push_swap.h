/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:13:54 by msouza-t          #+#    #+#             */
/*   Updated: 2026/07/27 23:04:35 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H 
# define FT_PUSH_SWAP_H 

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h> 
# include <stdio.h> 
# include <unistd.h>

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

typedef enum e_algorithm
{
	none = 0,
	simple,
	medium,
	complex,
	adaptive,
}	t_algorithm;

typedef struct s_flags
{
	int			bench;
	t_algorithm	algorithm;
}	t_flags;

typedef struct s_bench_relatory
{
    double     	disorder;
    t_algorithm *algorithm;
    int         total_ops;
    int         sa;
    int         sb;
    int         ss;
    int         pa;
    int         pb;
    int         ra;
    int         rb;
    int         rr;
    int         rra;
    int         rrb;
    int         rrr;
}   t_bench_relatory;

int		validate_input(int argc, char **argv, t_flags *flags);
int 	isnumber(char *arg);
void	put_error();
int		ft_isspace(char c);
int		ft_strcmp(const char *s1, const char *s2);
int		check_flags(int argc, char **argv, t_flags *flags);
int		check_string_arg(char *arg);
int		check_matrix_arg(int argc, char **argv, int start);

#endif
