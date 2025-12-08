/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:33:35 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/08 18:11:08 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_stack **stack, t_stack **node)
{
	t_stack	*tmp;

	if (*node == NULL)
		return (-1);
	tmp = *node;
	(*node) = (*node)->next;
	tmp->next = *stack;
	*stack = tmp;
	return (0);
}

int	ft_push_a(t_stack **a, t_stack **b)
{
	if (ft_push(a, b) == -1)
		return (0);
	if (write(1, "pa\n", 3) >= 0)
		return (0);
	return (-1);
}

int	ft_push_b(t_stack **a, t_stack **b)
{
	if (ft_push(b, a) == -1)
		return (0);
	if (write(1, "pb\n", 3) >= 0)
		return (0);
	return (-1);
}
