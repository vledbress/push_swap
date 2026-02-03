/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:19:08 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 17:46:20 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_is_sorted(t_stack	*stack)
{
	t_node	*current;

	if (!stack || stack->size <= 1)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

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

int	ft_calculate_chunk(int total_size)
{
	return ((total_size <= 100) ? 15 : 32);
}

static int	ft_find_max(t_stack *stack)
{
	int		index;
	int		max_index;
	t_node	*current;
	int		max;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	max = current->data;
	max_index = 0;
	index = 0;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
			max_index = index;
		}
		current = current->next;
		index++;
	}
	return (max_index);
}

static void	ft_move_chunks_b(t_stack *a, t_stack *b)
{
	int	i;
	int	range;

	i = 0;
	range = ft_calculate_chunk(a->size);
	while (a->size > 0)
	{
		if (a->head->data <= i)
		{
			ft_p(a, b, "pb\n");
			ft_r(b, "rb\n");
			i++;
		}
		else if (a->head->data <= i + range)
		{
			ft_p(a, b, "pb\n");
			i++;
		}
		else
			ft_r(a, "ra\n");
	}
}

static void	ft_move_chunks_a(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (b->size)
	{
		max_pos = ft_find_max(b);
		if (max_pos <= b->size / 2)
			while (max_pos--)
				ft_r(b, "rb\n");
		else
			while (max_pos++ < b->size)
				ft_rr(b, "rrb\n");
		ft_p(b, a, "pa\n");
	}
}

void	ft_sort(t_stack	*stack_a, t_stack	*stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 2 || ft_is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		return (ft_swap_stack(stack_a), (void)0);
	if (stack_a->size == 3)
		return (ft_sort_3(stack_a), (void)0);
	if (stack_a->size < 6)
		return (ft_sort_5(stack_a, stack_b), (void)0);
	ft_move_chunks_b(stack_a, stack_b);
	ft_move_chunks_a(stack_a, stack_b);
}
