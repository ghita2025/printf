/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:46:55 by gstitou           #+#    #+#             */
/*   Updated: 2024/11/19 16:18:32 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str);
int valide_base(char *base);
int ft_atoi(char *str, int *ptr_i);
int ft_atoi_base(char *str, char *base);

char *ft_strcat(char *dest, char *src, int pos)
{
	int i;
	int dlen;

	i = 0;
	dlen = ft_strlen(dest);
	while (src[i] && i < pos)
	{
		dest[i + dlen] = src[i];
		i++;
	}
	dest[i + dlen] = 0;
	return (dest);
}

int base_to_len(long nbr, char *base)
{
	long max;
	int count;
	int len_base;

	max = 1;
	count = 1;
	len_base = ft_strlen(base);
	if (nbr == 0)
	{
		return (2);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (max <= nbr)
	{
		max *= len_base;
		count++;
	}
	return (count);
}

void ft_nbr_base(long nb, char *base, char *str)
{
	int len_base;
	int i;

	len_base = ft_strlen(base);
	i = 0;
	if (nb < 0)
	{
		ft_strcat(str, "-", 1);
		nb = -nb;
	}
	if (nb >= len_base)
	{
		ft_nbr_base(nb / len_base, base, str);
		ft_nbr_base(nb % len_base, base, str);
	}
	else
		ft_strcat(str, &base[nb], 1);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long nb;
	int count;
	char *str;

	if (!valide_base(base_from) || !valide_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	count = base_to_len(nb, base_to);
	str = (char *)malloc(sizeof(char) * count);
	if (!str)
		return (NULL);
	ft_nbr_base(nb, base_to, str);
	return (str);
}
