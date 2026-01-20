/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/20 14:15:59 by vborysov         ###   ########.fr       */
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

// int main(void)
// {
// 	t_stack *stack_a = ft_new_stack();
// 	t_stack *stack_b = ft_new_stack();

// 	// fill stacks
// 	for (int i = 1; i <= 3; ++i)
// 	{
// 		ft_push_bottom(stack_a, ft_new_node(i));
// 		ft_push_bottom(stack_b, ft_new_node(i));
// 	}

// 	ft_putstr("Initial stacks:\n");
// 	show_stack(stack_a);
// 	show_stack(stack_b);
// 	ft_putstr("---------------------------\n");

// 	ft_putstr("Swap a:\n");
// 	ft_swap(stack_a);
// 	show_stack(stack_a);

// 	ft_putstr("Swap b:\n");
// 	ft_swap(stack_b);
// 	show_stack(stack_b);

// 	ft_putstr("Swap both (ss):\n");
// 	ft_s_swap(stack_a, stack_b);
// 	show_stack(stack_a);
// 	show_stack(stack_b);

// 	ft_putstr("Rotate a (ra):\n");
// 	ft_rotate(stack_a);
// 	show_stack(stack_a);

// 	ft_putstr("Rotate b (rb):\n");
// 	ft_rotate(stack_b);
// 	show_stack(stack_b);

// 	ft_putstr("Rotate both (rr):\n");
// 	ft_r_rotate(stack_a, stack_b);
// 	show_stack(stack_a);
// 	show_stack(stack_b);

// 	ft_putstr("Reverse rotate a (rra):\n");
// 	ft_rev_rotate(stack_a);
// 	show_stack(stack_a);

// 	ft_putstr("Reverse rotate b (rrb):\n");
// 	ft_rev_rotate(stack_b);
// 	show_stack(stack_b);

// 	ft_putstr("Reverse rotate both (rrr):\n");
// 	ft_r_rev_rotate(stack_a, stack_b);
// 	show_stack(stack_a);
// 	show_stack(stack_b);

// 	ft_putstr("Push from b to a (pa):\n");
// 	ft_push(stack_a, stack_b);
// 	show_stack(stack_a);
// 	show_stack(stack_b);

// 	ft_putstr("Push from a to b (pb):\n");
// 	ft_push(stack_b, stack_a);
// 	show_stack(stack_a);
// 	show_stack(stack_b);

// 	// free memory
// 	ft_destroy_stack(stack_a);
// 	ft_destroy_stack(stack_b);

// 	return 0;
// }


int	main(int ac, char	**av)
{
	
}
