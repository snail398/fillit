/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:39:00 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/06 20:39:02 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*temp_dest;
	const char	*temp_src;
	size_t		n;
	size_t		dlen;

	temp_dest = dst;
	temp_src = src;
	n = size;
	while (*temp_dest && n--)
		temp_dest++;
	dlen = temp_dest - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(temp_src));
	while (*temp_src)
	{
		if (n != 1)
		{
			*temp_dest++ = *temp_src;
			--n;
		}
		++temp_src;
	}
	*temp_dest = '\0';
	return (dlen + (temp_src - src));
}
