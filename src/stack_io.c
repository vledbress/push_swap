/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:33:02 by vblxssv           #+#    #+#             */
/*   Updated: 2026/02/06 15:30:35 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "../libft/libft.h"

void	ft_s(t_stack	*stack, const	char	*str)
{
	ft_swap_stack(stack);
	ft_putstr_fd(str, 1);
}

void	ft_p(t_stack	*source, t_stack *destination, const char	*str)
{
	ft_push(destination, source);
	ft_putstr_fd(str, 1);
}

void	ft_r(t_stack	*stack, const char	*str)
{
	ft_rotate(stack);
	ft_putstr_fd(str, 1);
}

void	ft_rr(t_stack	*stack, const char	*str)
{
	ft_rev_rotate(stack);
	ft_putstr_fd(str, 1);
}
