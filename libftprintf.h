#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

void ft_putstr_fd(char *str,int fd,int *counter);
void ft_putnbr_fd(int num, int fd, int *counter);
void	ft_putchar_fd(char c, int fd , int *counter);
void ft_put_arg(char sep, va_list args, int *counter);
void ft_convert_to_hex(unsigned long nb,char sep, int *counter);
void ft_convert_base(va_list args,char sep,int *counter);
void ft_putunsigned_fd(va_list args, int fd, int *counter);
int ft_printf(const char *format, ...);