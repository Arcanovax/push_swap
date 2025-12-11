/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seletion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:36:18 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/11 10:01:47 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_seletion(t_stack *a, t_stack *b)
{
	int	imin;
	int	min;
	int	i;
	int	j;
	int	size;

	size = a->size;
	j = 0;
	while (j < size - 1)
	{
		i = 0;
		imin = 0;
		min = a->head->value;
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
		i = 0;
		while (i < imin)
		{
			ft_rotate_a(a);
			i++;
		}
		ft_push_b(a, b);
		j++;
	}
	j = 0;
	while (j < size - 1)
	{
		ft_push_a(a, b);
		j++;
	}
	return (0);
}

// ft_rotate_to_min(t_stack *a, int min)
// {
// 	while (i < imin)
// 		{
// 			ft_rotate_a(a);
// 			i++;
// 		}
// 		ft_push_b(a, b);
// }
