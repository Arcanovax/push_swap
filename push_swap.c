/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:44:31 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/18 15:30:47 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_flag(t_stack *a, t_stack *b, int flag, t_log *log)
{
	if (flag % 4 == 1)
		return (ft_seletion(a, b, log));
	else if (flag % 4 == 2)
		return (ft_bucket(a, b, log));
	else if (flag % 4 == 3)
		return (ft_radix(a, b, log));
	if (((1 - compute_disorder(a)) * a->size) > 20)
		return (ft_radix(a, b, log));
	else
		return (ft_seletion(a, b, log));
}

static int	ft_sort_stack(t_stack *a, t_stack *b, int flag)
{
	t_log	*log;
	double	cp_disorder;

	cp_disorder = compute_disorder(a);
	log = NULL;
	if (flag & (1 << 2))
		if (ft_init_log(&log) == -1)
			return (-1);
	if (cp_disorder != 1 && handle_flag(a, b, flag, log) == -1)
	{
		free(log);
		return (-1);
	}
	if (flag & (1 << 2))
		ft_print_bench(cp_disorder, flag, log, a->size);
	if (log)
		free(log);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		flag;
	char	*str;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	flag = 0;
	i = 1;
	while (i < argc && get_flag(argv[i], &flag))
		i++;
	if (init_stack(&a) == -1 || init_stack(&b) == -1)
		return (ft_free_all_on_error(NULL, a, NULL));
	str = NULL;
	if (i < argc)
		str = ft_alloc_str(argv[i++]);
	while (str && i < argc)
		str = ft_cat_nb(str, argv[i++]);
	if (!str || (ft_split_node(a, str) < 0) || !a->head)
		return (ft_free_all_on_error(str, a, b));
	if (ft_sort_stack(a, b, flag) == -1)
		return (ft_free_all_on_error(str, a, b));
	return (ft_free_exit(str, a, b));
}
