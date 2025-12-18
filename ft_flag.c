/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:15:32 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/18 11:58:50 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((s1[i] == '\0') || (s1[i] < s2[i]))
			return (-1);
		if ((s2[i] == '\0') || (s1[i] > s2[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_set_flag(int *flag, int n)
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
