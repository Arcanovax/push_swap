/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:01:04 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/19 11:26:24 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	while (head != NULL)
	{
		node = head->next;
		while (node != NULL)
		{
			total_pairs++;
			if (head->value == node->value)
				return (-1);
			else if (head->value < node->value)
				mistakes++;
			node = node->next;
		}
		head = head->next;
	}
	if (total_pairs == 0)
		return (1);
	return ((double)mistakes / (double)total_pairs);
}
