/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:00:50 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/08 18:00:51 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	temp_len;

	if (*needle == '\0')
		return ((char *)haystack);
	temp_len = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= temp_len)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, temp_len) == 0)
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
