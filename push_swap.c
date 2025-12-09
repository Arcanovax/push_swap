/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:44:31 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/09 15:27:20 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_atoi(const char *str, int *invalid, int *nb)
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
		if (str[i] < '0' || str[i] > '9')
		{
			*invalid = 1;
			return;
		}
		all = all * 10 + str[i] - '0';
		i++;
	}
	*nb = all * sign;
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
	t_node *node;
	node = stack->head;
	while(node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
}

int get_flag(char *arg, int *i)
{
	if (ft_strcmp(arg,"--simple") == 0)
	{
		*i += 1;
		return (1);
	}
	else if (ft_strcmp(arg,"--medium") == 0)
	{
		*i += 1;
		return (2);
	}
	else if (ft_strcmp(arg,"--complex") == 0)
	{
		*i += 1;
		return (3);
	}
	else if (ft_strcmp(arg,"--adaptive") == 0)
	{
		*i += 1;
		return (4);
	}
	return (0);
}

int init_stack(t_stack **stack, char *arg)
{
	struct s_node	*node;
	int 			invalid;
	int				nb;

	
	invalid = 0;
	ft_atoi(arg, &invalid, &nb);
	if (invalid)
		return (0);
	*stack = malloc(sizeof(t_stack));
	node = malloc(sizeof(t_node));
	node->prev = NULL;
	node->value = nb;
	(*stack)->head = node;
	(*stack)->tails = node;
	node->next = NULL;
	return(1);
}

int add_node(t_stack *stack, char *arg, int argc, int i)
{
	struct s_node	*new;
	struct s_node	*last;
	int				invalid;
	int				nb;

	last = stack->tails;
	if (argc == i)
	{
		stack->tails->next = NULL;
		return (1);
	}
	invalid = 0;
	ft_atoi(arg, &invalid, &nb);
	if (invalid == 0)
	{
		new = malloc(sizeof(t_node));
		last->next = new;
		new->prev= last;
		last = new;
		last->value = nb;
		stack->tails=last;
		return (1);
	}
	printf("Error");
	return (0);
}

int	main(int argc, char **argv)
{
	int				i;
	int				flag;
	struct s_stack	*stack;

	i = 1;
	if (argc <= 1)
		return (0);
	flag = get_flag(argv[1], &i);
	if (init_stack(&stack, argv[i]) == 0)
	{
		printf("Error");
		return (0);
	}
	i++;
	while (argv[i])
	{
		if (add_node(stack, argv[i], argc, i) == 0)
			return (0);
		i++;
	}
	if (flag == 1)
		printf("simple\n");
	display_stack(stack);
}

