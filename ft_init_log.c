/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_log.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:59:50 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/19 15:00:09 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
