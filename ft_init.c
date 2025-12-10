/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:05:04 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/10 17:10:37 by mboutte          ###   ########.fr       */
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
