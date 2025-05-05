/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:34:30 by gstitou           #+#    #+#             */
/*   Updated: 2024/12/04 20:41:06 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_percent(char c)
{
	return (c == '%');
}

int	is_format(char c)
{
	return (c == 'd' || c == 'i' || c == 'p' || c == 'u' || c == 'x' || c == 'X'
		|| c == 's' || c == 'c' || c == '%');
}

void	print(const char **str, int *counter)
{
	while (**str && !is_percent(**str))
	{
		*counter += write(1, *str, 1);
		(*str)++;
	}
}

void	handle_percent(const char **format, va_list args, int *counter)
{
	(*format)++;
	if (!**format)
	{
		write(1, "%", 1);
		*counter = -1;
		return ;
	}
	if (is_format(**format))
		ft_put_arg(**format, args, counter);
	else
	{
		*counter += write(1, "%", 1);
		*counter += write(1, *format, 1);
	}
	(*format)++;
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	counter = 0;
	while (*format)
	{
		print(&format, &counter);
		if (is_percent(*format))
			handle_percent(&format, args, &counter);
	}
	va_end(args);
	return (counter);
}
