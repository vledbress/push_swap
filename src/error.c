/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:51:12 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/20 17:45:38 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <limits.h>



void	ft_error(void)
{
	ft_putstr(2, "Error\n");
	exit(1);
}
void	ft_check_valid_number(char	*str)
{
	long	val;
	
	if (!str || !*str)
		ft_error();
	val = ft_atol(str);
	if (val < INT_MIN || val > INT_MAX)
		ft_error();
	if (ft_is_sign(*str))
		str++;
	if (!*str)
		ft_error();
	while (*str)
	{
		if (!ft_is_digit(*str))
			ft_error();
		str++;
	}
}

void ft_check_dups(int ac, char **av)
{
	int		i;
	int		j;
	long	val_i;
	long	val_j;
	
	i = 1;
	while (i < ac)
	{
		val_i = ft_atol(av[i]);
		j = i + 1;
		while (j < ac)
		{
			val_j = ft_atol(av[j]);
			if (val_i == val_j)
				ft_error();
			j++;
		}
		i++;
	}
    
}
void	ft_check_nums(int ac, char	**av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_check_valid_number(av[i]);
		i++;
	}
}
