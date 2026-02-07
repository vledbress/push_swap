/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 01:31:10 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/07 01:47:28 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_init.h"
#include <stdlib.h>

static int	*ft_copy_arr(int	*arr, int len)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * len);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

void	ft_init_stack(t_stack	**stack, int	*raw, int len)
{
	int		*sorted;
	int		i;
	t_stack	*node;

	sorted = ft_copy_arr(raw, len);
	if (!sorted)
		return (free(raw), ft_error(), (void)0);
	ft_quick_sort(sorted, 0, len - 1);
	i = 0;
	while (i < len)
	{
		node = ft_new_node(ft_binary_search(sorted, len, raw[i]));
		if (!node)
			return (free(raw), free(sorted),
				ft_destroy_stack(stack), ft_error(), (void)0);
		ft_push_bottom(stack, node);
		++i;
	}
	free(sorted);
}
