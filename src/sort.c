/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:19:08 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/06 19:02:24 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include "sort_move.h"
#include "sort_small.h"

static int	ft_is_sorted(t_stack	*stack)
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

void	ft_sort(t_stack	*stack_a, t_stack	*stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 2 || ft_is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		return (ft_s(stack_a, "sa\n"), (void)0);
	if (stack_a->size == 3)
		return (ft_sort_3(stack_a), (void)0);
	if (stack_a->size < 6)
		return (ft_sort_5(stack_a, stack_b), (void)0);
	ft_move_chunks_b(stack_a, stack_b);
	ft_move_chunks_a(stack_a, stack_b);
}
