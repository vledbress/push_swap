/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:10:57 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/07 16:39:35 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_move.h"

static int	ft_calculate_chunk(int total_size)
{
	if (total_size <= 100)
		return (15);
	return (32);
}

void	ft_move_chunks_b(t_stack	**a, t_stack	**b)
{
	int	i;
	int	range;

	if (!a || !b)
		return ;
	i = 0;
	range = ft_calculate_chunk(ft_stack_size(*a));
	while (ft_stack_size(*a) > 0)
	{
		if ((*a)->data <= i)
		{
			ft_push(b, a, "pb");
			ft_rotate(b, "rb");
			i++;
		}
		else if ((*a)->data <= i + range)
		{
			ft_push(b, a, "pb");
			i++;
		}
		else
			ft_rotate(a, "ra");
	}
}
