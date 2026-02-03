/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblxssv <vblxssv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:26:29 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 02:40:38 by vblxssv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

typedef	struct	s_node
{
	int	data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

t_node	*ft_new_node(int data);
void	ft_destroy_node(t_node	*node);

typedef struct	s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}				t_stack;

t_stack	*ft_new_stack(void);
void	ft_destroy_stack(t_stack	*stack);	

void	ft_push_top(t_stack	*stack, t_node	*node);
void	ft_push_bottom(t_stack	*stack, t_node	*node);
t_node	*ft_pop_top(t_stack	*stack);
t_node	*ft_pop_bottom(t_stack	*stack);

void	ft_swap_stack(t_stack	*stack);
void	ft_s_swap_stack(t_stack	*stack_a, t_stack	*stack_b);
void	ft_push(t_stack	*stack_a, t_stack *stack_b);
void	ft_rotate(t_stack	*stack);
void	ft_r_rotate(t_stack	*stack_a, t_stack	*stack_b);
void	ft_rev_rotate(t_stack	*stack);
void	ft_r_rev_rotate(t_stack	*stack_a, t_stack	*stack_b);


void	ft_s(t_stack	*stack, const char	*str);
void	ft_p(t_stack	*source, t_stack *destination, const char	*str);
void	ft_r(t_stack	*stack, const char	*str);
void	ft_rr(t_stack	*stack, const char	*str);

#endif 