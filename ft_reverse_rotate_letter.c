/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_letter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:17:32 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/19 11:20:57 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse_rotate_a(t_stack *a, t_log *log)
{
	if (ft_reverse_rotate(a) == -1)
		return (0);
	if (log)
		log->rra += 1;
	return (write(1, "rra\n", 4));
}

int	ft_reverse_rotate_b(t_stack *b, t_log *log)
{
	if (ft_reverse_rotate(b) == -1)
		return (0);
	if (log)
		log->rrb += 1;
	return (write(1, "rrb\n", 4));
}

int	ft_reverse_rotate_ab(t_stack *a, t_stack *b, t_log *log)
{
	if (ft_reverse_rotate_rotate(a, b) == -1)
		return (-1);
	if ((log))
		log->rrr += 1;
	return (write(1, "rrr\n", 4));
}
