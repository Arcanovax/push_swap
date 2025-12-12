/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:24:13 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/12 15:54:48 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

static void	get_min_max(t_stack *a, t_bucket *bucket, t_log *log)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = a->head->value;
	max = a->head->value;
	while (i < a->size)
	{
		ft_rotate_a(a, log);
		if (a->head->value < min)
			min = a->head->value;
		if (a->head->value > max)
			max = a->head->value;
		i++;
	}
	bucket->min = min;
	bucket->max = max;
}

static void	ft_go_top(t_stack *b, int i, t_log *log)
{
	while (i != 0)
	{
		ft_reverse_rotate_b(b, log);
		i--;
	}
}

static void	ft_push_max_range(t_stack *a, t_stack *b, int range_min, t_log *log)
{
	int	i;
	int	max;
	int	imax;

	max = b->head->value;
	i = 0;
	while (b->head->value >= range_min && i < b->size)
	{
		if (b->head->value >= max)
		{
			max = b->head->value;
			imax = i;
		}
		ft_rotate_b(b, log);
		i++;
	}
	while (i != imax)
	{
		ft_reverse_rotate_b(b, log);
		i--;
	}
	ft_push_a(a, b, log);
	ft_go_top(b, i, log);
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
	get_min_max(a, &bucket, log);
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
