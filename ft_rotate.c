/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:39:58 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/08 16:52:38 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_a(t_stack **a)
{
	t_stack	*current_node;

	if (!a || !*a || !(*a)->next)
		return (0);
	current_node = *a;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = *a;
	*a = (*a)->next;
	current_node->next->next = NULL;
	if (write(1, "ra\n", 3) == -1)
		return (-1);
	return (0);
}

int	ft_rotate_b(t_stack **b)
{
	t_stack	*current_node;

	if (!b || !*b || !(*b)->next)
		return (0);
	current_node = *b;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = *b;
	*b = (*b)->next;
	current_node->next->next = NULL;
	if (write(1, "rb\n", 3) == -1)
		return (-1);
	return (0);
}
int	ft_rotate_ab(t_stack **a, t_stack **b)
{
	t_stack	*current_node;
	
	if (a && *a && (*a)->next && b && *b && (*b)->next)
	{
		current_node = *b;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = *b;
		*b = (*b)->next;
		current_node->next->next = NULL;
		current_node = *a;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = *a;
		*a = (*a)->next;
		current_node->next->next = NULL;	
		if (write(1, "rr\n", 3) == -1)
			return (-1);
		return (0);
	}
	if (a && *a && (*a)->next)
		return (ft_rotate_a(a));
	else
		return (ft_rotate_b(b));
}
