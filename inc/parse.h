/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:12:47 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/06 15:31:41 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "error.h"
# include "atol.h"

void	ft_parse_args(int argc, char	**argv, long	**raw, int	*len);

#endif