/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:39:58 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/18 16:01:27 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*tails;

	if (!stack || !stack->head || !stack->tails)
		return (-1);
	head = stack->head;
	tails = stack->tails;
	if (!head->next || !tails->prev)
		return (-1);
	stack->head = head->next;
	stack->head->prev = NULL;
	head->next = NULL;
	head->prev = tails;
	tails->next = head;
	stack->tails = head;
	return (0);
}

int	ft_rotate_rotate(t_stack *a, t_stack *b)
{
	if (ft_rotate(a) == 0 && ft_rotate(b) == 0)
		return (0);
	return (-1);
}

int	ft_rotate_a(t_stack *a, t_log *log)
{
	if (ft_rotate(a) == -1)
		return (-1);
	if (log)
		log->ra += 1;
	return (write(1, "ra\n", 3));
}

int	ft_rotate_b(t_stack *b, t_log *log)
{
	if (ft_rotate(b) == -1)
		return (-1);
	if (log)
		log->rb += 1;
	return (write(1, "rb\n", 3));
}

int	ft_rotate_ab(t_stack *a, t_stack *b, t_log *log)
{
	if (ft_rotate_rotate(a, b) == -1)
		return (-1);
	if ((log))
		log->rr += 1;
	return (write(1, "rr\n", 3));
}
