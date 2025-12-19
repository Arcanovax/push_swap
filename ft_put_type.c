/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:27:03 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/15 17:28:29 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -INT_MIN)
		return (write(fd, "-2147483647", 11));
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = '0' + (n % 10);
	return (write(fd, &c, 1));
}

void	ft_putdouble_fd(double x, int precision, int fd)
{
	int		integer;
	double	fraction;
	int		digit;
	char	c;
	int		i;

	integer = (int)x;
	fraction = x - integer;
	ft_putnbr_fd(integer, fd);
	write(fd, ".", 1);
	if (fraction < 0)
		fraction = -fraction;
	i = 0;
	while (i < precision)
	{
		fraction *= 10;
		digit = (int)fraction;
		c = '0' + digit;
		write(fd, &c, 1);
		fraction -= digit;
		i++;
	}
}
