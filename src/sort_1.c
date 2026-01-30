/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:19:08 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/30 23:05:25 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"
#include <stdlib.h>
#include "io.h"
#include <stdio.h>

int ft_is_sorted(t_stack *stack)
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
	int first;
	int middle;
	int last;

	first = stack->head->data;
	middle = stack->head->next->data;
	last = stack->head->next->next->data;
	if (first > middle && middle < last && first < last)
		ft_swap_stack(stack);
	else if (first > middle && middle > last)
	{
		ft_swap_stack(stack);
		ft_rev_rotate(stack);
	}
	else if (first > middle && middle < last && first > last)
		ft_rotate(stack);
	else if (first < middle && middle > last && first < last)
	{
		ft_swap_stack(stack);
		ft_rotate(stack);
	}
	else if (first < middle && middle > last && first > last)
		ft_rev_rotate(stack);
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

void	ft_sort_5(t_stack	*stack_a, t_stack	*stack_b)
{
	int	index;

	if (!stack_a || !stack_b)
		return ;
	while (stack_a->size > 3)
	{	
		index = ft_find_min(stack_a);
		if (index <= stack_a->size / 2)
			while (index--)
				ft_rotate(stack_a);
		else
			while (index++ < stack_a->size)
				ft_rev_rotate(stack_a);
		ft_push(stack_b, stack_a);
	}
	ft_sort_3(stack_a);
	while (stack_b->size)
		ft_push(stack_a, stack_b);
}

int	ft_calculate_chunk(int	total_size)
{
	int	num_chunks;
	int	chunk_size;

	if (total_size <= 100)
		num_chunks = (total_size / 20) + 1;
	else
		num_chunks = 11;
	chunk_size = (total_size + num_chunks - 1) / num_chunks;
	return (chunk_size);
}

static void	ft_move_chunks_b(t_stack	*stack_a, t_stack	*stack_b)
{
	int	chunk_size;
	int	chunk_count;
	int	chunk_current;
	int	chunk_min;
	int	chunk_max;
	int	items_pushed;	
	int total_size = stack_a->size;
	
	chunk_size = ft_calculate_chunk(stack_a->size);
	chunk_count = (stack_a->size + chunk_size - 1) / chunk_size;	
	chunk_current = 0;
	while (chunk_current < chunk_count)
	{
		chunk_min = chunk_size * chunk_current;
		chunk_max = chunk_min + chunk_size;
		if (chunk_max > total_size)
    		chunk_max = total_size;
		items_pushed = 0;
		while (items_pushed < chunk_max - chunk_min)
		{
			if(stack_a->head->data >= chunk_min && stack_a->head->data < chunk_max)
			{
				ft_push(stack_b, stack_a);
				items_pushed++;
			}
			else
				ft_rotate(stack_a);
		}
		chunk_current++;
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
}
