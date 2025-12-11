/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:16:27 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/11 20:55:24 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_randinx_next(t_stack *a, t_stack *b, int bits, t_log *log)
{
	int	bit;
	int	size;
	int	mask;

	bit = 0;
	while (bit < bits)
	{
		mask = 1 << bit;
		size = a->size;
		while (size--)
		{
			if (((a->head->value - INT_MIN) & mask))
				ft_rotate_a(a, log);
			else
				ft_push_b(a, b, log);
		}
		while (b->head)
			ft_push_a(a, b, log);
		bit++;
	}
	return (0);
}

int	ft_randinx(t_stack *a, t_stack *b, t_log *log)
{
	int		max;
	t_node	*node;
	int		bits;

	max = a->head->value;
	node = a->head;
	while (node)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
	}
	bits = 0;
	while (max >> bits != 0)
		bits++;
	return (ft_randinx_next(a, b, bits, log));
}
