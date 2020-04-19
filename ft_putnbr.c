#include <unistd.h>

void	putone(int n)
{
	char c;

	c = '0' + n;
	write(1, &c, 1);
}

void	putminus(int *nb)
{
	char minus;

	minus = '-';
	if (*nb < 0)
	{
		write(1, &minus, 1);
	}
	else
	{
		*nb *= (-1);
	}
	if (*nb == 0)
		putone(0);
}

void	ft_putnbr(int nb)
{
	int	order;
	int	flag;
	int	nb2;

	putminus(&nb);
	order = -1000000000;
	flag = 0;
	while (order <= -1)
	{
		if (nb <= order)
		{
			nb2 = nb / order;
			putone(nb2);
			flag = 1;
		}
		else
		{
			if (flag)
				putone(0);
		}
		nb = nb % order;
		order /= 10;
	}
}
