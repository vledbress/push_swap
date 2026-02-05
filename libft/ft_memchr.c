/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:45:23 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/06 13:40:48 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*dummy;

	dummy = s;
	while (n--)
	{
		if (*dummy == (unsigned char)c)
			return ((void *)dummy);
		dummy++;
	}
	return (NULL);
}
