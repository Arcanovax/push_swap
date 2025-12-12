/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:24:13 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/12 14:57:25 by mthetcha         ###   ########lyon.fr   */
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

void	get_min_max(t_stack *a, t_bucket *bucket)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = a->head->value;
	max = a->head->value;
	while (i < a->size)
	{
		ft_rotate_a(a);
		if (a->head->value < min)
			min = a->head->value;
		if (a->head->value > max)
			max = a->head->value;
		i++;
	}
	bucket->min = min;
	bucket->max = max;
}

void	ft_go_top(t_stack *a, t_stack *b, int i)
{
	while (i != 0)
	{
		ft_reverse_rotate_b(b);
		i--;
	}
}

void	ft_push_max_range(t_stack *a, t_stack *b, int range_min)
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
		ft_rotate_b(b);
		i++;
	}
	while (i != imax)
	{
		ft_reverse_rotate_b(b);
		i--;
	}
	ft_push_a(a, b);
	ft_go_top(a, b, i);
}

void	ft_push_current_bucket(t_stack *a, t_stack *b, t_bucket *bucket)
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
			ft_push_b(a, b);
		else
			ft_rotate_a(a);
		j++;
	}
}

int	create_bucket(t_stack *a, t_stack *b, t_bucket *bucket)
{
	int	i;
	int	j;

	i = 0;
	while (i < bucket->nb)
	{
		bucket->range_min = bucket->min + i * bucket->size;
		if (i == bucket->nb - 1)
			bucket->range_max = bucket->max;
		else
			bucket->range_max = bucket->range_min + bucket->size - 1;
		ft_push_current_bucket(a, b, bucket);
		i++;
	}
	i--;
	return (i);
}

int	ft_bucket(t_stack *a, t_stack *b)
{
	t_bucket	bucket;
	int			i;
	int			j;

	bucket.nb = ft_sqrt(a->size);
	get_min_max(a, &bucket);
	bucket.size = (bucket.max - bucket.min + 1) / bucket.nb;
	i = create_bucket(a, b, &bucket);
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
			ft_push_max_range(a, b, bucket.range_min);
		}
		i--;
	}
	return (0);
}
