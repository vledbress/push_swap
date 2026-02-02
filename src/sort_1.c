/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:19:08 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/02 16:06:25 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"
#include <stdlib.h>
#include "io.h"
#include <stdio.h>

int ft_is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size <= 1)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_sort_3(t_stack	*stack)
{
	int first;
	int middle;
	int last;

	first = stack->head->data;
	middle = stack->head->next->data;
	last = stack->head->next->next->data;
	if (first > middle && middle < last && first < last)
	{
		ft_swap_stack(stack);
		ft_putstr(1, "sa\n");
	}
	else if (first > middle && middle > last)
	{
		ft_swap_stack(stack);
		ft_putstr(1, "sa\n");
		ft_rev_rotate(stack);
		ft_putstr(1, "rra\n");
		
	}
	else if (first > middle && middle < last && first > last)
	{
		ft_rotate(stack);
		ft_putstr(1, "ra\n");
	}
	else if (first < middle && middle > last && first < last)
	{
		ft_swap_stack(stack);
		ft_putstr(1, "sa\n");
		ft_rotate(stack);
		ft_putstr(1, "ra\n");
	}
	else if (first < middle && middle > last && first > last)
	{
		ft_rev_rotate(stack);
		ft_putstr(1, "rra\n");
	}
}

static int	ft_find_min(t_stack *stack)
{
	int		index;
	int		min_index;
	t_node	*current;
	int		min;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	min = current->data;
	min_index = 0;
	index = 0;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}
void	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	if (!stack_a || !stack_b)
		return ;
	
	// Убираем минимальные элементы, пока не останется 3
	while (stack_a->size > 3)
	{
		index = ft_find_min(stack_a);
		if (index <= stack_a->size / 2)
		{
			// Вращаем вверх
			while (index--)
			{
				ft_rotate(stack_a);
				ft_putstr(1, "ra\n");
			}
		}
		else
		{
			// Вращаем вниз
			int rotations = stack_a->size - index;
			while (rotations--)
			{
				ft_rev_rotate(stack_a);
				ft_putstr(1, "rra\n");
			}
		}
		// Отправляем минимальный элемент в стек B
		ft_push(stack_b, stack_a);
		ft_putstr(1, "pb\n");
	}

	// Сортируем оставшиеся 3 элемента в стеке A
	ft_sort_3(stack_a);

	// Возвращаем элементы из B в A
	while (stack_b->size)
	{
		ft_push(stack_a, stack_b);
		ft_putstr(1, "pa\n");
	}
}


int	ft_calculate_chunk(int	total_size)
{
	int	num_chunks;
	int	chunk_size;

	if (total_size <= 100)
		num_chunks = (total_size / 20) + 1;
	else
		num_chunks = 11;
	chunk_size = (total_size + num_chunks - 1) / num_chunks;
	return (chunk_size);
}

static int	has_in_chunk(t_stack *a, int start, int end)
{
	t_node	*cur = a->head;

	while (cur)
	{
		if (cur->data >= start && cur->data < end)
			return (1);
		cur = cur->next;
	}
	return (0);
}


// ----------------- поиск 

// static int	ft_find_max(t_stack *stack)
// {
// 	int		index;
// 	int		max_index;
// 	t_node	*current;
// 	int		max;

// 	if (!stack || !stack->head)
// 		return (-1);
// 	current = stack->head;
// 	max = current->data;
// 	max_index = 0;
// 	index = 0;
// 	while (current)
// 	{
// 		if (current->data > max)
// 		{
// 			max = current->data;
// 			max_index = index;
// 		}
// 		current = current->next;
// 		index++;
// 	}
// 	return (max_index);
// }


// static void ft_move_chunks_b(t_stack *a, t_stack *b)
// {
// 	int chunk_size = ft_calculate_chunk(a->size);
// 	int start = 0;
// 	int end, mid;

// 	while (a->size)
// 	{
// 		end = start + chunk_size;
// 		mid = start + chunk_size / 2;

// 		while (has_in_chunk(a, start, end))
// 		{
// 			if (a->head->data >= start && a->head->data < end)
// 			{
// 				ft_push(b, a); ft_putstr(1, "pb\n");
// 				if (b->head->data < mid) { ft_rotate(b); ft_putstr(1, "rb\n"); }
// 			}
// 			else
// 			{
// 				ft_rotate(a); ft_putstr(1, "ra\n");
// 			}
// 		}
// 		start += chunk_size;
// 	}
// }

static void ft_move_chunks_b(t_stack *a, t_stack *b)
{
    int remaining = a->size - 5;        // элементы, которые будем пушить в b
    int start = 0;
    int end, mid;
    int chunk_size;

    while (a->size > 5)
    {
        chunk_size = ft_calculate_chunk(remaining); // считаем чанки от оставшегося
        end = start + chunk_size;
        mid = start + chunk_size / 2;

        // пока есть элементы в текущем чанке и их > 5
        while (has_in_chunk(a, start, end) && a->size > 5)
        {
            if (a->head->data >= start && a->head->data < end)
            {
                ft_push(b, a); 
                ft_putstr(1, "pb\n");

                if (b->head->data < mid)
                {
                    ft_rotate(b); 
                    ft_putstr(1, "rb\n");
                }
            }
            else
            {
                ft_rotate(a); 
                ft_putstr(1, "ra\n");
            }
        }

        start += chunk_size;
        remaining = a->size - 5; // пересчитываем оставшиеся для следующего чанка
    }
    ft_sort_5(a, b);
}


// static void	ft_move_chunks_a(t_stack *a, t_stack *b)
// {
// 	int	max_pos;

// 	while (b->size)
// 	{
// 		max_pos = ft_find_max(b);
// 		if (max_pos <= b->size / 2)
// 			while (max_pos--)
// 			{
// 				ft_rotate(b);
// 				ft_putstr(1, "rb\n");
// 			}	
// 		else
// 			while (max_pos++ < b->size)
// 			{
// 				ft_putstr(1, "rrb\n");
// 				ft_rev_rotate(b);
// 			}
// 		ft_push(a, b);
// 		ft_putstr(1, "pa\n");
		
// 	}
// }


void	ft_sort(t_stack	*stack_a, t_stack	*stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 2 || ft_is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		return (ft_swap_stack(stack_a), (void)0);
	if (stack_a->size == 3)
		return (ft_sort_3(stack_a), (void)0);
	if (stack_a->size < 6)
		return (ft_sort_5(stack_a, stack_b), (void)0);
	ft_move_chunks_b(stack_a, stack_b);
	//ft_move_chunks_a(stack_a, stack_b);
}
