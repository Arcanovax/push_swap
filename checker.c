/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:36:00 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/16 16:59:09 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int j;

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

// int	ft_verif_output(char *str)
// {
// 	if (ft_strcmp(str, "sa\n") == 0)
// 		return (1);
// 	else if (ft_strcmp(str, "sb\n") == 0)
// 		return (1);
// 	else if (ft_strcmp(str, "ss\n") == 0)
// 		return (1);
// 	else if (ft_strcmp(str, "pa\n") == 0)
// 		return (1);
// 	else if (ft_strcmp(str, "pb\n") == 0)
// 		return (1);
// 	else if (ft_strcmp(str, "ra\n") == 0)
// 		return (1);
// 	else if (ft_strcmp(str, "rb\n") == 0)
// 		return (1);
// 	else if (ft_strcmp(str, "rr\n") == 0)
// 		return (1);
// 	else if (ft_strcmp(str, "rra\n") == 0)
// 		return (1);
// 	else if (ft_strcmp(str, "rrb\n") == 0)
// 		return (1);
// 	else if (ft_strcmp(str, "rrr\n") == 0)
// 		return (1);
// 	return (-1);
// }

int	ft_exec(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (ft_swap(a));
	else if (ft_strcmp(str, "sb\n") == 0)
		return (ft_swap(b));
	else if (ft_strcmp(str, "ss\n") == 0) {
		(ft_swap(a));
		return (ft_swap(b));
	}
	else if (ft_strcmp(str, "pa\n") == 0)
		return (ft_push(a, b));
	else if (ft_strcmp(str, "pb\n") == 0)
		return (ft_push(b, a));
	else if (ft_strcmp(str, "ra\n") == 0)
		return (ft_rotate(a));
	else if (ft_strcmp(str, "rb\n") == 0)
		return (ft_rotate(b));
	else if (ft_strcmp(str, "rr\n") == 0) {
		ft_rotate(a);
		return (ft_rotate(b));
	}
	else if (ft_strcmp(str, "rra\n") == 0)
		return (ft_reverse_rotate(a));
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (ft_reverse_rotate(b));
	else if (ft_strcmp(str, "rrr\n") == 0) {
		(ft_reverse_rotate(a));
		return (ft_reverse_rotate(b));
	}
	__builtin_printf("commande not found");
	return (-1);
}

int	parcing(int argc, char **argv, t_stack *a)
{
	int		i;
	char	*str;

	if (argc == 1)
		return (0);
	i = 1;
	str = NULL;
	if (i < argc)
		str = ft_alloc_str(argv[i++]);
	while (str && i < argc)
		str = ft_cat_nb(str, argv[i++]);
	if (!str || (ft_split_node(a, str) < 0) || !a->head)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	ch[64];
	int		byte_read;
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (init_stack(&a) == -1 || init_stack(&b) == -1)
		return (ft_free_all_on_error(NULL, a, NULL));
	parcing(argc, argv, a);
	byte_read = read(0, ch, sizeof(ch) - 1);
	ch[byte_read] = '\0';
	while ((byte_read > 0))
	{
		if (ft_exec(ch, a, b) == -1) {
			__builtin_printf("Error + need to free");
			return (-1);
		} 
		ft_empty_char(ch);
		byte_read = read(0, ch, sizeof(ch) - 1);
		ch[byte_read] = '\0';
	}
	if (compute_disorder(a) == 1)
		write(1, "\033[38;2;0;255;0m[OK]\033[0m\n", 24);
	else
		write(1, "\033[38;2;255;0;0m[OK]\033[0m\n", 24);
	// allfree();
	return (0);
}
