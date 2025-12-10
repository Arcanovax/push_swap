/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:01:04 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/10 15:51:37 by mboutte          ###   ########.fr       */
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
static void	ft_print_stack(t_stack *stk)
{
	t_node *node = stk->head;
	__builtin_printf("stack\nhead: % 2d|%p\ntails:%2d|%p\nsize:%3d|\n", stk->head->value, stk->head, stk->tails->value, stk->tails, stk->size);
	while (node) {
		__builtin_printf("prev:%10p|node_a:%2d|%p|next:%-10p\n",node->prev, node->value, node, node->next);
		node = node->next;
	}
}

static void ft_free_stack(t_stack *stk)
{
	t_node *node = stk->head;
	t_node *next;
	
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(stk);
}
