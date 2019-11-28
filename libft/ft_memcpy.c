/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:58:47 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/05 18:58:48 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*temp_dst;
	const char	*temp_src;

	temp_dst = dst;
	temp_src = src;
	if (!dst && !src && n != 0)
		return (dst);
	while (n--)
		*temp_dst++ = *temp_src++;
	return (dst);
}
