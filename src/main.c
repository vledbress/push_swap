/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 18:08:44 by vborysov         ###   ########.fr       */
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
	int		index;

	if (argc == 1)
		exit(-1);
	stack_a = ft_new_stack();
	stack_b = ft_new_stack();
	ft_check_nums(argc, argv);
	ft_check_dups(argc, argv);
	index = 1;
	while (index < argc)
	{
		ft_push_bottom(stack_a, ft_new_node(ft_atol(argv[index])));
		index++;
	}
	ft_sort(stack_a, stack_b);
	ft_destroy_stack(stack_a);
	ft_destroy_stack(stack_b);
}
