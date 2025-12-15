/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:16:27 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/15 13:33:03 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_radix_will_change(t_stack *a, int mask)
{
	t_node			*node;
	unsigned int	curr;
	unsigned int	next;

	node = a->head;
	while (node && node->next)
	{
		curr = node->value - INT_MIN;
		next = node->next->value - INT_MIN;
		if ((curr & mask) != (next & mask))
			return (1);
		node = node->next;
	}
	return (0);
}
void	ft_rank(t_stack  *a)
{
	t_node	*node;
	int	smallest;
	int i;
	
	i =  0;
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

	ft_rank(a);
	bit = 0;
	while (bit < 32)
	{
		mask = 1 << bit;
		size = a->size;
		if (ft_radix_will_change(a, mask) == 1)
		{
			while (size--)
			{
				if (((a->head->value - INT_MIN) & mask))
					ft_rotate_a(a, log);
				else
					ft_push_b(a, b, log);
			}
			while (b->head)
				ft_push_a(a, b, log);
		}
		bit++;
	}
	return (0);
}
