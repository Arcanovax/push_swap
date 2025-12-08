/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:17:32 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/08 17:22:56 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse_rotate_a(t_stack **a)
{
	t_stack	*last;
	t_stack *current;

	if (!a || !*a || !(*a)->next)
		return (0);
	last = *a;
	while (last->next->next)
		last = last->next;
	current = last->next;
	current->next = *a;
	*a = current;
	last->next = NULL;
	if (write(1, "rra\n", 4) == -1)
		return (-1);
	return (0);
}

int	ft_reverse_rotate_b(t_stack **b)
{
	t_stack	*last;
	t_stack *current;

	if (!b || !*b || !(*b)->next)
		return (0);
	last = *b;
	while (last->next->next)
		last = last->next;
	current = last->next;
	current->next = *b;
	*b = current;
	last->next = NULL;
	if (write(1, "rrb\n", 4) == -1)
		return (-1);
	return (0);
}

int	ft_reverse_rotate_ab(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack *current;

	if (a && *a && (*a)->next && b && *b && (*b)->next)
	{
		last = *a;
		while (last->next->next)
			last = last->next;
		current = last->next;
		current->next = *a;
		*a = current;
		last->next = NULL;
		last = *b;
		while (last->next->next)
			last = last->next;
		current = last->next;
		current->next = *b;
		*b = current;
		last->next = NULL;
		if (write(1, "rrr\n", 4) == -1)
			return (-1);
		return (0);
	}
	if (a && *a && (*a)->next)
		return(ft_reverse_rotate_a(a));
	return (ft_reverse_rotate_b(b));
}
