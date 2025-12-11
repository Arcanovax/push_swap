/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:52:30 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/11 20:55:35 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_print_log(t_log *log)
{
	__builtin_printf("[bench] pa: %d pb: %d\n", log->pa, log->pb);
	__builtin_printf("[bench] sa: %d sb: %d ss: %d\n", log->sa, log->sb,
		log->ss);
	__builtin_printf("[bench] ra: %d rb: %d rr: %d\n", log->ra, log->rb,
		log->rr);
	__builtin_printf("[bench] rra: %d rrb: %d rrr: %d\n", log->rra, log->rrb,
		log->rrr);
	return (0);
}

static int	ft_print_total_ops(t_log *log)
{
	int	total;

	total = log->pa + log->pb + log->sa + log->sb + log->ss + log->ra + log->rb
		+ log->rr + log->rra + log->rrb + log->rrr;
	__builtin_printf("[bench] tatal ops: %d \n", total);
	return (1);
}

// écrire un entier avec write()
static void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

// écrire un double avec write()
static void	ft_putdouble(double x, int precision)
{
	int		integer;
	double	fraction;
	int		digit;
	char	c;
	int		i;

	integer = (int)x;
	fraction = x - integer;
	ft_putnbr(integer);
	write(1, ".", 1);
	if (fraction < 0)
		fraction = -fraction;
	i = 0;
	while (i < precision)
	{
		fraction *= 10;
		digit = (int)fraction;
		c = '0' + digit;
		write(1, &c, 1);
		fraction -= digit;
		i++;
	}
}

// écrire un double en couleur avec write()
static void	ft_putdouble_color(double x)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255 * (1.0 - x)); // calcul du dégradé rouge -> vert
	g = (int)(255 * x);
	b = 0;
	x *= 100;
	write(1, "\033[38;2;", 7); // séquence ANSI : "\033[38;2;R;G;Bm"
	ft_putnbr(r);
	write(1, ";", 1);
	ft_putnbr(g);
	write(1, ";0", 1);
	ft_putnbr(b);
	write(1, "m", 1);
	write(1, "[bench] ", 8);
	ft_putdouble(x, 2); // afficher le double
	write(1, "%%", 1);
	write(1, "\033[0m", 4); // reset couleur
	write(1, "\n", 1);
}
static int	ft_print_strategy(flag)
{
	write(1, "[bench] strategy: ", 19);
	if (flag % 4 == 0)
		write(1, "Adaptive O(n log(n))\n", 22);
	else if (flag % 4 == 1)
		write(1, "Simple O(n²)\n", 15);
	else if (flag % 4 == 2)
		write(1, "Medium O(n√n)\n", 17);
	else if (flag % 4 == 3)
		write(1, "Complex O(n log(n))\n", 21);
	return (0);
}

int	ft_print_bench(double cp_disorder, int flag, t_log *log)
{
	ft_putdouble_color(cp_disorder);
	write(1, "\033[38;2;0;0;255m", 16);
	ft_print_strategy(flag);
	ft_print_total_ops(log);
	ft_print_log(log);
	write(1, "\033[0m", 4);
	return (1);
}