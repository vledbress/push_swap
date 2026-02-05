/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:39:54 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/10 20:16:15 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void	*dest, const void	*src, size_t n)
{
	unsigned char		*dummy_dest;
	const unsigned char	*dummy_src;

	if (n == 0 || dest == src)
		return (dest);
	dummy_dest = dest;
	dummy_src = src;
	while (n--)
		*dummy_dest++ = *dummy_src++;
	return (dest);
}
