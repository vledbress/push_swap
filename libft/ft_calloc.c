/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:03:41 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/06 13:20:22 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t len, size_t element_size)
{
	void	*result;

	if (!len || !element_size)
		return (malloc(1));
	result = malloc(len * element_size);
	if (!result)
		return (NULL);
	ft_bzero(result, len * element_size);
	return (result);
}
