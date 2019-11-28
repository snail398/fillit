/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:32:46 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/09 18:32:48 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_symbol(char c)
{
	if (c == '\n' || c == '\t' || c == '\r'
		|| c == ' ' || c == '\v' || c == '\f')
		return (0);
	return (1);
}

char		*ft_strtrim(char const *s)
{
	size_t	min;
	size_t	max;
	size_t	len;

	if (!s)
		return (NULL);
	min = 0;
	while (s[min] != '\0'
			&& !check_symbol(s[min]))
		min++;
	max = ft_strlen(s);
	while (min < max
			&& !check_symbol(s[max - 1]))
		max--;
	if (min == max)
		return (ft_strnew(1));
	len = max - min;
	return (ft_strsub(s, min, len));
}
