/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/07 00:07:21 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "error.h"
#include "parse.h"
#include <stdio.h>
#include "sort.h"
#include "binary.h"


int main(int argc, char **argv)
{
	if (argc == 1)
		exit(1);
	int	len;
	long	*array;
	int	*copy_sorted;
	
	ft_parse_args(argc, argv, &array, &len);
	copy_sorted = malloc(sizeof(int) * len);
	for(int i = 0; i < len; ++i)
		copy_sorted[i] = (int)array[i];
	ft_quick_sort(copy_sorted, 0, len - 1);
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	for(int i = 0; i < len; ++i)
		ft_push_bottom(&a, ft_new_node(ft_binary_search(copy_sorted, len, (int)array[i])));
	ft_sort(&a, &b);
	ft_destroy_stack(&a);
	ft_destroy_stack(&b);
	free(array);
	free(copy_sorted);
}
