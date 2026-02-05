/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:40:19 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/06 13:50:16 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dummy_dest;
	const unsigned char	*dummy_src;

	dummy_dest = dest;
	dummy_src = src;
	if (dummy_dest > dummy_src)
	{
		dummy_dest += n - 1;
		dummy_src += n - 1;
		while (n--)
			*dummy_dest-- = *dummy_src--;
	}
	else if (dummy_dest < dummy_src)
	{
		while (n--)
			*dummy_dest++ = *dummy_src++;
	}
	return (dest);
}
