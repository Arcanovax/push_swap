/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:33:35 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/15 17:21:46 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_stack *stack_target, t_stack *stack_node)
{
	t_node	*node;

	if (!stack_node || !stack_node->head)
		return (-1);
	node = stack_node->head;
	stack_node->head = node->next;
	if (stack_node->head == NULL)
		stack_node->tails = NULL;
	else
		stack_node->head->prev = NULL;
	node->next = stack_target->head;
	if (stack_target->head == NULL)
	{
		stack_target->head = node;
		stack_target->tails = node;
	}
	else
	{
		stack_target->head->prev = node;
		stack_target->head = node;
	}
	stack_target->size++;
	stack_node->size--;
	return (0);
}

int	ft_push_a(t_stack *a, t_stack *b, t_log *log)
{
	if (ft_push(a, b) == -1)
		return (0);
	if (log)
		log->pa += 1;
	return (write(1, "pa\n", 3));
}

int	ft_push_b(t_stack *a, t_stack *b, t_log *log)
{
	if (ft_push(b, a) == -1)
		return (0);
	if (log)
		log->pb += 1;
	return (write(1, "pb\n", 3));
}
