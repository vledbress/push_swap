/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/20 17:49:21 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "stack.h"
#include "error.h"


void	show_stack(t_stack	*stack)
{
	t_node	*current;
	
	current = stack->head;
	ft_putstr(1, "[ ");
	for (int i = 0; i < stack->size; ++i)
	{
		ft_putnbr(current->data);
		if (i != stack->size - 1)
			ft_putstr(1, " <=> ");
		current = current->next;
	}
	ft_putstr(1, " ], size = ");
	ft_putnbr(stack->size);
	ft_putstr(1, "\n");

}


int	main(int ac, char	**av)
{
	t_stack	*stack_a;
	
	if (ac == 1)
		return (-1);
	stack_a = ft_new_stack();
	ft_check_nums(ac, av);
	ft_check_dups(ac, av);
	
	
	for (int i = 1; i < ac; ++i)
	{
		ft_push_bottom(stack_a, ft_new_node(ft_atol(av[i])));
	}

	show_stack(stack_a);


	ft_destroy_stack(stack_a);
}
