/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:01:47 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/08 16:16:10 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_a(t_stack *a)
{
	int	tmp;

	if (!a || !a->next)
		return (0);
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	if (write(1, "sa\n", 3) == -1)
		return (-1);
	return (0);
}

int	ft_swap_b(t_stack *b)
{
	int	tmp;

	if (!b || !b->next)
		return (0);
	tmp = b->value;
	b->value = b->next->value;
	b->next->value = tmp;
	if (write(1, "sb\n", 3) == -1)
		return (-1);
	return (0);
}

int	ft_swap_ab(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a && a->next && b && b->next)
	{
		tmp = a->value;
		a->value = a->next->value;
		a->next->value = tmp;
		tmp = b->value;
		b->value = b->next->value;
		b->next->value = tmp;
		if (write(1, "ss\n", 3) == -1)
			return (-1);
		return (0);
	}
	if (a && a->next)
		return (ft_swap_a(a));
	else
		return (ft_swap_a(b));
}
