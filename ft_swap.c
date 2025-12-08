/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:01:47 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/08 14:25:21 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_a(t_stack *a)
{
	int	tmp;

	if (a == NULL || a->next == NULL)
		return (0);
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	if (write(1, "sa", 2) == -1)
		return (-1);
	return (0);
}

int	ft_swap_b(t_stack *b)
{
	int	tmp;

	if (b == NULL || b->next == NULL)
		return (0);
	tmp = b->value;
	b->value = b->next->value;
	b->next->value = tmp;
	if (write(1, "sb", 2) == -1)
		return (-1);
	return (0);
}

int	ft_swap_ab(t_stack *a, t_stack *b)
{
	int	tmp;

	if (!(a == NULL || a->next == NULL))
	{
		tmp = a->value;
		a->value = a->next->value;
		a->next->value = tmp;
	}
	if (!(b == NULL || b->next == NULL))
	{
		tmp = b->value;
		b->value = b->next->value;
		b->next->value = tmp;
	}
	if (write(1, "ss", 2) == -1)
		return (-1);
	return (0);
}
