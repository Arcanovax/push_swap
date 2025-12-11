/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:50:42 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/11 20:51:01 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tails;
	int				size;
}					t_stack;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

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
}		t_log;

// tableau flag benchmark // flag
// value // res
// v = 0 % 8 benchmark == False flag = adaptive
// v = 1 % 8 benchmark == False flag = simple
// v = 2 % 8 benchmark == False flag = medium
// v = 3 % 8 benchmark == False flag = complexe
// v = 4 % 8 benchmark == True  flag = adaptive
// v = 5 % 8 benchmark == True  flag = simple
// v = 6 % 8 benchmark == True  flag = medium
// v = 7 % 8 benchmark == True  flag = complexe
// if a flag is set, v is  > 8

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
int		ft_randinx(t_stack *a, t_stack *b, t_log *log);
int		ft_seletion(t_stack *a, t_stack *b, t_log *log);
int		ft_free_all_on_error(char *str, t_stack *a, t_stack *b);
int		ft_free_exit(char *str, t_stack *a, t_stack *b);
int		ft_split_node(t_stack *stack, char const *s);
int		init_stack(t_stack **stack);
int		ft_init_log(t_log **log);
char	*ft_alloc_str(char *str);
char	*ft_cat_nb(char *base, char *cating);
void	ft_print_stack(t_stack *stk);
double	compute_disorder(t_stack *stack);
int		ft_print_bench(double cp_disorder, int flag, t_log *log);

#endif
