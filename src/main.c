/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 19:31:35 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "stack.h"
#include "error.h"
#include "normalize.h"
#include "sort_utils.h"
#include <time.h>
#include <stdio.h>

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted_args;

	if (argc == 1)
		exit(-1);
	stack_a = ft_new_stack();
	stack_b = ft_new_stack();
	ft_check_nums(argc, argv);
	ft_check_dups(argc, argv);
	sorted_args = ft_copy_arr(argc, argv);
	ft_quick_sort(sorted_args, 0, argc - 2);
	ft_normalize_stack(stack_a, sorted_args);
	ft_sort(stack_a, stack_b);
	ft_destroy_stack(stack_a);
	ft_destroy_stack(stack_b);
	free(sorted_args);
}
