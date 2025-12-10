/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:44:31 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/10 17:20:26 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	return (4);
}

void	handle_flag(t_stack *a, t_stack *b, int flag)
{
	if (flag == 1)
		ft_seletion(a, b);
	else if (flag == 2)
		printf("\nmedium");
	else if (flag == 3)
		printf("\ncomplex");
	else if (flag == 4)
		ft_randinx(a, b);
}

int	main(int argc, char **argv)
{
	int		i;
	int		flag;
	t_stack	*a;
	t_stack	*b;
	char	*str;

	i = 1;
	if (argc <= 1)
		return (0);
	flag = get_flag(argv[1], &i);
	if (init_stack(&a) == -1 || init_stack(&b) == -1)
		return (ft_free_all_error(NULL, a, NULL));
	str = ft_alloc_str(argv[i]);
	while (str && ++i < argc)
		str = ft_cat_nb(str, argv[i]);
	if (!str || !ft_split_node(a, str))
		return (ft_free_all_error());
	handle_flag(flag, a, b);
	return (ft_free_exit(str, a, b));
}
