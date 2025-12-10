/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:44:31 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/10 14:43:40 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	all;
	int	sign;
	int	i;

	i = 0;
	all = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -sign;
	}
	while (str[i] != '\0')
	{
		all = all * 10 + str[i] - '0';
		i++;
	}
	return (all * sign);
}

int	add_node(t_stack *stack, int nb)
{
	struct s_node	*new;
	struct s_node	*last;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
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
	stack->tails = new;
	return (1);
}

static int	ft_split_size_allocate(const char *s, char c)
{
	size_t	i;
	size_t	size;
	int		in_sep;

	in_sep = 1;
	i = 0;
	size = 0;
	while (s[i])
	{
		if (in_sep == 1 && s[i] != c)
		{
			size++;
			in_sep = 0;
		}
		else if (in_sep == 0 && s[i] == c)
			in_sep = 1;
		i++;
	}
	return (size + 1);
}

static int	ft_split_add(char **split, size_t *i, const char *str, char sep)
{
	size_t	end;
	size_t	j;

	while (str[*i] && (char) str[*i] == sep)
		(*i)++;
	end = *i;
	while (str[end] && (char) str[end] != sep)
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
		(*split)[j++] = (char) str[(*i)++];
	(*split)[j] = '\0';
	return (0);
}

static void	ft_freeing(char ***split, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
		free((*split)[i++]);
	free(*split);
	*split = NULL;
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
		if (!result)
			return (1);
		nb = ft_atoi(result);
		if (!add_node(stack, nb))
			return (0);
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
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

void	display_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->head)
		return ;
	node = stack->head;
	while (node)
	{
		printf("%d\n", node->value);
		if (node == stack->tails)
			return ;
		node = node->next;
	}
}

int	get_flag(char *arg, int *i)
{
	if (ft_strcmp(arg, "--simple") == 0)
	{
		*i += 1;
		return (1);
	}
	else if (ft_strcmp(arg, "--medium") == 0)
	{
		*i += 1;
		return (2);
	}
	else if (ft_strcmp(arg, "--complex") == 0)
	{
		*i += 1;
		return (3);
	}
	else if (ft_strcmp(arg, "--adaptive") == 0)
	{
		*i += 1;
		return (4);
	}
	return (0);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tails = NULL;
	// stack->size = 0;
	return (stack);
}

int	main(int argc, char **argv)
{
	int			i;
	int			flag;
	t_stack		*stack;

	i = 1;
	if (argc <= 1)
		return (0);
	flag = get_flag(argv[1], &i);
	stack = init_stack();
	if (!stack)
	{
		printf("Error");
		return (0);
	}
	if (!ft_split_node(stack, argv[1]))
	{
		printf("Error");
		return (0);
	}
	if (flag == 1)
		printf("simple\n");
	printf("\nDisplay:\n");
	display_stack(stack);
}
