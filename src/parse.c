/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:14:49 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/05 17:47:39 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../libft/libft.h"

static int ft_is_number(const char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

static char	**ft_get_tokens(int argc, char **argv)
{
	char **tokens;

    if (argc == 2)
        tokens = ft_split(argv[1], ' ');
    else
        tokens = argv + 1;
	return (tokens);
}

static int	ft_count_tokens(char	**tokens)
{
	int	len;

	len = 0;
	while (tokens[len])
		len++;
	return (len);
}

void ft_parse_args(int argc, char **argv, long **raw, int *len)
{
    char	**tokens;
	int		i;

	tokens = ft_get_tokens(argc, argv);




	
    if (need_free)
        ft_free_split(tokens);
}

