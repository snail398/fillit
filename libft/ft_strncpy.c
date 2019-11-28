/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:11:44 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/06 20:11:46 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*temp;

	temp = dst;
	while (*src && len)
	{
		*temp++ = *src++;
		--len;
	}
	while (len)
	{
		*temp++ = '\0';
		--len;
	}
	return (dst);
}
