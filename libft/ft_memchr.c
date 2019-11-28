/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:03:33 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/05 20:03:59 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n)
	{
		if (*temp == (unsigned char)c)
			break ;
		++temp;
		--n;
	}
	if (!n)
		return (NULL);
	return ((void*)temp);
}
