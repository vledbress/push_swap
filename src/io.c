#include "io.h"

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(int fd, char *str)
{
	if (!str)
		return ;
	while (*str)
		ft_putchar(fd, *str++);
}

void	ft_putnbr(int num)
{
	long n;

	n = num;
	if (n < 0)
	{
		ft_putchar(1, '-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(1, (n % 10) + '0');
}

