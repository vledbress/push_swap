#include "io.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int num)
{
	long n;

	n = num;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}
