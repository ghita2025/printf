#include "libftprintf.h"

void	ft_putnbr_fd(int num, int fd, int *counter)
{
	long	nb;
	char	c;

	nb = num;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
        (*counter)++;

	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd, counter);
	}
	c = (nb % 10) + '0';
	write(fd, &c, 1);
    (*counter)++;
}