/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:50:42 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/19 12:36:05 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include "push_swap_common.h"

typedef struct s_bucket
{
	int	min;
	int	max;
	int	nb;
	int	size;
	int	range_min;
	int	range_max;
}	t_bucket;

typedef struct s_log
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_log;

int		ft_swap_a(t_stack *a, t_log *log);
int		ft_swap_b(t_stack *b, t_log *log);
int		ft_swap_ab(t_stack *a, t_stack *b, t_log *log);
int		ft_push_a(t_stack *a, t_stack *b, t_log *log);
int		ft_push_b(t_stack *a, t_stack *b, t_log *log);
int		ft_rotate_a(t_stack *a, t_log *log);
int		ft_rotate_b(t_stack *b, t_log *log);
int		ft_rotate_ab(t_stack *a, t_stack *b, t_log *log);
int		ft_reverse_rotate_a(t_stack *a, t_log *log);
int		ft_reverse_rotate_b(t_stack *b, t_log *log);
int		ft_reverse_rotate_ab(t_stack *a, t_stack *b, t_log *log);

int		ft_seletion(t_stack *a, t_stack *b, t_log *log);
int		ft_radix(t_stack *a, t_stack *b, t_log *log);
int		ft_bucket(t_stack *a, t_stack *b, t_log *log);

int		ft_sqrt(int nb);
void	get_min_max(t_stack *a, t_bucket *bucket);
int		get_bucket_imax(t_stack *b, int range_min);

int		ft_init_log(t_log **log);

int		ft_print_bench(double cp_disorder, int flag, t_log *log, int size);
int		ft_putnbr_fd(int n, int fd);
void	ft_putdouble_fd(double x, int precision, int fd);

int		get_flag(char *arg, int *flag);

#endif
