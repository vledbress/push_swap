/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:33:24 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/06 13:49:26 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char	*src, size_t dsize)
{
	size_t	src_len;
	size_t	index;

	src_len = ft_strlen(src);
	if (!dsize)
		return (src_len);
	index = 0;
	while (index < dsize - 1 && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = 0;
	return (src_len);
}
