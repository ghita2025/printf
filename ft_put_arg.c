/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:59:04 by gstitou           #+#    #+#             */
/*   Updated: 2024/11/18 18:17:37 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
void ft_put_arg(char sep, va_list args, int *counter)
{
    if (sep == 'd' || sep)
    {
        //int num = va_arg(args, int)
            ft_putnbr_fd(va_arg(args, int), 1, &counter);
    }
    else if (sep == 'c')
    {
        write(1, &(char)(var_arg(args, int)), 1);
        (*counte)++;
    }
    else if (sep == 's')
    {
        //char *str = var_arg(args, char *);
        ft_putstr_fd(var_arg(args, char *), 1, &counter);
    }
    else if (sep == 'p')
    {
        int *p=var_arg(args, char *);
        
    }
}
 