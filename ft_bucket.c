/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:24:13 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/12 13:50:53 by mthetcha         ###   ########lyon.fr   */
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

void	get_min_max(t_stack *a, int *min, int *max)
{
	int	i;

	i = 0;
	*min = a->head->value;
	*max = a->head->value;
	while (i < a->size)
	{
		ft_rotate_a(a);
		if (a->head->value < *min)
			*min = a->head->value;
		if (a->head->value > *max)
			*max = a->head->value;
		i++;
	}
}

void	ft_push_imax(t_stack *a, t_stack *b, int i, int imax)
{
	while (i != imax)
	{
		ft_reverse_rotate_b(b);
		i--;
	}
	ft_push_a(a, b);
	while (i != 0)
	{
		ft_reverse_rotate_b(b);
		i--;
	}
}

void	ft_push_max_range(t_stack *a, t_stack *b, int range_min, int range_max)
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
	ft_push_imax(a, b, i, imax);
}


int	ft_bucket(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	nb_bucket;
	int bucket_size;
	int range_min;//
	int range_max;//
	int i;
	int j;//

	i = 0;
	j = 0;
	nb_bucket = ft_sqrt(a->size);
	get_min_max(a, &min, &max);
	bucket_size = (max - min + 1) / nb_bucket;
	//create_bucket(t_stack *a, t_stack *b, int min, int max)
	while (i < nb_bucket)
	{
		j = 0;
		range_min = min + i * bucket_size;
		if (i == nb_bucket - 1)
			range_max = max;
		else
			range_max = range_min + bucket_size - 1;
		printf("Bucket %d : [%d .. %d]\n", i + 1, range_min, range_max);
		while(j < a->size + b->size)
		{
			if (!a->head)
				break;
			if (a->head->value >= range_min && a->head->value <= range_max)
				ft_push_b(a,b);
			else
				ft_rotate_a(a);
			j++;
		}
		i++;
	}
	i--;
	while (i >= 0)
	{
		j = 0;
		range_min = min + i * bucket_size;
		if (i == nb_bucket - 1)
			range_max = max;
		else
			range_max = range_min + bucket_size - 1;
		printf("Bucket %d : [%d .. %d]\n", i + 1, range_min, range_max);
		while(b->head && b->head->value >= range_min)
		{
			if (!b->head)
				break;
			ft_push_max_range(a, b, range_min, range_max);
		}
		i--;
	}
	return (0);
}
