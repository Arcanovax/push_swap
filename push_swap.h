/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:50:42 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/09 09:29:04 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>


typedef struct	s_stack
{
	t_stack	*head;
	t_stack	*tails;
}	t_stack;



typedef struct s_node
{
	int				value;
	t_node	*prev;
	t_node	*next;
}	t_node;

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
