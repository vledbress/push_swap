/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:01:37 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 17:29:09 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOL_H
# define ATOL_H
# include <stdlib.h>

int		ft_is_digit(char c);
int		ft_is_sign(char c);	
int		ft_is_space(char c);
long	ft_atol(char	*str);

#endif