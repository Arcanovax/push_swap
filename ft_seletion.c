/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seletion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:36:18 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/15 17:09:03 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_get_imin(t_stack *a)
{
	t_node	*current_node;
	int		i;
	int		imin;
	int		min;

	imin = 0;
	i = 0;
	current_node = a->head;
	min = current_node->value;
	while (current_node && i < a->size)
	{
		if (current_node->value < min)
		{
			min = current_node->value;
			imin = i;
		}
		current_node = current_node->next;
		i++;
	}
	return (imin);
}

void	ft_push_min(t_stack *a, t_stack *b, int imin, t_log *log)
{
	int	i;

	i = 0;
	if (imin <= a->size / 2)
	{
		while (i < imin)
		{
			ft_rotate_a(a, log);
			i++;
		}
	}
	else
	{
		while (i < a->size - imin)
		{
			ft_reverse_rotate_a(a, log);
			i++;
		}
	}
	ft_push_b(a, b, log);
}

int	ft_seletion(t_stack *a, t_stack *b, t_log *log)
{
	int	imin;

	while (a->size > 0)
	{
		imin = ft_get_imin(a);
		ft_push_min(a, b, imin, log);
	}
	while (b->head)
		ft_push_a(a, b, log);
	return (0);
}
