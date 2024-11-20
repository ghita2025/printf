/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:18:06 by gstitou           #+#    #+#             */
/*   Updated: 2024/11/20 13:25:18 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_putnbr_fd(int num, int fd, int *counter)
{
	long nb;
	char c;

	nb = num;
	if (nb < 0)
	{
		(*counter) += write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd, counter);
	}
	c = (nb % 10) + '0';
	(*counter) += write(fd, &c, 1);
}