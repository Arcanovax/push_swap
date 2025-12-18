/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:24:13 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/18 14:03:52 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stk)
{
	t_node	*node;

	node = stk->head;
	__builtin_printf("\n\n");
	while (node)
	{
		__builtin_printf("%2d\n",node->value);
		node = node->next;
	}
}

int	get_bucket_imaxN(t_stack *b, int range_min)
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
	i = 0;
	current_node = b->tails;
	while (current_node && current_node->value >= range_min && i <= b->size)
	{
		if (current_node->value >= max)
		{
			max = current_node->value;
			imax = b->size - i - 1;
		}
		current_node = current_node->prev;
		i++;
	}

	return (imax);
}

static int	ft_push_max_rangeN(t_stack *a, t_stack *b, t_bucket *bucket, t_log *log)
{
	int	i;
	int	imax;
	int	error;

	error = 1;
	i = 0;
	imax = get_bucket_imaxN(b, bucket->range_min);

	if (imax <= b->size / 2)
	{
		while (i < imax && error > 0)
		{
			error = ft_rotate_b(b, log);
			i++;
		}
	}
	else
	{
		while (i < b->size - imax && error > 0)
		{
			error = ft_reverse_rotate_b(b, log);
			i++;
		}
	}

	if (error > 0)
		error = ft_push_a(a, b, log);

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
	int t = 0;

	i = bucket->nb;
	while (b->size )
	{
		j = 0;
		bucket->range_min = bucket->min + i * bucket->size;
		if (i == bucket->nb - 1)
			bucket->range_max = bucket->max;
		else
			bucket->range_max = bucket->range_min + bucket->size - 1;
		printf("min %d et max %d\n", bucket->range_min,bucket->range_max);
		while ((b->head && b->head->value >= bucket->range_min))
		{
			if (!b->head)
				break ;
			if (ft_push_max_rangeN(a, b, bucket, log) < 0)
				return (-1);
		}
		printf("\nAFTER\n");
		print_stack(a);
		print_stack(b);
		t++;
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
