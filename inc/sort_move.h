/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:11:53 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/06 20:57:24 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_MOVE_H
# define SORT_MOVE_H

# include "stack.h"

void	ft_move_chunks_b(t_stack **a, t_stack **b);
void	ft_move_chunks_a(t_stack **a, t_stack **b);

#endif