/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:16:27 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/10 12:44:45 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_set_unsigned(t_stack *stack)
// {
// 	int last_before;

// 	if (!stack || !stack->head)
// 		return ;
// 	last_before = stack->tails->value;
// 	while (stack->head->value != last_before)
// 	{
// 		stack->head->value -= INT_MIN;
// 		ft_rotate_a(stack);
// 	}
// 	stack->head->value -= INT_MIN;
// }

// void	ft_unset_unsigned(t_stack *stack)
// {
// 	int last_before;

// 	if (!stack || !stack->head)
// 		return ;
// 	last_before = stack->tails->value;
// 	while (stack->head->value != last_before)
// 	{
// 		stack->head->value += INT_MIN;
// 		ft_rotate_a(stack);
// 	}
// 	stack->head->value += INT_MIN;
// }

int	ft_randinx(t_stack *a, t_stack *b)
{
	int size;
	int bit;

	bit = 0;
	// ft_set_unsigned(a);
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
	// ft_unset_unsigned(a);
	// ft_rotate_a(a);
	return (0);
}
