/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:50:42 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/15 17:31:53 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_bucket
{
	int	min;
	int	max;
	int	nb;
	int	size;
	int	range_min;
	int	range_max;
}	t_bucket;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tails;
	int				size;
}	t_stack;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

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

int		ft_free_all_on_error(char *str, t_stack *a, t_stack *b);
int		ft_free_exit(char *str, t_stack *a, t_stack *b);

int		ft_split_node(t_stack *stack, char const *s);

int		init_stack(t_stack **stack);
int		ft_init_log(t_log **log);
char	*ft_alloc_str(char *str);
char	*ft_cat_nb(char *base, char *cating);

int		ft_print_bench(double cp_disorder, int flag, t_log *log);
double	compute_disorder(t_stack *stack);

int		ft_putnbr_fd(int n, int fd);
void	ft_putdouble_fd(double x, int precision, int fd);

//this ft need to be remove
void	ft_print_stack(t_stack *stk);

#endif
