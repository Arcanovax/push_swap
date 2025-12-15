/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:00:35 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/15 13:32:27 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stk)
{
	t_node	*node;

	node = stk->head;
	__builtin_printf("stack\nhead: % 2d|%p\ntails:%2d|%p\nsize:%3d|\n",
		stk->head->value, stk->head, stk->tails->value, stk->tails, stk->size);
	while (node)
	{
		__builtin_printf("prev:%10p|node_a:%2d|%p|next:%-10p\n", node->prev,
			node->value, node, node->next);
		node = node->next;
	}
}

/*
static void	ft_free_stack(t_stack *stk)
{
	t_node	*node;
	t_node	*next;

	node = stk->head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(stk);
}

int	main(void)
{
	t_node *a1 = malloc(sizeof(t_node));
	t_node *a2 = malloc(sizeof(t_node));
	t_node *a3 = malloc(sizeof(t_node));
	t_node *a4 = malloc(sizeof(t_node));
	t_stack *stk_a = malloc(sizeof(t_stack));

	a1->prev = NULL;
	a1->value = 1;
	a1->next = a2;
	a2->prev = a1;
	a2->value = 2;
	a2->next = a3;
	a3->prev = a2;
	a3->value = 3;
	a3->next = a4;
	a4->prev = a3;
	a4->value = 4;
	a4->next = NULL;

	stk_a->head = a1;
	stk_a->tails = a4;
	stk_a->size = 4;

	// t_node *b1 = malloc(sizeof(t_node));
	// t_node *b2 = malloc(sizeof(t_node));
	// t_node *b3 = malloc(sizeof(t_node));
	// t_node *b4 = malloc(sizeof(t_node));
	t_stack *stk_b = malloc(sizeof(t_stack));

	// b1->prev = NULL;
	// b1->value = 5;
	// b1->next = b2;
	// b2->prev = b1;
	// b2->value = 6;
	// b2->next = b3;
	// b3->prev = b2;
	// b3->value = 7;
	// b3->next = b4;
	// b4->prev = b3;
	// b4->value = 8;
	// b4->next = NULL;

	stk_b->head = NULL;
	stk_b->tails = NULL;
	stk_b->size = 0;

	// // test_ft_swap()
	// ft_print_stack(stk_a);
	// ft_swap_a(stk_a);
	// ft_print_stack(stk_a);

	// // test ft_push()
	// ft_print_stack(stk_a); ft_print_stack(stk_b);
	// ft_push_a(stk_a, stk_b);
	// ft_print_stack(stk_a); ft_print_stack(stk_b);

	// // test ft_reverse_rotate() and / or ft_rotate()
	// ft_print_stack(stk_a);
	// ft_rotate_a(stk_a);
	// ft_reverse_rotate_a(stk_a);
	// ft_print_stack(stk_a);
	// ft_free_stack(stk_a);

	ft_print_stack(stk_a);
	ft_randinx(stk_a, stk_b);
	ft_print_stack(stk_a);
	ft_free_stack(stk_a);
*/

// proto test no i in main :

// int	get_flag(char ***arg)
// {
// 	if (ft_strcmp(**arg, "--simple") == 0)
// 	{
// 		++(*arg);
// 		return (1);
// 	}
// 	else if (ft_strcmp(**arg, "--medium") == 0)
// 	{
// 		++(*arg);
// 		return (2);
// 	}
// 	else if (ft_strcmp(**arg, "--complex") == 0)
// 	{
// 		++(*arg);
// 		return (3);
// 	}
// 	else if (ft_strcmp(**arg, "--adaptive") == 0)
// 	{
// 		++(*arg);
// 		return (4);
// 	}
// 	return (4);
// }

// int	main(int argc, char **argv)
// {
// 	int		flag;
// 	t_stack	*a;
// 	t_stack	*b;
// 	char	*str;

// 	++(argv);
// 	if (--argc <= 0)
// 		return (write(1, "put arg", 7));
// 	flag = get_flag(&argv);
// 	if (init_stack(&a) == -1 || init_stack(&b) == -1)
// 		return (ft_free_all_on_error(NULL, a, NULL));
// 	if (*argv)
// 		str = ft_alloc_str(*argv);
// 	++argv;
// 	while (str && (*argv)) {
// 		str = ft_cat_nb(str, *argv);
// 		(++argv);
// 	}
// 	if (!str || !ft_split_node(a, str))
// 		return (ft_free_all_on_error(NULL, a, NULL));
// 	handle_flag(a, b, flag);
// 	// ft_print_stack(a);
// 	// display_stack(a);

// 	// write(1, "\033[1;31m", 7);
// 	// write(1, "Texte en rouge", 24);
// 	// write(1, "\033[0m", 4);
// 	return (ft_free_exit(str, a, b));