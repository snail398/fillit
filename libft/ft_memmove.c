/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:36:53 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/05 19:36:55 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*temp_dst;
	const unsigned char		*temp_src;
	size_t					i;

	if (!dst && !src && len > 0)
		return (dst);
	i = -1;
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_src < temp_dst)
		while ((int)--len >= 0)
			*(temp_dst + len) = *(temp_src + len);
	else
		while (++i < len)
			*(temp_dst + i) = *(temp_src + i);
	return (dst);
}
