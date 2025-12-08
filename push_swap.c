/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:49:49 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/08 15:21:46 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	t_stack *c;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	c = malloc(sizeof(t_stack));

	a->value = 1;
	a->next = b;
	b->value = 2;
	b->next = c;
	c->value = 3;
	c->next = NULL;

	
	__builtin_printf("a:%d|b:%d|c:%d\n", a->value, a->next->value, a->next->next->value);
	ft_rotate_a(&a);
	__builtin_printf("a:%d|b:%d|c:%d\n", a->value, a->next->value, a->next->next->value);
	return (0);
}
