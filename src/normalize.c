/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:39:02 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/04 16:58:21 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normalize.h"

static int	*ft_copy_arr(int ac, char	**av)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * (ac - 1));
	if (!arr)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		arr[i - 1] = ft_atol(av[i]);
		i++;
	}
	return (arr);
}

void	ft_init_stack(t_stack	*stack, int argc, char	**argv)
{
	int	*values;
	int	*sorted;
	int	index;

	values = ft_copy_arr(argc, argv);
	if (!values)
		return ;
	sorted = ft_copy_arr(argc, argv);
	if (!sorted)
		return (free(values), (void)(0));
	ft_quick_sort(sorted, 0, argc - 2);
	index = 0;
	while (index < argc - 1)
	{
		ft_push_bottom(stack, ft_new_node(ft_binary_search(sorted,
					argc - 1, values[index])));
		index++;
	}
	free(values);
	free(sorted);
}
