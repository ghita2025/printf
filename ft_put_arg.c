/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:59:04 by gstitou           #+#    #+#             */
/*   Updated: 2024/11/25 14:29:01 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_adress(va_list args, int *counter)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		(*counter) += write(1, "(nil)", 5);
	else
	{
		(*counter) += write(1, "0x", 2);
		ft_convert_to_hex((unsigned long)ptr, 'x', counter);
	}
	
}

void	ft_put_arg(char sep, va_list args, int *counter)
{
	if (sep == '%')
		(*counter) += write(1, "%%", 1);
	else if (sep == 'd' || sep == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, counter);
	else if (sep == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1, counter);
	else if (sep == 's')
		ft_putstr_fd(args, 1, counter);
	else if (sep == 'p')
		print_adress(args, counter);
	else if (sep == 'x' || sep == 'X')
		ft_convert_to_hex(va_arg(args, unsigned int), sep, counter);
	else if (sep == 'u')
		ft_putunsigned_fd(args, 1, counter);
}
