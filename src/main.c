/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/20 13:44:56 by vborysov         ###   ########.fr       */
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
	ft_putstr(" ], size = ");
	ft_putnbr(stack->size);
	ft_putstr("\n");

}


int	main(void)
{
	t_stack	*stack_a = ft_new_stack();
	t_stack	*stack_b = ft_new_stack();
	
	for (int i = 1; i <= 5; ++i)
	{
		ft_push_bottom(stack_a, ft_new_node(i));
		ft_push_bottom(stack_b, ft_new_node(i));
	}
	show_stack(stack_a);
	show_stack(stack_b);

	ft_r_rev_rotate(stack_a, stack_a);

	show_stack(stack_a);
	show_stack(stack_b);
	
	ft_destroy_stack(stack_a);
	ft_destroy_stack(stack_b);
	
}

