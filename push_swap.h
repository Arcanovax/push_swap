/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:50:42 by mthetcha          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/12/09 10:31:33 by mthetcha         ###   ########lyon.fr   */
=======
/*   Updated: 2025/12/09 12:58:16 by mboutte          ###   ########.fr       */
>>>>>>> origin
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stack
{
	struct s_node	*head;
	struct s_node	*tails;
}	t_stack;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
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
