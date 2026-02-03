/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:10:57 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 19:36:39 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_move.h"

static int	ft_calculate_chunk(int total_size)
{
	if (total_size <= 100)
		return (15);
	return (32);
}

void	ft_move_chunks_b(t_stack *a, t_stack *b)
{
	int	i;
	int	range;

	i = 0;
	range = ft_calculate_chunk(a->size);
	while (a->size)
	{
		if (a->head->data <= i)
		{
			ft_p(a, b, "pb\n");
			ft_r(b, "rb\n");
			i++;
		}
		else if (a->head->data <= i + range)
		{
			ft_p(a, b, "pb\n");
			i++;
		}
		else
			ft_r(a, "ra\n");
	}
}
