/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/06 21:13:27 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "error.h"
#include "parse.h"
#include <stdio.h>
#include "sort.h"


int main(int argc, char **argv)
{
	if (argc == 1)
		exit(1);
	int	len;
	long	*array;

	ft_parse_args(argc, argv, &array, &len);
	
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	for(int i = 0; i < len; ++i)
		ft_push_bottom(&a, ft_new_node(array[i]));

	
	for (t_stack	*curr = a; curr; curr = curr->next)
		printf("%d ",curr->data);
	printf("\n");
	
	ft_sort(&a, &b);
	
	for (t_stack	*curr = a; curr; curr = curr->next)
		printf("%d ",curr->data);
	

	ft_destroy_stack(&a);
	ft_destroy_stack(&b);
	free(array);
}
