/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:17:32 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/08 16:28:22 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse_rotate_a(t_stack **a)
{
	t_stack	*current_node;
	t_stack *new_start;

	if (!a || !*a == NULL || !(*a)->next)
		return (0);
	
	
		current_node = *a;
	while (current_node->next != NULL)
		current_node = current_node->next;

	new_start = current_node;

	new_start->next = *a;
	*a = NULL;
	
	current_node->next = *a;
	*a = current_node;
	current_node;
	(*a)->next;
	current_node->next->next = NULL;

	
	if (write(1, "rra\n", 4) == -1)
		return (-1);
	return (0);
}