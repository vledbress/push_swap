/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:07:52 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/10 20:16:58 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	index;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	len = ft_min(len, s_len - start);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	index = 0;
	while (index < len)
	{
		result[index] = s[start + index];
		index++;
	}
	result[index] = 0;
	return (result);
}
