/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:24:21 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/10 19:16:46 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void	*s2, size_t n)
{
	unsigned char	*dummy1;
	unsigned char	*dummy2;
	size_t			index;

	dummy1 = (unsigned char *)s1;
	dummy2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (dummy1[index] != dummy2[index])
			return (dummy1[index] - dummy2[index]);
		index++;
	}
	return (0);
}
