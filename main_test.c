/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:00:35 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/15 17:14:19 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stk)
{
	t_node	*node;

	node = stk->head;
	__builtin_printf("stack\nhead: % 2d|%p\ntails:%2d|%p\nsize:%3d|\n",
		stk->head->value, stk->head, stk->tails->value, stk->tails, stk->size);
	while (node)
	{
		__builtin_printf("prev:%10p|node_a:%2d|%p|next:%-10p\n", node->prev,
			node->value, node, node->next);
		node = node->next;
	}
}
