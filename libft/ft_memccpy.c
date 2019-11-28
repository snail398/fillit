/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:12:32 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/05 19:12:34 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst,
	const void *src, int c, size_t n)
{
	unsigned char			*temp_dst;
	const unsigned char		*temp_src;
	size_t					i;

	i = 0;
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		if (temp_src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
