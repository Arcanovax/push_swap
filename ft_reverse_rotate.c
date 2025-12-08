/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:17:32 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/08 18:09:27 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_reverse_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*current;

	if (!head || !*head || !(*head)->next)
		return (-1);
	last = *head;
	while (last->next->next)
		last = last->next;
	current = last->next;
	current->next = *head;
	*head = current;
	last->next = NULL;
	return (0);
}

int	ft_reverse_rotate_a(t_stack **a)
{
	if (ft_reverse_rotate(a) == -1)
		return (0);
	if (write(1, "rra\n", 4) >= 0)
		return (0);
	return (-1);
}

int	ft_reverse_rotate_b(t_stack **b)
{
	if (ft_reverse_rotate(b) == -1)
		return (0);
	if (write(1, "rrb\n", 4) >= 0)
		return (0);
	return (-1);
}

int	ft_reverse_rotate_ab(t_stack **a, t_stack **b)
{
	int	res_a;
	int	res_b;

	res_a = ft_reverse_rotate(a);
	res_b = ft_reverse_rotate(b);
	if (res_a == 0 && res_b == 0)
		return (write(1, "rrr\n", 4));
	else if (res_a == 0)
		return (write(1, "rra\n", 4) >= 0);
	else if (res_b == 0)
		return (write(1, "rrb\n", 4));
	return (0);
}
