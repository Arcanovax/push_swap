/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seletion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:36:18 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/11 20:51:58 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_get_imin(t_stack *a, int size, int j, int min, t_log *log)
{
	int	i;
	int	imin;

	imin = 0;
	i = 0;
	while (i < size - j)
	{
		if (a->head->value < min)
		{
			min = a->head->value;
			imin = i;
		}
		ft_rotate_a(a, log);
		i++;
	}
	return (imin);
}

void	ft_push_min(t_stack *a, t_stack *b, int imin, t_log *log)
{
	int	i;

	i = 0;
	while (i < imin)
	{
		ft_rotate_a(a, log);
		i++;
	}
	ft_push_b(a, b, log);
}

void	ft_push_all(t_stack *a, t_stack *b, int size, t_log *log)
{
	int	j;

	j = 0;
	while (j < size - 1)
	{
		ft_push_a(a, b, log);
		j++;
	}
}

int	ft_seletion(t_stack *a, t_stack *b, t_log *log)
{
	int	imin;
	int	min;
	int	j;
	int	size;

	size = a->size;
	j = 0;
	while (j < size - 1)
	{
		min = a->head->value;
		imin = ft_get_imin(a, size, j, min, log);
		ft_push_min(a, b, imin, log);
		j++;
	}
	ft_push_all(a, b, size, log);
	return (0);
}
