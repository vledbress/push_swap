/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/12 18:51:09 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "stack.h"


void	show_stack(t_stack	*stack)
{
	t_node	*current;
	
	current = stack->head;
	ft_putstr("[ NULL <=> ");
	for (int i = 0; i < stack->size; ++i)
	{
		ft_putnbr(current->data);
		ft_putstr(" <=> ");
		current = current->next;
	}
	ft_putstr("NULL ]\n");
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
	
	ft_destroy_stack(stack_a);
}

