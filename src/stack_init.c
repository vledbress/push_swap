/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:21:01 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 19:22:08 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack	*ft_new_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->tail = NULL;
	new_stack->size = 0;
	return (new_stack);
}

void	ft_destroy_stack(t_stack	*stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->head)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		ft_destroy_node(tmp);
	}
	free(stack);
}
