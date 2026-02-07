/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:16:51 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/07 20:17:54 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_move.h"

static int	ft_find_max(t_stack	*stack)
{
	int		index;
	int		max_index;
	int		max;
	t_stack	*current;

	if (!stack)
		return (-1);
	current = stack;
	max = current->data;
	max_index = 0;
	index = 0;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
			max_index = index;
		}
		current = current->next;
		index++;
	}
	return (max_index);
}

void	ft_move_chunks_a(t_stack	**a, t_stack	**b)
{
	int	max_pos;
	int	size;

	if (!a || !b)
		return ;
	size = ft_stack_size(*b);
	while (ft_stack_size(*b) > 0)
	{
		max_pos = ft_find_max(*b);
		size = ft_stack_size(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos--)
				ft_rotate(b, "rb");
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos--)
				ft_rev_rotate(b, "rrb");
		}
		ft_push(a, b, "pa");
	}
}
