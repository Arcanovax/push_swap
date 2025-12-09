/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:39:58 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/09 10:11:05 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_stack *stack)
{// set the tails to head  
	t_stack	*current_node;
	t_node *head;
	
	if (!stack || stack->head || stack->head->next)
		return (-1);	
	stack->tails->next = stack->head;
	stack->tails = stack->head;
	stack->head = stack->head->next;
	stack->tails->next = NULL;
	return (0);
}

int	ft_rotate_a(t_stack stack)
{
	if (ft_rotate(a) == -1)
		return (0);
	if (write(1, "ra\n", 3) >= 0)
		return (0);
	return (-1);
}

int	ft_rotate_b(t_stack **b)
{
	if (ft_rotate(b) == -1)
		return (0);
	if (write(1, "rb\n", 3) >= 0)
		return (0);
	return (-1);
}

int	ft_rotate_ab(t_stack **a, t_stack **b)
{
	int	res_a;
	int	res_b;

	res_a = ft_rotate(a);
	res_b = ft_rotate(b);
	if (res_a == 0 && res_b == 0)
		return (write(1, "rr\n", 3));
	else if (res_a == 0)
		return (write(1, "ra\n", 3) >= 0);
	else if (res_b == 0)
		return (write(1, "rb\n", 3));
	return (0);
}
