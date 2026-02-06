/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:42:16 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/06 20:36:50 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include "../libft/libft.h"

void	ft_swap_stack(t_stack	**stack, const char	*str)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = ft_pop_top(stack);
	second = ft_pop_top(stack);
	ft_push_top(stack, first);
	ft_push_top(stack, second);
	if (str)
		ft_putendl_fd(str, 1);
}

void	ft_push(t_stack	**stack_a, t_stack	**stack_b, const char	*str)
{
	t_stack	*node;

	if (!stack_a || !stack_b || !*stack_b)
		return ;
	node = ft_pop_top(stack_b);
	ft_push_top(stack_a, node);
	if (str)
		ft_putendl_fd(str, 1);
}

void	ft_rotate(t_stack	**stack, const char	*str)
{
	t_stack	*node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node = ft_pop_top(stack);
	ft_push_bottom(stack, node);
	if (str)
		ft_putendl_fd(str, 1);
}

void	ft_rev_rotate(t_stack	**stack, const char	*str)
{
	t_stack	*node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node = ft_pop_bottom(stack);
	ft_push_top(stack, node);
	if (str)
		ft_putendl_fd(str, 1);
}
