/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:24:13 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/15 17:19:31 by mboutte          ###   ########.fr       */
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

static void	get_min_max(t_stack *a, t_bucket *bucket)
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

static int	get_bucket_imax(t_stack *b, int range_min)
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

static void	ft_push_max_range(t_stack *a, t_stack *b, int range_min, t_log *log)
{
	int	i;
	int	max;
	int	imax;

	max = b->head->value;
	i = 0;
	imax = get_bucket_imax(b, range_min);
	while (i != imax)
	{
		ft_rotate_b(b, log);
		i++;
	}
	ft_push_a(a, b, log);
	while (i != 0)
	{
		ft_reverse_rotate_b(b, log);
		i--;
	}
}

static void	ft_push_bucket(t_stack *a, t_stack *b, t_bucket *bucket, t_log *log)
{
	int	j;
	int	top_a;

	j = 0;
	while (j < a->size + b->size)
	{
		if (!a->head)
			break ;
		top_a = a->head->value;
		if (top_a >= bucket->range_min && top_a <= bucket->range_max)
			ft_push_b(a, b, log);
		else
			ft_rotate_a(a, log);
		j++;
	}
}

static int	create_bucket(t_stack *a, t_stack *b, t_bucket *bucket, t_log *log)
{
	int	i;

	i = 0;
	while (i < bucket->nb)
	{
		bucket->range_min = bucket->min + i * bucket->size;
		if (i == bucket->nb - 1)
			bucket->range_max = bucket->max;
		else
			bucket->range_max = bucket->range_min + bucket->size - 1;
		ft_push_bucket(a, b, bucket, log);
		i++;
	}
	i--;
	return (i);
}

int	ft_bucket(t_stack *a, t_stack *b, t_log *log)
{
	t_bucket	bucket;
	int			i;
	int			j;

	bucket.nb = ft_sqrt(a->size);
	get_min_max(a, &bucket);
	bucket.size = (bucket.max - bucket.min + 1) / bucket.nb;
	i = create_bucket(a, b, &bucket, log);
	while (i >= 0)
	{
		j = 0;
		bucket.range_min = bucket.min + i * bucket.size;
		if (i == bucket.nb - 1)
			bucket.range_max = bucket.max;
		else
			bucket.range_max = bucket.range_min + bucket.size - 1;
		while (b->head && b->head->value >= bucket.range_min)
		{
			if (!b->head)
				break ;
			ft_push_max_range(a, b, bucket.range_min, log);
		}
		i--;
	}
	return (0);
}
