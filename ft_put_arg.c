/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:59:04 by gstitou           #+#    #+#             */
/*   Updated: 2024/11/19 17:47:16 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
void ft_put_arg(char sep, va_list args, int *counter)
{
    if (sep == 'd' || sep == 'i')
    {
        ft_putnbr_fd(va_arg(args, int), 1, counter);
    }
    else if (sep == 'c')
    {
        ft_putchar_fd((char)va_arg(args, int), 1, counter);
    }
    else if (sep == 's')
    {
        // char *str = var_arg(args, char *);
        ft_putstr_fd(va_arg(args, char *), 1, counter);
    }
    else if (sep == 'p')
    {
        if(va_arg(args,int *)==NULL)
        (*counter)+=write(1,"(nil)",6);
        else ft_convert_to_hex(args,&counter);
    }
}
