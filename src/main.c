/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/02 14:44:53 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "stack.h"
#include "error.h"
#include "normalize.h"
#include "sort_utils.h"
#include <time.h>
#include <stdio.h>

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
	ft_putstr(1, " ]\n");
}


int	*gen_rand_arr(int	len)
{
	int	*result = (int *)malloc(sizeof(int) * len);
	if (!result)
		return (NULL);
	for (int i = 0; i < len; ++i)
	{
		result[i] = i;
	}

	srand((unsigned int)time(NULL));
    for (int i = len - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        int temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }

	return (result);
}


int	ft_calculate_chunk(int	total_size);

int main(int argc, char **argv)
{
	if (argc == 1)
		exit(-1);

	int len = ft_atol(argv[1]);
	t_stack	*stack_a = ft_new_stack();
	t_stack	*stack_b = ft_new_stack();
	int	*arg = gen_rand_arr(len);
	
	for(int i = 0; i < len; ++i)
		ft_push_bottom(stack_a, ft_new_node(arg[i]));


	ft_sort(stack_a, stack_b);
	
	

	ft_destroy_stack(stack_a);
	ft_destroy_stack(stack_b);
	free(arg);
}