/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:39:02 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 17:38:56 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normalize.h"

int	*ft_copy_arr(int ac, char	**av)
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

void	ft_normalize_stack(t_stack	*stack, int	*sorted_arr)
{
	t_node	*current;

	if (!stack || !sorted_arr)
		return ;
	current = stack->head;
	while (current)
	{
		current->data = ft_binary_search(sorted_arr,
				stack->size, current->data);
		current = current->next;
	}
}
