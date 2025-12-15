/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:52:30 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/15 17:28:23 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_log(t_log *log, int fd)
{
	write(fd, "pa: ", 4);
	ft_putnbr_fd(log->pa, fd);
	write(fd, " pb: ", 5);
	ft_putnbr_fd(log->pb, fd);
	write(fd, "\nsa: ", 5);
	ft_putnbr_fd(log->sa, fd);
	write(fd, " sb: ", 5);
	ft_putnbr_fd(log->sb, fd);
	write(fd, " ss: ", 5);
	ft_putnbr_fd(log->ss, fd);
	write(fd, "\nra: ", 5);
	ft_putnbr_fd(log->ra, fd);
	write(fd, " rb: ", 5);
	ft_putnbr_fd(log->rb, fd);
	write(fd, " rr: ", 5);
	ft_putnbr_fd(log->rr, fd);
	write(fd, "\nrra: ", 6);
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
	write(fd, "Tatal ops: ", 11);
	ft_putnbr_fd(total, fd);
	write(fd, "\n", 1);
	return (1);
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
	ft_putdouble_fd(x, 2, fd);
	write(fd, "%%", 1);
	write(fd, "\033[0m", 4);
	write(fd, "\n", 1);
}

static int	ft_print_strategy(int flag, int fd)
{
	write(fd, "Strategy: ", 10);
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
	int		fd;
	char	*line;

	line = "----------";
	fd = 2;
	write(fd, line, 10);
	write(fd, "PUSH SWAP / 42 Project By Mboutte and Mthetcha", 46);
	write(fd, line, 10);
	write(1, "\n", 1);
	write(fd, "\033[38;2;0;0;255m", 15);
	write(fd, "Compute disorder : ", 19);
	write(fd, "\033[0m", 4);
	ft_putdouble_color_fd(cp_disorder, fd);
	write(fd, "\033[38;2;0;0;255m", 15);
	ft_print_strategy(flag, fd);
	ft_print_total_ops(log, fd);
	ft_print_log(log, fd);
	write(fd, "\033[0m\n", 5);
	write(fd, line, 10);
	write(fd, line, 10);
	write(fd, "----------------------------------------------\n", 47);
	return (0);
}
