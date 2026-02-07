/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/07 16:32:26 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "error.h"
#include "parse.h"
#include "sort.h"
#include "binary.h"
#include "stack_init.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len;
	int		*array;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	ft_parse_args(argc, argv, &array, &len);
	ft_init_stack(&a, array, len);
	ft_sort(&a, &b);
	ft_destroy_stack(&a);
	ft_destroy_stack(&b);
	free(array);
}
