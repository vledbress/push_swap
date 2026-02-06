/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:04:56 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/06 21:04:36 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_small.h"

void	ft_sort_3(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if (first > second && second < third && first < third)
		ft_swap_stack(stack, "sa");
	else if (first > second && second > third)
	{
		ft_swap_stack(stack, "sa");
		ft_rev_rotate(stack, "rra");
	}
	else if (first > second && second < third && first > third)
		ft_rotate(stack, "ra");
	else if (first < second && second > third && first < third)
	{
		ft_swap_stack(stack, "sa");
		ft_rotate(stack, "ra");
	}
	else if (first < second && second > third && first > third)
		ft_rev_rotate(stack, "rra");
}

static int	ft_find_min(t_stack	*stack)
{
	int		index;
	int		min_index;
	int		min;
	t_stack	*current;

	if (!stack)
		return (-1);
	current = stack;
	min = current->data;
	min_index = 0;
	index = 0;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

void	ft_sort_5(t_stack	**stack_a, t_stack	**stack_b)
{
	int	index;
	int	rotations;

	if (!stack_a || !stack_b)
		return ;
	while (ft_stack_size(*stack_a) > 3)
	{
		index = ft_find_min(*stack_a);
		if (index <= ft_stack_size(*stack_a) / 2)
		{
			while (index--)
				ft_rotate(stack_a, "ra");
		}
		else
		{
			rotations = ft_stack_size(*stack_a) - index;
			while (rotations--)
				ft_rev_rotate(stack_a, "rra");
		}
		ft_push(stack_b, stack_a, "pb");
	}
	ft_sort_3(stack_a);
	while (ft_stack_size(*stack_b) > 0)
		ft_push(stack_a, stack_b, "pa");
}
