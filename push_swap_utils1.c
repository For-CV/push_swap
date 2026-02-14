/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:39:56 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/21 14:35:14 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **stack)
{
	t_list	*max_node;

	if (!stack || !*stack || ft_is_sorted(*stack))
		return ;
	max_node = ft_find_max(*stack);
	if (*stack == max_node)
		ra(stack);
	else if ((*stack)->next == max_node)
		rra(stack);
	if ((long)(*stack)->content > (long)(*stack)->next->content)
		sa(stack);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pos;

	size = ft_lstsize(*stack_a);
	if (size-- > 3)
		pb(stack_b, stack_a);
	if (size-- > 3)
		pb(stack_b, stack_a);
	while (size-- > 3)
		ft_move_cheapest_to_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (ft_lstsize(*stack_b) > 0)
		ft_move_cheapest_to_a(stack_a, stack_b);
	pos = ft_get_pos(*stack_a, ft_find_min(*stack_a));
	if (pos <= ft_lstsize(*stack_a) / 2)
		while (pos--)
			ra(stack_a);
	else
	{
		pos = ft_lstsize(*stack_a) - pos;
		while (pos--)
			rra(stack_a);
	}
}
