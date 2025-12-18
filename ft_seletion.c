/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seletion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:36:18 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/18 15:33:05 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	ft_push_min(t_stack *a, t_stack *b, int imin, t_log *log)
{
	int	i;
	int	error;

	error = 1;
	i = 0;
	if (imin <= a->size / 2)
	{
		while (i < imin && error > 0)
		{
			error = ft_rotate_a(a, log);
			i++;
		}
	}
	else
	{
		while (i < a->size - imin && error > 0)
		{
			error = ft_reverse_rotate_a(a, log);
			i++;
		}
	}
	if (error > 0)
		error = ft_push_b(a, b, log);
	return (error);
}

int	ft_seletion(t_stack *a, t_stack *b, t_log *log)
{
	int	imin;
	int	error;

	error = 1;
	while (a->size > 0 && error > 0)
	{
		imin = ft_get_imin(a);
		error = ft_push_min(a, b, imin, log);
	}
	while (b->head && error > 0)
		error = ft_push_a(a, b, log);
	return (error);
}
