/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstitou <gstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:34:30 by gstitou           #+#    #+#             */
/*   Updated: 2024/11/20 14:37:21 by gstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
int is_percent(char c)
{
    return (c == '%');
}
void print(const char **str, int *counter)
{
    while (**str && !is_percent(**str))
    {
        (*counter) += write(1, *str, 1);
        (*str)++;
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
            ft_put_arg(*format, args, &counter);
            format++;
        }
    }
    va_end(args);
    return (counter);
}
int main()
{

// char f;
// char *p = &f;

//   int c= printf("%p\n",p);
//   printf("%d   \n",c);
//     int b=ft_printf("%p\n",p);
//     printf("%d   \n",b);
//      printf("%d\n",printf("%X\n",1010));
//      printf("%d\n",ft_printf("%X\n",1010));

printf("%d \n",0);
ft_printf("%d",0);

}