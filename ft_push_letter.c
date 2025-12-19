/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_letter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:33:35 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/19 11:22:06 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_a(t_stack *a, t_stack *b, t_log *log)
{
	if (ft_push(a, b) == -1)
		return (0);
	if (log)
		log->pa += 1;
	return (write(1, "pa\n", 3));
}

int	ft_push_b(t_stack *a, t_stack *b, t_log *log)
{
	if (ft_push(b, a) == -1)
		return (0);
	if (log)
		log->pb += 1;
	return (write(1, "pb\n", 3));
}
