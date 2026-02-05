/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:14:49 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/05 19:17:29 by vborysov         ###   ########.fr       */
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
static void	ft_free_all(int need_free, char	**tokens)
{
	int	i;

	if (!need_free)
		return ;
	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}


void ft_parse_args(int argc, char **argv, long **raw, int *len)
{
    char	**tokens;
	int		i;

	tokens = ft_get_tokens(argc, argv);
	*len = ft_count_tokens(tokens);
	*raw = malloc(sizeof(long) * (*len));
	if (!*raw)
		return (ft_free_all(argc == 2, tokens), ft_error());
	i = 0;
	while (i < *len)
	{
		if (!ft_is_number(tokens[i]))
			return (free(*raw), ft_free_all(argc == 2, tokens), ft_error());
		++i;
	}
	i = 0;
	while (i < *len)
	{
		(*raw)[i] = ft_atol(tokens[i]);
		++i;
	}
    ft_free_all(argc == 2, tokens);
}

