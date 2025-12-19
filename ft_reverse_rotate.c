/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:17:32 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/19 12:22:13 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

int	ft_reverse_rotate(t_stack *stack)
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

int	ft_reverse_rotate_rotate(t_stack *a, t_stack *b)
{
	if (ft_reverse_rotate(a) == 0 && ft_reverse_rotate(b) == 0)
		return (0);
	return (-1);
}
