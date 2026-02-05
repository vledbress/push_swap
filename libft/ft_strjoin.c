/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:18:18 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/06 14:22:48 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s2) + ft_strlen(s1);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[0] = 0;
	ft_strlcat(result, s1, len + 1);
	ft_strlcat(result, s2, len + 1);
	return (result);
}
