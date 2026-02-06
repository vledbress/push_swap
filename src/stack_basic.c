/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:48:09 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/06 21:05:58 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack	*ft_push_top(t_stack	**stack, t_stack	*node)
{
	if (!stack || !node)
		return (NULL);
	node->next = *stack;
	*stack = node;
	return (node);
}

t_stack	*ft_push_bottom(t_stack	**stack, t_stack	*node)
{
	t_stack	*curr;

	if (!stack || !node)
		return (NULL);
	node->next = NULL;
	if (!*stack)
	{
		*stack = node;
		return (node);
	}
	curr = *stack;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
	return (node);
}

t_stack	*ft_pop_top(t_stack	**stack)
{
	t_stack	*node;

	if (!stack || !*stack)
		return (NULL);
	node = *stack;
	*stack = node->next;
	node->next = NULL;
	return (node);
}

t_stack	*ft_pop_bottom(t_stack	**stack)
{
	t_stack	*curr;
	t_stack	*prev;

	if (!stack || !*stack)
		return (NULL);
	curr = *stack;
	if (!curr->next)
	{
		*stack = NULL;
		return (curr);
	}
	prev = NULL;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev)
		prev->next = NULL;
	return (curr);
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		++size;
		stack = stack->next;
	}
	return (size);
}
