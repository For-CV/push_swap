/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:40:29 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/21 12:56:51 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

/* Commands */
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/* Initialization & Parsing */
t_list	*ft_load_stck_a(int *argc, char **argv);
int		ft_valid_args(int argc, char **argv);
int		ft_rep_content(t_list *stack);

/* Sorting Logic */
void	ft_sort_three(t_list **stack);
void	ft_push_swap(t_list **stack_a, t_list **stack_b);
void	ft_move_cheapest_to_b(t_list **a, t_list **b);
void	ft_move_cheapest_to_a(t_list **a, t_list **b);

/* Utils */
int		ft_is_sorted(t_list *stack);
t_list	*ft_find_min(t_list *list);
t_list	*ft_find_max(t_list *list);
int		ft_get_pos(t_list *stack, t_list *node);
int		ft_get_target_pos_in_b(t_list *stack_b, int content_a);
int		ft_get_target_pos_in_a(t_list *stack_a, int content_b);
void	ft_error_exit(t_list **a, t_list **b, char **argv_split);

#endif
