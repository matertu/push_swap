/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouza-t <msouza-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:10:55 by msouza-t          #+#    #+#             */
/*   Updated: 2026/06/18 16:52:38 by msouza-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count_char;

	if (!format)
		return (-1);
	va_start(args, format);
	count_char = ft_scanstring(format, &args);
	va_end(args);
	return (count_char);
}

int	ft_printparamter(va_list *args, char type)
{
	int	c;

	c = 0;
	if (!type)
		return (-1);
	else if (type == 'c')
		c = ft_putchar(va_arg(*args, int));
	else if (type == 's')
		c = ft_putstr(va_arg(*args, char *));
	else if (type == 'p')
		c = ft_putptr(va_arg(*args, void *));
	else if (type == 'd' || type == 'i')
		c = ft_putnbr(va_arg(*args, int));
	else if (type == 'u')
		c = ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (type == 'x')
		ft_puthex(va_arg(*args, unsigned int), 0, &c);
	else if (type == 'X')
		ft_puthex(va_arg(*args, unsigned int), 1, &c);
	else if (type == '%')
		c = ft_putchar('%');
	else
		return (-1);
	return (c);
}

int	ft_scanstring(const char *s, va_list *args)
{
	int	i;
	int	count_char;
	int	return_value;

	i = 0;
	count_char = 0;
	return_value = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			return_value = ft_printparamter(args, s[++i]);
			if (return_value == -1)
				return (-1);
		}
		else
			return_value = ft_putchar(s[i]);
		if (return_value == -1)
			return (-1);
		count_char += return_value;
		i++;
	}
	return (count_char);
}
