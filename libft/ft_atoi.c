/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:46:57 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/13 18:49:06 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char	*str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_issign(*str))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

// typedef struct s_testcase
// {
//     const char *input;
// } t_testcase;
// int main(void)
// {
//     t_testcase tests[] = {
//         {"123"},       // обычное число
//         {"-123"},      // отрицательное число
//         {"+123"},      // с плюсом
//         {"  42"},      // пробелы в начале
//         {"\t\n 56"},   // табы и переносы
//         {"0"},         // ноль
//         {"-0"},        // отрицательный ноль
//         {"2147483647"},    // INT_MAX
//         {"-2147483648"},   // INT_MIN
//         {"42abc"},     // число с текстом
//         {"abc42"},     // текст с числом
//         {"--42"},      // двойной минус
//         {"++42"},      // двойной плюс
//         {"-+42"},      // минус-плюс
//         {"-8z9"},      // твой пример
//         {""},          // пустая строка
//         {" "},         // пробел
//         {"\n"},        // перенос строки
//     };
//     size_t n_tests = sizeof(tests) / sizeof(tests[0]);
//     for (size_t i = 0; i < n_tests; i++)
//     {
//         int std_res = atoi(tests[i].input);
//         int ft_res = ft_atoi(tests[i].input);
//         if (std_res == ft_res)
//             printf("[OK] Input: \"%s\" -> %d\n", tests[i].input, ft_res);
//         else
//             printf("[FAIL] Input: \"%s\" -> atoi: %d, ft_atoi: %d\n", 
//                     tests[i].input, std_res, ft_res);
//     }
//     return 0;
// }
