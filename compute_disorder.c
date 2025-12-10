/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:01:04 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/10 16:15:40 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

double	compute_disorder(t_stack *stack)
{
	long	mistakes;
	long	total_pairs;
	t_node	*head;
	t_node	*node;

	mistakes = 0;
	total_pairs = 0;
	head = stack->head;
	node = head->next;
	while (head != NULL)
	{
		node = head->next;
		while (node != NULL)
		{
			total_pairs++;
			if (head->value > node->value)
				mistakes++;
			node = node->next;
		}
		head = head->next;
	}
	return ((double)mistakes / (double)total_pairs);
}
