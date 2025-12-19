/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:36:00 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/19 12:36:14 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

char	*get_next_line(int fd);

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((s1[i] == '\0') || (s1[i] < s2[i]))
			return (-1);
		if ((s2[i] == '\0') || (s1[i] > s2[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_empty_char(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	j = 0;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (1);
}

int	ft_exec(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (ft_swap(a));
	else if (ft_strcmp(str, "sb\n") == 0)
		return (ft_swap(b));
	else if (ft_strcmp(str, "ss\n") == 0)
		return (ft_swap_swap(a, b));
	else if (ft_strcmp(str, "pa\n") == 0)
		return (ft_push(a, b));
	else if (ft_strcmp(str, "pb\n") == 0)
		return (ft_push(b, a));
	else if (ft_strcmp(str, "ra\n") == 0)
		return (ft_rotate(a));
	else if (ft_strcmp(str, "rb\n") == 0)
		return (ft_rotate(b));
	else if (ft_strcmp(str, "rr\n") == 0)
		return (ft_rotate_rotate(a, b));
	else if (ft_strcmp(str, "rra\n") == 0)
		return (ft_reverse_rotate(a));
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (ft_reverse_rotate(b));
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (ft_reverse_rotate_rotate(a, b));
	return (-1);
}

int	parcing(int argc, char **argv, t_stack **a, t_stack **b)
{
	int		i;
	char	*str;

	if (init_stack(a) == -1 || init_stack(b) == -1)
		return (ft_free_all_on_error(NULL, *a, *b));
	if (argc == 1)
		return (0);
	i = 1;
	str = NULL;
	if (i < argc)
		str = ft_alloc_str(argv[i++]);
	while (str && i < argc)
		str = ft_cat_nb(str, argv[i++]);
	if ((ft_split_node(*a, str) < 0) || !(*a)->head)
	{
		if (str)
			free(str);
		return (-1);
	}
	if (str)
		free(str);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;

	if (parcing(argc, argv, &a, &b) < 0 || a->size == 0)
		return (ft_free_all_on_error(NULL, a, b));
	line = get_next_line(0);
	while (line)
	{
		if (ft_exec(line, a, b) == -1)
		{
			free(line);
			return (ft_free_all_on_error(NULL, a, b));
		}
		free(line);
		line = get_next_line(0);
	}
	if (compute_disorder(a) == 1)
		write(1, "\033[38;2;0;255;0m[OK]\033[0m\n", 24);
	else
		write(1, "\033[38;2;255;0;0m[KO]\033[0m\n", 24);
	ft_free_exit(NULL, a, b);
	return (0);
}
