/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:50:08 by gstitou           #+#    #+#             */
/*   Updated: 2024/11/25 08:45:14 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned_fd(va_list args, int fd, int *counter)
{
	unsigned int	num;
	char			buffer[10];
	int				i;
	char			c;

	num = va_arg(args, unsigned int);
	i = 0;
	if (num == 0)
	{
		c = '0';
		(*counter) += write(fd, &c, 1);
		return ;
	}
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (--i >= 0)
		(*counter) += write(fd, &buffer[i], 1);
}
