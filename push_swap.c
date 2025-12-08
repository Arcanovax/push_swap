/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:49:49 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/08 14:29:36 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *a_bis;
	t_stack *b;
	t_stack *b_bis;

	a = malloc(sizeof(t_stack));
	a_bis = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	b_bis = malloc(sizeof(t_stack));

	a->value = 1;
	a->next = a_bis;
	a_bis->value = 2;
	b->value = 3;
	b->next = b_bis;
	b_bis->value = 4;

	__builtin_printf("a:%d|a:%d\n", a->value, a->next->value);
	__builtin_printf("b:%d|b:%d\n", b->value, b->next->value);
	ft_swap_ab(a, b);
	__builtin_printf("a:%d|a:%d\n", a->value, a->next->value);
	__builtin_printf("b:%d|b:%d\n", b->value, b->next->value);
	return (0);
}
