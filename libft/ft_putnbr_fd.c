/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:05:30 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/06 15:09:42 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	dummy;

	dummy = (long long int)n;
	if (dummy < 0)
	{
		ft_putchar_fd('-', fd);
		dummy = -dummy;
	}
	if (dummy >= 10)
		ft_putnbr_fd(dummy / 10, fd);
	ft_putchar_fd((dummy % 10) + '0', fd);
}
