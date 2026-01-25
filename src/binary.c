/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:06:06 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/25 18:20:57 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary.h"
#include "swap.h"

static int		ft_partition(int	*arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[end];
	i = start;
	j = start;
	while (j < end)
	{
		if (arr[j] <= pivot)
		{
			ft_swap(&arr[i], &arr[j]);
			++i;
		}
		++j;
	}
	ft_swap(&arr[i], &arr[end]);
	return (i);
}

void	ft_quick_sort(int	*arr, int start, int end)
{
	int	pi;
	
	if (start < end)
	{
		pi = ft_partition(arr, start, end);
		ft_quick_sort(arr, start, pi - 1);
		ft_quick_sort(arr, pi + 1, end);
	}
}

int		ft_binary_search(int	*arr, int len, int element)
{
	int	start;
	int	end;
	int	middle;

	start = 0;
	end = len - 1;
	while (start <= end)
	{
		middle = start + (end - start) / 2;
		if (arr[middle] == element)
			return (middle);  
		else if (arr[middle] > element)
			end = middle - 1; 
		else
			start = middle + 1; 
	}
	return (-1);
}

