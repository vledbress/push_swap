/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:48:09 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/04 23:04:41 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void	ft_push_top(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->head;
	stack->head = node;
	stack->size++;
}

void	ft_push_bottom(t_stack *stack, t_node *node)
{
	t_node	*curr;

	if (!stack || !node)
		return ;
	node->next = NULL;
	if (!stack->head)
	{
		stack->head = node;
		stack->size++;
		return ;
	}
	curr = stack->head;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
	stack->size++;
}

t_node	*ft_pop_top(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->head)
		return (NULL);
	node = stack->head;
	stack->head = node->next;
	node->next = NULL;
	stack->size--;
	return (node);
}

t_node	*ft_pop_bottom(t_stack *stack)
{
	t_node	*curr;
	t_node	*prev;

	if (!stack || !stack->head)
		return (NULL);
	if (!stack->head->next)
	{
		curr = stack->head;
		stack->head = NULL;
		stack->size--;
		return (curr);
	}
	prev = NULL;
	curr = stack->head;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	stack->size--;
	return (curr);
}
