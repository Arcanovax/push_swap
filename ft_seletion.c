/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seletion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:36:18 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/11 10:29:17 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_get_imin(t_stack *a, int size, int j, int min)
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
		ft_rotate_a(a);
		i++;
	}
	return (imin);
}

void	ft_push_min(t_stack *a, t_stack *b, int imin)
{
	int	i;

	i = 0;
	while (i < imin)
	{
		ft_rotate_a(a);
		i++;
	}
	ft_push_b(a, b);
}

void	ft_push_all(t_stack *a, t_stack *b, int size)
{
	int	j;

	j = 0;
	while (j < size - 1)
	{
		ft_push_a(a, b);
		j++;
	}
}

int	ft_seletion(t_stack *a, t_stack *b)
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
		imin = ft_get_imin(a, size, j, min);
		ft_push_min(a, b, imin);
		j++;
	}
	ft_push_all(a, b, size);
	return (0);
}
