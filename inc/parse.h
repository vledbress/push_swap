/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:12:47 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/05 17:26:00 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

#include "error.h"

void	ft_parse_args(int argc, char	**argv, long	*raw, int	*len);
void	ft_validate(long	*raw, int len);

#endif