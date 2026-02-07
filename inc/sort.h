/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:19:30 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/07 02:22:07 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "stack.h"

int		ft_is_sorted(t_stack	*stack);
void	ft_sort(t_stack	**stack_a, t_stack	**stack_b);

#endif