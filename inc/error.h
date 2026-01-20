/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:47:56 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/20 17:42:03 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H
#include <stdlib.h>
#include "io.h"
#include "mini_libft.h"


void	ft_error(void);

void	ft_check_nums(int ac, char	**av);

void	ft_check_valid_number(char	*str);

void	ft_check_dups(int ac, char	**av);




#endif