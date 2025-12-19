/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:48:58 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/19 11:12:34 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

static void	ft_free_t_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	if (stack)
	{
		node = stack->head;
		while (node)
		{
			next = node->next;
			free(node);
			node = next;
		}
		free(stack);
	}
}

int	ft_free_all_on_error(char *str, t_stack *a, t_stack *b)
{
	if (str)
		free(str);
	if (a)
		free(a);
	if (b)
		free(b);
	write(1, "Error", 5);
	return (-1);
}

int	ft_free_exit(char *str, t_stack *a, t_stack *b)
{
	free(str);
	ft_free_t_stack(a);
	ft_free_t_stack(b);
	return (0);
}
