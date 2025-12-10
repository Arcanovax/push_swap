/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:17:32 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/10 12:27:20 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_reverse_rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*tails;

	if (!stack || !stack->head || !stack->tails)
		return (-1);
	head = stack->head;
	tails = stack->tails;
	if (!head->next || !tails->prev)
		return (-1);
	stack->tails = stack->tails->prev;
	stack->tails->next = NULL;
	stack->head = tails;
	tails->next = head;
	head->prev = tails;
	tails->prev = NULL;
	return (0);
}

int	ft_reverse_rotate_a(t_stack *a)
{
	if (ft_reverse_rotate(a) == -1)
		return (0);
	if (write(1, "rra\n", 4) >= 0)
		return (0);
	return (-1);
}

int	ft_reverse_rotate_b(t_stack *b)
{
	if (ft_reverse_rotate(b) == -1)
		return (0);
	if (write(1, "rrb\n", 4) >= 0)
		return (0);
	return (-1);
}

int	ft_reverse_rotate_ab(t_stack *a, t_stack *b)
{
	int	res_a;
	int	res_b;

	res_a = ft_reverse_rotate(a);
	res_b = ft_reverse_rotate(b);
	if (res_a == 0 && res_b == 0)
		return (write(1, "rrr\n", 4));
	else if (res_a == 0)
		return (write(1, "rra\n", 4) >= 0);
	else if (res_b == 0)
		return (write(1, "rrb\n", 4));
	return (0);
}
