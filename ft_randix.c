/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:16:27 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/10 15:54:24 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_randinx(t_stack *a, t_stack *b)
{
	int size;
	int bit;

	bit = 0;
	while (bit < 32)
	{
		size = a->size;
		while (size--)
		{
			if (((a->head->value - INT_MIN) >> bit) & 1)
				ft_push_b(a, b);
			else
				ft_rotate_a(a);
		}
		while (b->head)
			ft_push_a(a, b);
		bit++;
	}
	return (0);
}
