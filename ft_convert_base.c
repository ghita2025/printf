/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:49:54 by gstitou           #+#    #+#             */
/*   Updated: 2024/08/14 22:49:59 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	valide_base(char *base)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	while (i < len)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi(char *str, int *ptr_i)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*ptr_i = i;
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	nbr;
	int	len;
	int	i;
	int	j;

	sign = ft_atoi(str, &i);
	nbr = 0;
	len = ft_strlen(base);
	while (str[i])
	{
		j = 0;
		while (str[i] != base[j] && base[j])
			j++;
		if (base[j] == '\0')
			break ;
		nbr = nbr * len + j;
		i++;
	}
	return (nbr * sign);
}
