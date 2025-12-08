/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:33:35 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/08 16:19:03 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_push_a(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (*b == NULL)
		return (0);
	tmp = *b;
	(*b) = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (write(1, "pa\n", 3) == -1)
		return (-1);
	return (0);
}

int ft_push_b(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (*a == NULL)
		return (0);
	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (write(1, "pb\n", 3) == -1)
		return (-1);
	return (0);
}

