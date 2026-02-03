/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblxssv <vblxssv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:46:48 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/03 02:41:45 by vblxssv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
#define IO_H

#include <unistd.h>

void	ft_putchar(int fd, char c);
void	ft_putstr(int fd, const char *str);
void	ft_putnbr(int	num);


#endif