/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:34:29 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/25 18:37:49 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMALIZE_H
#define NORMALIZE_H
#include <stdlib.h>
#include "binary.h"
#include "atol.h"
#include "stack.h"

int		*ft_copy_arr(int	ac, char	**av);
void	ft_normalize_stack(t_stack	*stack, int	*sorted_arr);

#endif