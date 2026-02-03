/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:16:51 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 19:18:12 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_move.h"

static int	ft_find_max(t_stack *stack)
{
	int		index;
	int		max_index;
	t_node	*current;
	int		max;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
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

void	ft_move_chunks_a(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (b->size)
	{
		max_pos = ft_find_max(b);
		if (max_pos <= b->size / 2)
			while (max_pos--)
				ft_r(b, "rb\n");
		else
			while (max_pos++ < b->size)
				ft_rr(b, "rrb\n");
		ft_p(b, a, "pa\n");
	}
}
