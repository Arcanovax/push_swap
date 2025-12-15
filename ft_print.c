/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:52:30 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/12 17:10:59 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_putnbr_fd(int n, int fd)
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

static void	ft_print_log(t_log *log, int fd)
{
	write(fd, "[bench] pa: ", 12);
	ft_putnbr_fd(log->pa, fd);
	write(fd, " pb: ", 5);
	ft_putnbr_fd(log->pb, fd);
	write(fd, "\n[bench] sa: ", 13);
	ft_putnbr_fd(log->sa, fd);
	write(fd, " sb: ", 5);
	ft_putnbr_fd(log->sb, fd);
	write(fd, " ss: ", 5);
	ft_putnbr_fd(log->ss, fd);
	write(fd, "\n[bench] ra: ", 13);
	ft_putnbr_fd(log->ra, fd);
	write(fd, " rb: ", 5);
	ft_putnbr_fd(log->rb, fd);
	write(fd, " rr: ", 5);
	ft_putnbr_fd(log->rr, fd);
	write(fd, "\n[bench] rra: ", 14);
	ft_putnbr_fd(log->rra, fd);
	write(fd, " rrb: ", 6);
	ft_putnbr_fd(log->rrb, fd);
	write(fd, " rrr: ", 6);
	ft_putnbr_fd(log->rrr, fd);
}

static int	ft_print_total_ops(t_log *log, int fd)
{
	int	total;

	total = log->pa + log->pb + log->sa + log->sb + log->ss + log->ra + log->rb
		+ log->rr + log->rra + log->rrb + log->rrr;
	write(fd, "[bench] tatal ops: ", 19);
	ft_putnbr_fd(total, fd);
	write(fd, "\n", 1);
	return (1);
}

static void	ft_putdouble_fd(double x, int precision, int fd)
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

static void	ft_putdouble_color_fd(double x, int fd)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255 * (1.0 - x));
	g = (int)(255 * x);
	b = 0;
	x *= 100;
	write(fd, "\033[38;2;", 7);
	ft_putnbr_fd(r, fd);
	write(fd, ";", 1);
	ft_putnbr_fd(g, fd);
	write(fd, ";", 1);
	ft_putnbr_fd(b, fd);
	write(fd, "m", 1);
	write(fd, "[bench] ", 8);
	ft_putdouble_fd(x, 2, fd);
	write(fd, "%%", 1);
	write(fd, "\033[0m", 4);
	write(fd, "\n", 1);
}

static int	ft_print_strategy(int flag, int fd)
{
	write(fd, "[bench] strategy: ", 18);
	if (flag % 4 == 0)
		write(fd, "Adaptive O(n log(n))\n", 21);
	else if (flag % 4 == 1)
		write(fd, "Simple O(n²)\n", 14);
	else if (flag % 4 == 2)
		write(fd, "Medium O(n√n)\n", 16);
	else if (flag % 4 == 3)
		write(fd, "Complex O(n log(n))\n", 20);
	return (0);
}

int	ft_print_bench(double cp_disorder, int flag, t_log *log)
{
	int	fd;

	fd = 2;
	ft_putdouble_color_fd(cp_disorder, fd);
	write(fd, "\033[38;2;0;0;255m", 15);
	ft_print_strategy(flag, fd);
	ft_print_total_ops(log, fd);
	ft_print_log(log, fd);
	write(fd, "\033[0m\n", 5);
	return (1);
}
