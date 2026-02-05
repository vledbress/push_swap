/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:53:32 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/06 13:49:50 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char	*big, const char	*little, size_t len)
{
	size_t	index_big;
	size_t	index_little;

	if (!*little)
		return ((char *)big);
	index_big = 0;
	index_little = 0;
	while (index_big < len && big[index_big])
	{
		index_little = 0;
		while (index_big + index_little < len && big[index_big + index_little]
			&& (big[index_big + index_little] == little[index_little]))
			index_little++;
		if (little[index_little] == 0)
			return ((char *)(big + index_big));
		index_big++;
	}
	return (NULL);
}
