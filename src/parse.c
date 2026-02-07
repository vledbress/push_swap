/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:14:49 by vborysov          #+#    #+#             */
/*   Updated: 2026/02/07 01:56:15 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../libft/libft.h"
#include <limits.h>

static int	ft_is_number(const char *s)
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
	char	**tokens;

	if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	else
		tokens = argv + 1;
	return (tokens);
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

static int	ft_check_duplicates(int	*array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

void	ft_parse_args(int argc, char **argv, int **raw, int *len)
{
	char	**tokens;
	int		i;
	long	val;

	tokens = ft_get_tokens(argc, argv);
	*len = 0;
	while (tokens[*len])
		(*len)++;
	*raw = malloc(sizeof(int) * (*len));
	if (!*raw)
		return (ft_free_all(argc == 2, tokens), ft_error());
	i = 0;
	while (i < *len)
	{
		if (!ft_is_number(tokens[i]))
			return (free(*raw), ft_free_all(argc == 2, tokens), ft_error());
		val = ft_atol(tokens[i]);
		if (val > INT_MAX || val < INT_MIN)
			return (free(*raw), ft_free_all(argc == 2, tokens), ft_error());
		(*raw)[i] = (int)val;
		++i;
	}
	ft_free_all(argc == 2, tokens);
	if (!ft_check_duplicates(*raw, *len))
		return (free(*raw), ft_error());
}
