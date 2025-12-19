/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:33:35 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/19 11:22:17 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

int	ft_push(t_stack *stack_target, t_stack *stack_node)
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
