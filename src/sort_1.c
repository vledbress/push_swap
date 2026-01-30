/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:19:08 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/30 01:38:38 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"
#include <stdlib.h>
// »»-----► Number of lines: 12
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
// »»-----► Number of lines: 23
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
// void	ft_sort_5(t_stack	*stack);