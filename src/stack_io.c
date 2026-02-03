/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_io_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblxssv <vblxssv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:33:02 by vblxssv           #+#    #+#             */
/*   Updated: 2026/02/03 02:40:51 by vblxssv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "io.h"

void	ft_s(t_stack	*stack, const	char	*str)
{
    ft_swap_stack(stack);
    ft_putstr(1, str);
}

void	ft_p(t_stack	*source, t_stack *destination, const char	*str)
{
    ft_push(destination, source);
    ft_putstr(1, str);
}

void	ft_r(t_stack	*stack, const char	*str)
{
    ft_rotate(stack);
    ft_putstr(1, str);
}

void	ft_rr(t_stack	*stack, const char	*str)
{
    ft_rev_rotate(stack);
    ft_putstr(1, str);
}