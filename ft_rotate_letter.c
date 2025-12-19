/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_letter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:39:58 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/19 11:19:52 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
