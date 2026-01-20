/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:20:23 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/20 13:43:52 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void	ft_rev_rotate(t_stack	*stack)
{
	t_node	*last;
	if (!stack || stack->size < 2)
		return ;
	last = stack->tail;
	stack->tail = last->prev;
	stack->tail->next = NULL;
	last->prev = NULL;
	last->next = stack->head;
	stack->head->prev = last;
	stack->head = last;
}

void	ft_r_rev_rotate(t_stack	*stack_a, t_stack	*stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
}