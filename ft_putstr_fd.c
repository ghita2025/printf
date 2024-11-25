/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:17:29 by gstitou           #+#    #+#             */
/*   Updated: 2024/11/25 08:46:23 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(va_list args, int fd, int *counter)
{
	char	*str;
	int		i;

	str = va_arg(args, char *);
	i = 0;
	if (!str)
		(*counter) += write(1, "(null)", 6);
	else
	{
		i = 0;
		while (str[i])
		{
			write(fd, &str[i], 1);
			i++;
		}
		(*counter) += i;
	}
}
