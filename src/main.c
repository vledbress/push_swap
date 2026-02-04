/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/04 20:16:29 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "stack.h"
#include "error.h"
#include "normalize.h"
#include "sort.h"
#include <time.h>
#include <stdio.h>

// void	ft_show_stack(t_stack	*stack)
// {
// 	for (t_node	*i = stack->head; i; i = i->next)
// 		printf("%d ", i->data);
// 	printf("\n");
// }

// int	*gen_rand_arr(int	size)
// {
// 	int	*arr = (int	*)malloc(sizeof(int) * size);
// 	for (int i = 0; i < size; ++i)
// 	{
// 		arr[i] = i;
// 	}
// 	srand(time(NULL));
//     for (int i = size - 1; i > 0; --i)
//     {
//         int j = rand() % (i + 1);
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//     }

// 	return (arr);
// }
int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(0);
	ft_check_nums(argc, argv);
	ft_check_dups(argc, argv);
	stack_a = ft_new_stack();
	if (!stack_a)
		ft_error();
	stack_b = ft_new_stack();
	if (!stack_b)
		return (ft_destroy_stack(stack_a), ft_error(), 1);
	if (!ft_init_stack(stack_a, argc, argv))
		return (ft_destroy_stack(stack_b), ft_error(), 1);
	ft_sort(stack_a, stack_b);
	ft_destroy_stack(stack_a);
	ft_destroy_stack(stack_b);
}
