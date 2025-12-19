/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_common.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:58:55 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/19 14:26:49 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_COMMON_H
# define PUSH_SWAP_COMMON_H

# include <unistd.h>
# include <limits.h>

# include <stdlib.h>

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tails;
	int				size;
}	t_stack;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

int		ft_split_node(t_stack *stack, char const *s);

int		ft_swap(t_stack *stack);
int		ft_swap_swap(t_stack *a, t_stack *b);
int		ft_push(t_stack *stack_target, t_stack *stack_node);
int		ft_rotate(t_stack *stack);
int		ft_rotate_rotate(t_stack *a, t_stack *b);
int		ft_reverse_rotate(t_stack *stack);
int		ft_reverse_rotate_rotate(t_stack *a, t_stack *b);

int		init_stack(t_stack **stack);
char	*ft_alloc_str(char *str);
char	*ft_cat_nb(char *base, char *cating);
int		ft_strlen_secure(char *str);

int		ft_free_all_on_error(char *str, t_stack *a, t_stack *b);
int		ft_free_exit(char *str, t_stack *a, t_stack *b);
double	compute_disorder(t_stack *stack);

#endif