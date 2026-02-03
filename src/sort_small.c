/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:04:56 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 19:08:36 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_small.h"

void	ft_sort_3(t_stack	*stack)
{
	int	first;
	int	middle;
	int	last;

	first = stack->head->data;
	middle = stack->head->next->data;
	last = stack->head->next->next->data;
	if (first > middle && middle < last && first < last)
		ft_s(stack, "sa\n");
	else if (first > middle && middle > last)
	{
		ft_s(stack, "sa\n");
		ft_rr(stack, "rra\n");
	}
	else if (first > middle && middle < last && first > last)
		ft_r(stack, "ra\n");
	else if (first < middle && middle > last && first < last)
	{
		ft_s(stack, "sa\n");
		ft_r(stack, "ra\n");
	}
	else if (first < middle && middle > last && first > last)
		ft_rr(stack, "rra\n");
}

static int	ft_find_min(t_stack *stack)
{
	int		index;
	int		min_index;
	t_node	*current;
	int		min;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
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

void	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	rotations;

	if (!stack_a || !stack_b)
		return ;
	while (stack_a->size > 3)
	{
		index = ft_find_min(stack_a);
		if (index <= stack_a->size / 2)
			while (index--)
				ft_r(stack_a, "ra\n");
		else
		{
			rotations = stack_a->size - index;
			while (rotations--)
				ft_rr(stack_a, "rra\n");
		}
		ft_p(stack_a, stack_b, "pb\n");
	}
	ft_sort_3(stack_a);
	while (stack_b->size)
		ft_p(stack_b, stack_a, "pa\n");
}
