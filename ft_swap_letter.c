/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_letter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:01:47 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/19 11:18:15 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_a(t_stack *a, t_log *log)
{
	if (ft_swap(a) == -1)
		return (-1);
	if (log)
		log->sa += 1;
	return (write(1, "sa\n", 3) >= 0);
}

int	ft_swap_b(t_stack *b, t_log *log)
{
	if (ft_swap(b) == -1)
		return (-1);
	if (log)
		log->sb += 1;
	return (write(1, "sb\n", 3));
}

int	ft_swap_ab(t_stack *a, t_stack *b, t_log *log)
{
	if (ft_swap_swap(a, b) == -1)
		return (-1);
	if ((log))
		log->ss += 1;
	return (write(1, "ss\n", 3));
}
