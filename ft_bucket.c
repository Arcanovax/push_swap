/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:24:13 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/16 15:00:40 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push_max_range(t_stack *a, t_stack *b, int range_min, t_log *log)
{
	int	i;
	int	max;
	int	imax;
	int	error;

	error = 1;
	max = b->head->value;
	i = 0;
	imax = get_bucket_imax(b, range_min);
	while (i != imax && error > 0)
	{
		error = ft_rotate_b(b, log);
		i++;
	}
	if (error > 0)
		error = ft_push_a(a, b, log);
	while (i != 0 && error > 0)
	{
		error = ft_reverse_rotate_b(b, log);
		i--;
	}
	return (error);
}

static int	ft_push_bucket(t_stack *a, t_stack *b, t_bucket *bucket, t_log *log)
{
	int	j;
	int	top_a;
	int	error;

	error = 1;
	j = 0;
	while (j < a->size + b->size && error > 0)
	{
		if (!a->head)
			break ;
		top_a = a->head->value;
		if (top_a >= bucket->range_min && top_a <= bucket->range_max)
			error = ft_push_b(a, b, log);
		else
			error = ft_rotate_a(a, log);
		j++;
	}
	return (error);
}

static int	create_bucket(t_stack *a, t_stack *b, t_bucket *bucket, t_log *log)
{
	int	i;
	int	error;

	error = 1;
	i = 0;
	while (i < bucket->nb)
	{
		bucket->range_min = bucket->min + i * bucket->size;
		if (i == bucket->nb - 1)
			bucket->range_max = bucket->max;
		else
			bucket->range_max = bucket->range_min + bucket->size - 1;
		error = ft_push_bucket(a, b, bucket, log);
		if (error < 0)
			return (-1);
		i++;
	}
	i--;
	return (i);
}

int	ft_align_buckets(t_stack *a, t_stack *b, t_bucket *bucket, t_log *log)
{
	int	i;
	int	j;

	i = bucket->nb;
	while (b->size)
	{
		j = 0;
		bucket->range_min = bucket->min + i * bucket->size;
		if (i == bucket->nb - 1)
			bucket->range_max = bucket->max;
		else
			bucket->range_max = bucket->range_min + bucket->size - 1;
		while (b->head && b->head->value >= bucket->range_min)
		{
			if (!b->head)
				break ;
			if (ft_push_max_range(a, b, bucket->range_min, log) < 0)
				return (-1);
		}
		i--;
	}
	return (1);
}

int	ft_bucket(t_stack *a, t_stack *b, t_log *log)
{
	t_bucket	bucket;

	bucket.nb = ft_sqrt(a->size);
	get_min_max(a, &bucket);
	bucket.size = (bucket.max - bucket.min + 1) / bucket.nb;
	if (create_bucket(a, b, &bucket, log) < 0)
		return (-1);
	if (ft_align_buckets(a, b, &bucket, log) < 0)
		return (-1);
	return (1);
}
