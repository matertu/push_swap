/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheus <matheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:13:54 by msouza-t          #+#    #+#             */
/*   Updated: 2026/07/24 03:18:11 by matheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H 
# define FT_PUSH_SWAP_H 

# include <stdlib.h> 
# include <stdio.h> 

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

#endif
