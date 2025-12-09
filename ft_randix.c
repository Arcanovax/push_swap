/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:16:27 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/09 17:06:18 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_stack(t_stack *stk)
{
	t_node	*node;

	node = stk->head;
	__builtin_printf("stack:\nhead: % 2d|%p\ntails:%2d|%p\n", stk->head->value,
		stk->head, stk->tails->value, stk->tails);
	while (node)
	{
		__builtin_printf("prev:%10p|node_a:%2d|%p|next:%-10p\n", node->prev,
			node->value, node, node->next);
		node = node->next;
	}
}

#include <limits.h>

void	ft_set_unsigned(t_stack *stack)
{
	int last_before;

	if (!stack || !stack->head)
		return ;
	last_before = stack->tails->value;
	while (stack->head->value != last_before)
	{
		stack->head->value -= INT_MIN;
		ft_rotate_a(stack);
	}
	stack->head->value -= INT_MIN;
}

void	ft_unset_unsigned(t_stack *stack)
{
	int last_before;

	if (!stack || !stack->head)
		return ;
	last_before = stack->tails->value;
	while (stack->head->value != last_before)
	{
		stack->head->value += INT_MIN;
		ft_rotate_a(stack);
	}
	stack->head->value += INT_MIN;
}

int	ft_randinx(t_stack *a)
{
	t_stack *b = malloc(sizeof(t_stack));
	b->head = NULL;
	b->tails = NULL;
	int last;
	int bit = 0;

	ft_set_unsigned(a);
	while (bit < 32)
	{
		last = a->tails->value;
		while (a->head && a->head->value != last)
		{
			if ((a->head->value >> bit) & 1)
				ft_push_b(a, b);
			else
				ft_rotate_a(a);
		}
		if ((a->head->value >> bit) & 1)
			ft_push_b(a, b);
		else
			ft_rotate_a(a);
		while (b->head)
			ft_push_a(a, b);
		bit ++;
	}
	ft_unset_unsigned(a);
	ft_rotate_a(a);
	free(b);
	return (0);
}