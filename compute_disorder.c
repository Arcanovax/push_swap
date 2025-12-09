/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:01:04 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/09 09:34:01 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

	#include <stdio.h>
#include "push_swap.h"

double compute_disorder(t_stack *a)
{
	long		mistakes = 0;
	long		total_pairs = 0;
	t_stack		*i;
	t_stack		*j;

	i = a;

	while(i->next != NULL)
	{
		j = i->next;
		while(j != NULL)
		{
			total_pairs++;
			if(i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes/(double)total_pairs);
}
/*
int main(void)
{
	t_stack *a1;
	t_stack *a2;
	t_stack *a3;
	t_stack *a4;

	a1 = malloc(sizeof(t_stack));
	a2 = malloc(sizeof(t_stack));
	a3 = malloc(sizeof(t_stack));
	a4 = malloc(sizeof(t_stack));

	a1->value = 1;
	a1->next = a2;
	a2->value = 2;
	a2->next = a3;
	a3->value = 4;
	a3->next = a4;
	a4->value = 3;
	a4->next = NULL;

	printf("%f", compute_disorder(a1));
}
*/
