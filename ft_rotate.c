/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:39:58 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/09 10:27:45 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_stack *stack)
{// set the tails to head  
	t_node	*head;
	t_node	*tails;
	
	if (!stack || stack->head || stack->tails)
		return (-1);
	head = stack->head;
	tails = stack->tails;
	if (!head->next)
		return (-1);
	tails->next = stack->head;
	stack->tails = stack->head;
	stack->head = head->next;
	head->next = NULL;
	return (0);
}

int	ft_rotate_a(t_stack *a)
{
	if (ft_rotate(a) == -1)
		return (0);
	if (write(1, "ra\n", 3) >= 0)
		return (0);
	return (-1);
}

int	ft_rotate_b(t_stack *b)
{
	if (ft_rotate(b) == -1)
		return (0);
	if (write(1, "rb\n", 3) >= 0)
		return (0);
	return (-1);
}

int	ft_rotate_ab(t_stack *a, t_stack *b)
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
