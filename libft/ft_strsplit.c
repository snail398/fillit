/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:05:39 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/09 19:05:40 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			++count;
		while (s[i] && s[i] != c)
			++i;
		if (s[i] == '\0')
			break ;
		++i;
	}
	return (count);
}

static int	check_symbol(char s, char c, int *a, int b)
{
	if (s != c)
	{
		*a = b;
		return (1);
	}
	return (0);
}

static char	**clean_arr(char **res, int c)
{
	int		i;

	i = 0;
	while (i < c)
		free(res[i++]);
	free(res);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**res;
	int		arr_i;
	int		temp_start;
	int		flag;

	if (s == NULL || c == 0)
		return (NULL);
	i = 0;
	arr_i = 0;
	if (!(res = (char**)malloc(sizeof(char*) * (count_word(s, c) + 1))))
		return (NULL);
	while (arr_i < count_word(s, c))
	{
		flag = check_symbol(s[i], c, &temp_start, i) == 1 ? 1 : 0;
		while (s[i] && s[i] != c)
			++i;
		if (flag == 1)
			if (!(res[arr_i++] = ft_strsub(s, temp_start, i - temp_start)))
				return (clean_arr(res, arr_i - 1));
		++i;
	}
	res[arr_i] = NULL;
	return (res);
}
