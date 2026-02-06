/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:26:29 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/06 20:20:23 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_new_node(int data);
void	ft_destroy_node(t_stack	*node);
void	ft_destroy_stack(t_stack	**stack);

t_stack	*ft_push_top(t_stack	**stack, t_stack	*node);
t_stack	*ft_push_bottom(t_stack	**stack, t_stack	*node);
t_stack	*ft_pop_top(t_stack	**stack);
t_stack	*ft_pop_bottom(t_stack	**stack);

void	ft_swap_stack(t_stack	**stack, const char	*str);
void	ft_push(t_stack	**stack_a, t_stack **stack_b, const char	*str);
void	ft_rotate(t_stack	**stack, const char	*str);
void	ft_rev_rotate(t_stack	**stack, const char	*str);

#endif