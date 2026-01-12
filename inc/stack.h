/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:26:29 by vborysov          #+#    #+#             */
/*   Updated: 2026/01/12 17:30:06 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct	s_node
{
	int	data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}				t_stack;







