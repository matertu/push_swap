/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:13:54 by msouza-t          #+#    #+#             */
/*   Updated: 2026/07/26 17:47:29 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H 
# define FT_PUSH_SWAP_H 

# include <stdlib.h> 
# include <stdio.h> 
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*top;
	int		size;
}	t_list;

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

int		validate_input(int argc, char **argv, t_flags *flags);
void	print_error();
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_strlen(char *s);
int		ft_isspace(char c);
int		ft_strcmp(const char *s1, const char *s2);
int		check_flags(int argc, char **argv, t_flags *flags);
int		check_string_arg(char *arg);
int		check_matrix_arg(int argc, char **argv, int start);

#endif
