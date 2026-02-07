/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 01:31:26 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/07 01:46:28 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_INIT_H
# define STACK_INIT_H
# include "stack.h"
# include "binary.h"
# include "error.h"

void	ft_init_stack(t_stack	**stack, int	*raw, int len);

#endif