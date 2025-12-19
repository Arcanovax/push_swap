/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:02:58 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/19 13:13:19 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

static int	ft_atoi_stack(const char *str)
{
	int	all;
	int	sign;
	int	i;

	i = 0;
	all = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		all = all * 10 + str[i] - '0';
		i++;
	}
	return (all * sign);
}

static int	add_node(t_stack *stack, int nb)
{
	struct s_node	*new;
	struct s_node	*last;

	new = malloc(sizeof(t_node));
	if (!new)
		return (-1);
	new->value = nb;
	new->next = NULL;
	if (stack->tails)
	{
		last = stack->tails;
		new->next = NULL;
		new->prev = last;
		last->next = new;
	}
	else
	{
		stack->head = new;
		new->prev = NULL;
	}
	stack->size++;
	stack->tails = new;
	return (1);
}

static int	ft_split_add(char **split, size_t *i, const char *str, char sep)
{
	size_t	end;
	size_t	j;

	while (str[*i] && (char)str[*i] == sep)
		(*i)++;
	end = *i;
	while (str[end] && (char)str[end] != sep)
		end++;
	if (str[*i] == '\0')
	{
		*split = (NULL);
		return (1);
	}
	*split = malloc(sizeof(char) * (end - *i + 1));
	if (!*split)
		return (-1);
	j = 0;
	while (*i < end)
		(*split)[j++] = (char)str[(*i)++];
	(*split)[j] = '\0';
	return (0);
}

int	ft_split_node(t_stack *stack, char const *s)
{
	int		state;
	char	*result;
	int		nb;
	size_t	i;

	i = 0;
	state = 0;
	if (!s)
		return (0);
	while (state == 0)
	{
		state = ft_split_add(&result, &i, s, ' ');
		if (state < 0)
			return (-1);
		if (!result)
			return (1);
		nb = ft_atoi_stack(result);
		free(result);
		if (add_node(stack, nb) < 0)
			return (-1);
	}
	return (1);
}
