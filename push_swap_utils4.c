/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:07:38 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/20 21:41:15 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = ft_lstlast(*stack_a);
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	last = ft_lstlast(*stack_b);
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		*stack_a = first->next;
		last = ft_lstlast(*stack_a);
		last->next = first;
		first->next = NULL;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		*stack_b = first->next;
		last = ft_lstlast(*stack_b);
		last->next = first;
		first->next = NULL;
	}
	write(1, "rr\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}
