/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:15:32 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/16 11:19:59 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_flag(int *flag, int n)
{
	*flag += n;
	if (n < 4)
		*flag += 8;
	return (1);
}

int	get_flag(char *arg, int *flag)
{
	if (ft_strcmp(arg, "--adaptive") == 0 && *flag < 8)
		return (ft_set_flag(flag, 0));
	else if (ft_strcmp(arg, "--simple") == 0 && *flag < 8)
		return (ft_set_flag(flag, 1));
	else if (ft_strcmp(arg, "--medium") == 0 && *flag < 8)
		return (ft_set_flag(flag, 2));
	else if (ft_strcmp(arg, "--complex") == 0 && *flag < 8)
		return (ft_set_flag(flag, 3));
	else if (ft_strcmp(arg, "--bench") == 0 && (!(*flag & (1 << 2))))
		return (ft_set_flag(flag, 4));
	return (0);
}
