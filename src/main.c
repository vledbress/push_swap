/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:50:42 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/06 15:52:57 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "error.h"
#include "parse.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		exit(1);
	int	len;
	long	*array;
	
	ft_parse_args(argc, argv, &array, &len);
	
	free(array);
}