/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:42:16 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/20 14:06:45 by vborysov         ###   ########.fr       */
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
	first = ft_pop_top(stack);
	second = ft_pop_top(stack);
	ft_push_top(stack, first);
	ft_push_top(stack, second);       
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

// void ft_rotate(t_stack *stack)
// {
// 	t_node	*first;
 
// 	if (!stack || stack->size < 2)
// 		return ;
// 	first = ft_pop_top(stack);
// 	ft_push_bottom(stack, first);
// }

void ft_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	ft_push_bottom(stack, ft_pop_top(stack));
}

void	ft_r_rotate(t_stack	*stack_a, t_stack	*stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

