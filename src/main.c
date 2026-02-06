/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/06 15:27:55 by vborysov         ###   ########.fr       */
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
#include "error.h"
#include "parse.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		ft_error();
	int	len;
	long	*array;
	
	ft_parse_args(argc, argv, &array, &len);
	

	for (int i = 0; i < len; ++i)
		printf("%ld ", array[i]);
	
	free(array);
}