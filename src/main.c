/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/19 01:19:41 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "stack.h"


void	show_stack(t_stack	*stack)
{
	t_node	*current;
	
	current = stack->head;
	ft_putstr("[ ");
	for (int i = 0; i < stack->size; ++i)
	{
		ft_putnbr(current->data);
		if (i != stack->size - 1)
			ft_putstr(" <=> ");
		current = current->next;
	}
	ft_putstr(" ]\n");
}


int	main(void)
{
	t_stack	*stack_a = ft_new_stack();
	
	ft_push_bottom(stack_a, ft_new_node(23));
	ft_push_bottom(stack_a, ft_new_node(-23));
	ft_push_bottom(stack_a, ft_new_node(0));
	ft_push_bottom(stack_a, ft_new_node(-89));
	ft_push_bottom(stack_a, ft_new_node(9));
	
	show_stack(stack_a);
	
	ft_swap(stack_a);

	show_stack(stack_a);
	
	ft_rotate(stack_a);
	
	show_stack(stack_a);
	
	ft_rotate(stack_a);
	
	show_stack(stack_a);
	
	ft_rotate(stack_a);
	
	show_stack(stack_a);
	
	ft_destroy_stack(stack_a);
}

