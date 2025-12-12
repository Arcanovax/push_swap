/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seletion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:36:18 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/12 15:28:26 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_get_imin(t_stack *a, t_log *log)
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

int	ft_seletion(t_stack *a, t_stack *b, t_log *log)
{
	int	imin;

	while (a->size > 0)
	{
		imin = ft_get_imin(a, log);
		ft_push_min(a, b, imin, log);
	}
	while (0 < b->size)
		ft_push_a(a, b, log);
	return (0);
}
