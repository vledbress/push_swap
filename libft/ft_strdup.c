/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:07:45 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/06 13:12:05 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	index;
	char	*result;

	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	index = 0;
	if (!result)
		return (NULL);
	while (index < len)
	{
		result[index] = s[index];
		index++;
	}
	result[len] = 0;
	return (result);
}
