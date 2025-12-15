/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:44:31 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:20 by mboutte          ###   ########.fr       */
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

	printf("\n");
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

void	handle_flag(t_stack *a, t_stack *b, int flag, t_log *log)
{
	if (flag % 4 == 0)
		ft_radix(a, b, log);
	else if (flag % 4 == 1)
		ft_seletion(a, b, log);
	else if (flag % 4 == 2)
		ft_bucket(a, b, log);
	else if (flag % 4 == 3)
		ft_radix(a, b, log);
}

int	ft_bench_mode(t_stack *a, t_stack *b, int flag)
{
	double	cp_disorder;
	t_log	*log;

	if (ft_init_log(&log) == -1)
		return (-1);
	cp_disorder = compute_disorder(a);
	handle_flag(a, b, flag, log);
	ft_print_bench(cp_disorder, flag, log);
	free(log);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		flag;
	t_stack	*a;
	t_stack	*b;
	char	*str;

	i = 1;
	str = NULL;
	if (argc == 1)
		return (0);
	flag = 0;
	while (i <= argc && get_flag(argv[i], &flag))
		i++;
	if (init_stack(&a) == -1 || init_stack(&b) == -1)
		return (ft_free_all_on_error(NULL, a, NULL));
	if (i < argc)
		str = ft_alloc_str(argv[i++]);
	while (str && i < argc)
		str = ft_cat_nb(str, argv[i++]);
	if (!str || !ft_split_node(a, str))
		return (ft_free_all_on_error(NULL, a, NULL));
		if (flag & (1 << 2))
	{
		if (ft_bench_mode(a, b, flag) == -1)
			return (ft_free_all_on_error(str, a, b));
	}
	else
		handle_flag(a, b, flag, NULL);
	ft_print_stack(a);
	return (ft_free_exit(str, a, b));
}
