/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:48:09 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 19:21:34 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void	ft_push_top(t_stack	*stack, t_node	*node)
{
	if (!stack || !node)
		return ;
	node->prev = NULL;
	node->next = stack->head;
	if (stack->head)
		stack->head->prev = node;
	else
		stack->tail = node;
	stack->head = node;
	stack->size++;
}

void	ft_push_bottom(t_stack	*stack, t_node	*node)
{
	if (!stack || !node)
		return ;
	node->prev = stack->tail;
	node->next = NULL;
	if (stack->tail)
		stack->tail->next = node;
	else
		stack->head = node;
	stack->tail = node;
	stack->size++;
}

t_node	*ft_pop_top(t_stack *stack)
{
	t_node	*head;

	if (!stack || !stack->head)
		return (NULL);
	head = stack->head;
	stack->head = head->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	head->next = NULL;
	head->prev = NULL;
	stack->size--;
	return (head);
}

t_node	*ft_pop_bottom(t_stack	*stack)
{
	t_node	*tail;

	if (!stack || !stack->tail)
		return (NULL);
	tail = stack->tail;
	stack->tail = tail->prev;
	if (stack->tail)
		stack->tail->next = NULL;
	else
		stack->head = NULL;
	tail->next = NULL;
	tail->prev = NULL;
	stack->size--;
	return (tail);
}
