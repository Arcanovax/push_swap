/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:16:27 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/17 14:33:22 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_bit_list(t_stack *a)
{
	t_node			*node;
	unsigned int	max;
	int				pos;
	unsigned int	val;

	node = a->head;
	max = 0;
	pos = -1;
	while (node)
	{
		val = node->value - INT_MIN;
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

static int	ft_radix_push_bit(t_stack *origin, t_stack *target, t_log *log,
		int bit)
{
	int	size;
	int	error;

	error = 1;
	size = origin->size;
	while (size-- && error >= 0)
	{
		if ((origin->head->value - INT_MIN) & 1 << bit)
			error = ft_rotate_a(origin, log);
		else
			error = ft_push_b(origin, target, log);
	}
	return (error);
}

static int	ft_radix_empty(t_stack *origin, t_stack *target, t_log *log,
		int bit)
{
	int	size;
	int	error;

	error = 1;
	size = origin->size;
	while (size-- && error >= 0)
	{
		if ((origin->head->value - INT_MIN) & 1 << (bit))
			error = ft_push_a(target, origin, log);
		else
			error = ft_rotate_b(origin, log);
	}
	return (error);
}

int	ft_radix(t_stack *a, t_stack *b, t_log *log)
{
	int	bit;
	int	end;
	int	error;

	error = 1;
	ft_rank(a);
	end = highest_bit_list(a);
	bit = 0;
	while (bit <= end && error >= 0)
	{
		error = ft_radix_push_bit(a, b, log, bit);
		bit++;
		if (bit <= end && error >= 0)
			error = ft_radix_empty(b, a, log, bit);
	}
	while (b->head)
		ft_push_a(a, b, log);
	return (error);
}
