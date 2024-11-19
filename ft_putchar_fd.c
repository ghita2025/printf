#include <unistd.h>

void	ft_putchar_fd(char c, int fd , int *counter)
{
	(*counter)+=write(fd, &c, 1);
}