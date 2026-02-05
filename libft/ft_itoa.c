/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:37:24 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/06 14:57:48 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int number)
{
	size_t	result;

	result = 0;
	if (number <= 0)
		result = 1;
	while (number)
	{
		result++;
		number /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			len;
	size_t			index;
	long long int	dummy;

	len = ft_numlen(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = 0;
	if (n == 0)
		return (result[0] = '0', result);
	dummy = n;
	if (dummy < 0)
		dummy = -dummy;
	index = len - 1;
	while (dummy)
	{
		result[index--] = (dummy % 10) + '0';
		dummy /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
