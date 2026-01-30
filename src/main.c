/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/30 01:44:23 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "stack.h"
#include "error.h"
#include "normalize.h"
#include "sort_utils.h"
#include <time.h>

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

// int	main(int ac, char	**av)
// {
// 	t_stack *stack_a;
// 	int *arr;

// 	ft_check_nums(ac, av);
// 	ft_check_dups(ac, av);
// 	stack_a = ft_new_stack();
// 	for (int i = 1; i < ac; i++)
// 		ft_push_bottom(stack_a, ft_new_node(ft_atol(av[i])));
	
// 	arr = ft_copy_arr(ac, av);
// 	ft_quick_sort(arr, 0, ac - 2);
// 	ft_normalize_stack(stack_a, arr);
// 	free(arr);

// 	show_stack(stack_a);

// 	ft_destroy_stack(stack_a);
// }
int main(void)
{
	int cases[6][3] = {
		{1, 2, 3},
		{2, 1, 3},
		{3, 2, 1},
		{3, 1, 2},
		{1, 3, 2},
		{2, 3, 1}
	};
	

	for (int i = 0; i < 6; i++)
	{
		t_stack *stack_a = ft_new_stack();
		for(int el = 0; el < 3; ++el)
		{
			ft_push_bottom(stack_a, ft_new_node(cases[i][el]));
		}

		write(1, "====================\n", 21);
		write(1, "before:\n", 8);
		show_stack(stack_a);

		ft_sort_3(stack_a);

		write(1, "after:\n", 7);
		show_stack(stack_a);

		write(1, "is_sorted = ", 12);
		if (ft_is_sorted(stack_a))
			write(1, "1\n", 2);
		else
			write(1, "0\n", 2);

		ft_destroy_stack(stack_a);
	}

	return (0);
}