/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:40:14 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/20 20:18:06 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_target_pos_in_b(t_list *stack_b, int content_a)
{
	int		pos;
	int		target_pos;
	long	closest_smaller;
	t_list	*curr;

	pos = 0;
	target_pos = 0;
	closest_smaller = LONG_MIN;
	curr = stack_b;
	while (curr)
	{
		if ((long)curr->content < (long)content_a && (long)curr->content > closest_smaller)
		{
			closest_smaller = (long)curr->content;
			target_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	if (closest_smaller == LONG_MIN)
		return (ft_get_pos(stack_b, ft_find_max(stack_b)));
	return (target_pos);
}

static void	ft_apply_rotations(t_list **a, t_list **b, int pos_a, int pos_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
	{
		while (pos_a > 0 && pos_b > 0 && pos_a-- && pos_b--)
			rr(a, b);
		while (pos_a-- > 0)
			ra(a);
		while (pos_b-- > 0)
			rb(b);
	}
	else if (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		while (pos_a < size_a && pos_b < size_b && pos_a++ && pos_b++)
			rrr(a, b);
		while (pos_a++ < size_a)
			rra(a);
		while (pos_b++ < size_b)
			rrb(b);
	}
	else if (pos_a <= size_a / 2)
	{
		while (pos_a-- > 0)
			ra(a);
		while (pos_b++ < size_b)
			rrb(b);
	}
	else
	{
		while (pos_a++ < size_a)
			rra(a);
		while (pos_b-- > 0)
			rb(b);
	}
}

static long	ft_calculate_cost(int pos_a, int pos_b, int size_a, int size_b)
{
	long	cost_up;
	long	cost_down;
	long	cost_mixed1;
	long	cost_mixed2;
	long	min;

	cost_up = (pos_a > pos_b) ? pos_a : pos_b;
	cost_down = ((size_a - pos_a) > (size_b - pos_b)) ? (size_a - pos_a) : (size_b - pos_b);
	cost_mixed1 = pos_a + (size_b - pos_b);
	cost_mixed2 = (size_a - pos_a) + pos_b;
	min = cost_up;
	if (cost_down < min)
		min = cost_down;
	if (cost_mixed1 < min)
		min = cost_mixed1;
	if (cost_mixed2 < min)
		min = cost_mixed2;
	return (min);
}

void	ft_move_cheapest_to_b(t_list **a, t_list **b)
{
	t_list	*curr;
	int		pos_a;
	int		best_a;
	int		best_b;
	long	min_cost;
	long	cost;
	int		target_pos_b;

	curr = *a;
	pos_a = 0;
	min_cost = LONG_MAX;
	while (curr)
	{
		target_pos_b = ft_get_target_pos_in_b(*b, (long)curr->content);
		cost = ft_calculate_cost(pos_a, target_pos_b, ft_lstsize(*a), ft_lstsize(*b));
		if (cost < min_cost)
		{
			min_cost = cost;
			best_a = pos_a;
			best_b = target_pos_b;
		}
		curr = curr->next;
		pos_a++;
	}
	ft_apply_rotations(a, b, best_a, best_b);
	pb(b, a);
}
