/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:36:38 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/06 13:36:54 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last_seen;

	last_seen = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_seen = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (last_seen);
}
