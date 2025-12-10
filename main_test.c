/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:00:35 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/10 12:36:31 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_stack(t_stack *stk)
{
	t_node *node = stk->head;
	__builtin_printf("stack\nhead: % 2d|%p\ntails:%2d|%p\nsize:%3d|\n", stk->head->value, stk->head, stk->tails->value, stk->tails, stk->size);
	while (node) {
		__builtin_printf("prev:%10p|node_a:%2d|%p|next:%-10p\n",node->prev, node->value, node, node->next);
		node = node->next;
	}
}

static void ft_free_stack(t_stack *stk)
{
	t_node *node = stk->head;
	t_node *next;
	
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

	stk_b->head =  NULL;
	stk_b->tails = NULL;
	stk_b->size =  0;

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

}