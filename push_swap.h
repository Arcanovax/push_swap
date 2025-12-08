/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:50:42 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/08 18:08:12 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int	ft_swap_a(t_stack *a);
int	ft_swap_b(t_stack *b);
int	ft_swap_ab(t_stack *a, t_stack *b);
int	ft_push_a(t_stack **a, t_stack **b);
int	ft_push_b(t_stack **a, t_stack **b);
int	ft_rotate_a(t_stack **a);
int	ft_rotate_b(t_stack **b);
int	ft_rotate_ab(t_stack **a, t_stack **b);
int	ft_reverse_rotate_a(t_stack **a);
int	ft_reverse_rotate_b(t_stack **b);
int	ft_reverse_rotate_ab(t_stack **a, t_stack **b);

#endif
