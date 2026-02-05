/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/05 01:23:43 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "io.h"
// #include "stack.h"
// #include "error.h"
// #include "sort.h"
// #include <time.h>
#include <stdio.h>
#include "atol.h"
#include <limits.h>

// int	main(int argc, char	**argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	if (argc == 1)
// 		exit(0);
// 	ft_check_nums(argc, argv);
// 	ft_check_dups(argc, argv);
// 	stack_a = ft_new_stack();
// 	if (!stack_a)
// 		ft_error();
// 	stack_b = ft_new_stack();
// 	if (!stack_b)
// 		return (ft_destroy_stack(stack_a), ft_error(), 1);
// 	if (!ft_init_stack(stack_a, argc, argv))
// 		return (ft_destroy_stack(stack_b), ft_error(), 1);
// 	ft_sort(stack_a, stack_b);
// 	ft_destroy_stack(stack_a);
// 	ft_destroy_stack(stack_b);
// }

#include "../libft/libft.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
		
	char **args = ft_split(argv[1], ' ');
	int len = 0;
	for (; args[len]; ++len);
		
	
	// === Check On normal nums (if contains only digits)===


	long *array_nums = (long *)malloc(sizeof(long) * len);
	for (int i = 0; i < len; ++i)
		array_nums[i] = ft_atol(args[i]);


	for (int i = 0; i < len; ++i)
	{
		if (array_nums[i] > INT_MAX || array_nums[i] < INT_MIN)
		{
			printf("Error\n");
			break ;
		}
	}
	
	for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (array_nums[i] == array_nums[j])
            {
                printf("Error\n");
				break ;
            }
        }
    }
		
		

	for (int i = 0; args[i]; ++i)
		free(args[i]);
	free(args);
	free(array_nums);
}