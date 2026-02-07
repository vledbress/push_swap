/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:10:57 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/07 16:32:16 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_move.h"

static int	ft_calculate_chunk(int total_size)
{
	if (total_size <= 100)
		return (15);
	return (32);
}

// static int ft_calculate_chunk(int total_size)
// {
// 	int	K;

// 	if (total_size <= 100)
// 		K = 6;
// 	else
// 		K = 12;
// 	return (total_size / K + 1);
// }

// static int ft_calculate_chunk(int total_size)
// {
//     if (total_size <= 100)
//         return total_size / 6 + 1;
//     if (total_size <= 500)
//         return total_size / 11 + 1;
//     return total_size / 20 + 1;
// }

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

// void	ft_move_chunks_b(t_stack **a, t_stack **b)
// {
// 	int		i;
// 	int		range;
// 	int		pos;
// 	t_stack	*tmp;
// 	int		size;

// 	if (!a || !b)
// 		return ;

// 	i = 0;
// 	range = ft_calculate_chunk(ft_stack_size(*a));

// 	while (ft_stack_size(*a) > 0)
// 	{
// 		// ищем позицию ближайшего элемента в текущем чанке
// 		pos = 0;
// 		tmp = *a;
// 		size = ft_stack_size(*a);
// 		while (tmp && tmp->data > i + range)
// 		{
// 			tmp = tmp->next;
// 			pos++;
// 		}

// 		// умная ротация A
// 		if (pos <= size / 2)
// 		{
// 			while (pos--)
// 				ft_rotate(a, "ra");
// 		}
// 		else
// 		{
// 			pos = size - pos;
// 			while (pos--)
// 				ft_rev_rotate(a, "rra");
// 		}

// 		// теперь верхний элемент точно в текущем чанке
// 		if ((*a)->data <= i)
// 		{
// 			ft_push(b, a, "pb");
// 			ft_rotate(b, "rb");
// 			i++;
// 		}
// 		else if ((*a)->data <= i + range)
// 		{
// 			ft_push(b, a, "pb");
// 			i++;
// 		}
// 	}
// }
