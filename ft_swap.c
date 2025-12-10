/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:01:47 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/10 12:26:58 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);
	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
	return (0);
}

int	ft_swap_a(t_stack *a)
{
	if (ft_swap(a) == -1)
		return (0);
	if (write(1, "sa\n", 3) >= 0)
		return (0);
	return (-1);
}

int	ft_swap_b(t_stack *b)
{
	if (ft_swap(b) == -1)
		return (0);
	if (write(1, "sb\n", 3) >= 0)
		return (0);
	return (-1);
}

int	ft_swap_ab(t_stack *a, t_stack *b)
{
	int	res_a;
	int	res_b;

	res_a = ft_swap(a);
	res_b = ft_swap(b);
	if (res_a == 0 && res_b == 0)
		return (write(1, "ss\n", 3));
	else if (res_a == 0)
		return (write(1, "sa\n", 3) >= 0);
	else if (res_b == 0)
		return (write(1, "sb\n", 3));
	return (0);
}
