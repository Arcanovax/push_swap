/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:50:42 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/10 17:17:46 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tails;
	int				size;
}					t_stack;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

int		ft_swap_a(t_stack *a);
int		ft_swap_b(t_stack *b);
int		ft_swap_ab(t_stack *a, t_stack *b);
int		ft_push_a(t_stack *a, t_stack *b);
int		ft_push_b(t_stack *a, t_stack *b);
int		ft_rotate_a(t_stack *a);
int		ft_rotate_b(t_stack *b);
int		ft_rotate_ab(t_stack *a, t_stack *b);
int		ft_reverse_rotate_a(t_stack *a);
int		ft_reverse_rotate_b(t_stack *b);
int		ft_reverse_rotate_ab(t_stack *a, t_stack *b);
int		ft_randinx(t_stack *a, t_stack *b);
int		ft_free_all_on_error(char *str, t_stack *a, t_stack *b);
int		ft_free_exit(char *str, t_stack *a, t_stack *b);
int		ft_split_node(t_stack *stack, char const *s);
int		init_stack(t_stack **stack);
char	*ft_alloc_str(char *str);
char	*ft_cat_nb(char *base, char *cating);
#endif
