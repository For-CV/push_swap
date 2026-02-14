/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:39:27 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/21 14:32:12 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(t_list **a, t_list **b, char **argv_split)
{
	if (a && *a)
		ft_lstclear(a, NULL);
	if (b && *b)
		ft_lstclear(b, NULL);
	if (argv_split)
		ft_free_d(argv_split);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_is_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack && stack->next)
	{
		if ((long)stack->content > (long)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_valid_args(int argc, char **argv)
{
	int		i;
	int		j;
	long	val;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		val = ft_atol(argv[i]);
		if (val < INT_MIN || val > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

t_list	*ft_load_stck_a(int *argc, char **argv)
{
	t_list	*stack_a;
	char	**args;
	int		i;

	stack_a = NULL;
	if (*argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (!args || !*args)
		ft_error_exit(NULL, NULL, (char **)(*argc == 2 ? args : NULL));
	if (!ft_valid_args(ft_doubleptr_len(args), args))
		ft_error_exit(NULL, NULL, (char **)(*argc == 2 ? args : NULL));
	i = 0;
	while (args[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew((void *)(long)ft_atol(args[i])));
		i++;
	}
	if (*argc == 2)
		ft_free_d(args);
	if (ft_rep_content(stack_a))
		ft_error_exit(&stack_a, NULL, NULL);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = ft_load_stck_a(&argc, argv);
	if (ft_is_sorted(stack_a))
	{
		ft_lstclear(&stack_a, NULL);
		return (0);
	}
	stack_b = NULL;
	if (ft_lstsize(stack_a) == 2)
		sa(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		ft_sort_three(&stack_a);
	else
		ft_push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a, NULL);
	return (0);
}
