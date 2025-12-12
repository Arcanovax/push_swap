/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seletion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:36:18 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/11 12:40:53 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_get_imin(t_stack *a)
{
	int	i;
	int	imin;
	int	min;

	min = a->head->value;
	imin = 0;
	i = 0;
	while (i < a->size)
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

int	ft_seletion(t_stack *a, t_stack *b)
{
	int	imin;

	while (a->size > 0)
	{
		imin = ft_get_imin(a);
		ft_push_min(a, b, imin);
	}
	while (0 < b->size)
		ft_push_a(a, b);
	return (0);
}
