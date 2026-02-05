/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:25:11 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/10 20:37:51 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char delimeter)
{
	size_t	result;
	int		in_word;

	result = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != delimeter && in_word == 0)
		{
			result++;
			in_word = 1;
		}
		else if (*s == delimeter)
		{
			in_word = 0;
		}
		s++;
	}
	return (result);
}

static char	*ft_extract_word(const char *s, size_t start, char delim)
{
	size_t	end;

	end = start;
	while (s[end] && s[end] != delim)
		end++;
	return (ft_substr(s, start, end - start));
}

static void	ft_free_words(char **words, size_t count)
{
	while (count > 0)
		free(words[--count]);
	free(words);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	size_t	word_start;
	char	**result;

	if (!s)
		return (NULL);
	len = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	len = 0;
	word_start = 0;
	while (s[word_start])
	{
		if (s[word_start] == c)
		{
			word_start++;
			continue ;
		}
		result[len] = ft_extract_word(s, word_start, c);
		if (!result[len])
			return (ft_free_words(result, len), NULL);
		word_start += ft_strlen(result[len++]);
	}
	return (result[len] = NULL, result);
}
