/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:43:03 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/21 13:49:08 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*before_last;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		last = *stack_a;
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		before_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		last = *stack_b;
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		before_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
	write(1, "rrr\n", 4);
}

int	ft_rep_content(t_list *stack)
{
	t_list	*i;
	t_list	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if ((long)i->content == (long)j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

t_list	*ft_find_min(t_list *list)
{
	t_list	*min_node;
	long	min_val;

	if (!list)
		return (NULL);
	min_node = list;
	min_val = (long)list->content;
	while (list)
	{
		if ((long)list->content < min_val)
		{
			min_val = (long)list->content;
			min_node = list;
		}
		list = list->next;
	}
	return (min_node);
}

t_list	*ft_find_max(t_list *list)
{
	t_list	*max_node;
	long	max_val;

	if (!list)
		return (NULL);
	max_node = list;
	max_val = (long)list->content;
	while (list)
	{
		if ((long)list->content > max_val)
		{
			max_val = (long)list->content;
			max_node = list;
		}
		list = list->next;
	}
	return (max_node);
}

int	ft_get_pos(t_list *stack, t_list *node)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == node)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
