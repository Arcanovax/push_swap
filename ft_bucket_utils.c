/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:00:09 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/16 15:02:40 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;
	int	x;

	i = 1;
	x = 1;
	while (nb > 0 && i++ < 100)
		x = 0.5 * (x + (nb / x));
	return (x);
}

void	get_min_max(t_stack *a, t_bucket *bucket)
{
	t_node	*current_node;
	int		min;
	int		max;

	current_node = a->head;
	min = a->head->value;
	max = a->head->value;
	while (current_node)
	{
		if (current_node->value < min)
			min = current_node->value;
		if (current_node->value > max)
			max = current_node->value;
		current_node = current_node->next;
	}
	bucket->min = min;
	bucket->max = max;
}

int	get_bucket_imax(t_stack *b, int range_min)
{
	t_node	*current_node;
	int		imax;
	int		max;
	int		i;

	i = 0;
	current_node = b->head;
	max = current_node->value;
	imax = 0;
	while (current_node && current_node->value >= range_min && i < b->size)
	{
		if (current_node->value >= max)
		{
			max = current_node->value;
			imax = i;
		}
		current_node = current_node->next;
		i++;
	}
	return (imax);
}
