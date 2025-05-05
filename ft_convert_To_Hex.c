/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_To_Hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:04:18 by gstitou           #+#    #+#             */
/*   Updated: 2024/12/04 20:40:53 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_to_hex(unsigned long nb, char sep, int *counter)
{
	char	res[16];
	int		i;
	char	*f;

	if (sep == 'x')
		f = "0123456789abcdef";
	else
		f = "0123456789ABCDEF";
	i = 0;
	if (nb == 0)
	{
		ft_putchar_fd('0', 1, counter);
		return ;
	}
	while (nb > 0)
	{
		res[i++] = f[nb % 16];
		nb /= 16;
	}
	while (--i >= 0)
	{
		ft_putchar_fd(res[i], 1, counter);
	}
}
