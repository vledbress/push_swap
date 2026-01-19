/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:42:16 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/19 01:21:53 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void	ft_swap(t_stack	*stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;          
	second = stack->head->next;   
	first->next = second->next;   
	second->next = first;         
	stack->head = second;         
}

void	ft_s_swap(t_stack	*stack_a, t_stack	*stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_push(t_stack	*stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || !stack_b->size)
		return ;
	ft_push_top(stack_a, ft_pop_top(stack_b));
}
void ft_rotate(t_stack *stack)
{
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	stack->head = first->next;
	stack->head->prev = NULL;
	first->next = NULL;
	first->prev = stack->tail;
	stack->tail->next = first;
	stack->tail = first;
}

void	ft_r_rotate(t_stack	*stack_a, t_stack	*stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

