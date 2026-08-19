/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:12:19 by msouza-t          #+#    #+#             */
/*   Updated: 2026/08/18 17:55:38 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTERR_H
# define FT_PRINTERR_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printerr(const char *format, ...);
int		ft_printparamter(va_list *args, char type);
int		ft_scanstring(const char *s, va_list *args);
int		ft_putletter_upper(int i);
int		ft_putletter_lower(int i);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr(int n);
int		add_count(int *count, int ret);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putptr(void *ptr);
char	int_to_char(int n);
void	ft_puthex(unsigned int i, int isupper, int *count);
void	ft_puthex_long(unsigned long i, int *count);
void	ft_puthex(unsigned int i, int isupper, int *count);
int		ft_putfloat(double num);

#endif