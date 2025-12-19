/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:01:47 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/19 12:21:42 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

int	ft_swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);
	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
	return (0);
}

int	ft_swap_swap(t_stack *a, t_stack *b)
{
	if (ft_swap(a) == 0 && ft_swap(b) == 0)
		return (0);
	return (-1);
}
