/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:16:27 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/15 15:26:47 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_bit_list(t_stack *a)
{
	t_node			*node;
	unsigned int	max;
	int				pos;

	node = a->head;
	max = 0;
	pos = -1;
	while (node)
	{
		unsigned int val = node->value - INT_MIN;
		if (val > max)
			max = val;
		node = node->next;
	}
	while (max)
	{
		pos++;
		max >>= 1;
	}
	return (pos);
}

static void	ft_rank(t_stack *a)
{
	t_node	*node;
	int		smallest;
	int		i;

	i = 0;
	node = a->head;
	while (i < a->size)
	{
		node = a->head;
		smallest = INT_MAX;
		while (node)
		{
			if (node->value < smallest && node->value >= INT_MIN + i)
				smallest = node->value;
			node = node->next;
		}
		node = a->head;
		while (node->value != smallest)
			node = node->next;
		node->value = INT_MIN + i;
		i++;
	}
}

int	ft_radix(t_stack *a, t_stack *b, t_log *log)
{
	int	bit;
	int	size;
	int	mask;
	int	end;

	ft_rank(a);
	bit = 0;
	end = highest_bit_list(a);
	while (bit <= end)
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
