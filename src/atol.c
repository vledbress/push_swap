/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:02:23 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/06 15:42:21 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atol.h"

static int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

static int	ft_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

long	ft_atol(char	*str)
{
	long	result;
	int		sign;

	if (!str)
		return (0);
	result = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	if (ft_is_sign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_is_digit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
