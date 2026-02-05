/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:34:20 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/10 20:17:41 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char	*src, size_t dsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	remain_space;
	size_t	index;

	src_len = ft_strlen(src);
	if (!dst && dsize == 0)
		return (src_len);
	dst_len = 0;
	while (dst_len < dsize && dst[dst_len])
		dst_len++;
	if (dst_len == dsize)
		return (dst_len + src_len);
	remain_space = dsize - dst_len - 1;
	index = 0;
	while (index < remain_space && src[index])
	{
		dst[dst_len + index] = src[index];
		index++;
	}
	dst[dst_len + index] = 0;
	return (dst_len + src_len);
}
