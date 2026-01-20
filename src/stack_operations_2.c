/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:20:23 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/20 13:55:52 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

// void	ft_rev_rotate(t_stack	*stack)
// {
// 	t_node	*last;
// 	if (!stack || stack->size < 2)
// 		return ;
// 	last = ft_pop_bottom(stack);
// 	ft_push_top(stack, last);
// }

void	ft_rev_rotate(t_stack	*stack)
{
	if (!stack || stack->size < 2)
		return ;
	ft_push_top(stack, ft_pop_bottom(stack));
}

void	ft_r_rev_rotate(t_stack	*stack_a, t_stack	*stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
}