/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:05:04 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/11 20:56:05 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!(*stack))
		return (-1);
	(*stack)->head = NULL;
	(*stack)->tails = NULL;
	(*stack)->size = 0;
	return (0);
}

int	ft_init_log(t_log **log)
{
	*log = malloc(sizeof(t_log));
	if (!(*log))
		return (-1);
	(*log)->sa = 0;
	(*log)->sb = 0;
	(*log)->ss = 0;
	(*log)->pa = 0;
	(*log)->pb = 0;
	(*log)->ra = 0;
	(*log)->rb = 0;
	(*log)->rr = 0;
	(*log)->rra = 0;
	(*log)->rrb = 0;
	(*log)->rrr = 0;
	return (1);
}
