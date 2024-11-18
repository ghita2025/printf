/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:34:30 by gstitou           #+#    #+#             */
/*   Updated: 2024/11/18 18:43:32 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
int is_percent(char c)
{
    return (c == '%');
}
void print(char **str, int *counter)
{
    while (**str && !is_percent(*str))
    {
        write(1, *str, 1);
        (*str)++;
        (*counter)++;
    }
}

int ft_printf(const char *format, ...)
{
    int counter;
    va_list args;

    if (!format)
        return (0);

    va_start(args, format);
    counter = 0;
    while (*format)
    {
        if (!is_percent(*format))
        print(&format, &counter);
        if (is_percent(*format))
        {
            format++;
            if(*format == c || *format == s || *format == p ||*format == d ||*format == i ||*format == u ||*format == x ||*format == X )
            ft_put_arg(*format, args, &counter);
            else
            write(1,'%',1);
            format++;
        }
    }
    va_end(args);
    return (counter);
}
int main()
{
    int c =ft_printf("this is life %d %s\n",22,ghita);
    printf("%d",c);
}