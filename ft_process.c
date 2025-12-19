/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:07:03 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/19 12:52:48 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_full_of_int(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!('0' <= str[i] && str[i] <= '9') && !(str[i] == ' ')
			&& !(9 <= str[i] && str[i] <= 13) && !(str[i] == '-')
			&& !(str[i] == '+'))
			return (0);
	return (1);
}

int	ft_strlen_secure(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_cat_nb(char *base, char *cating)
{
	int		i;
	char	*new_str;

	if (ft_full_of_int(cating) == 0)
	{
		free(base);
		return (NULL);
	}
	new_str = malloc(sizeof(char) * (ft_strlen_secure(base)
				+ ft_strlen_secure(cating) + 2));
	if (!new_str)
	{
		free(base);
		return (NULL);
	}
	i = -1;
	while (base[++i])
		new_str[i] = base[i];
	new_str[i++] = ' ';
	while (*cating)
		new_str[i++] = *cating++;
	new_str[i] = '\0';
	free(base);
	return (new_str);
}

char	*ft_alloc_str(char *str)
{
	char	*new_str;
	int		i;

	if (ft_full_of_int(str) == 0)
		return (NULL);
	new_str = malloc(sizeof(char) * ft_strlen_secure(str) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
